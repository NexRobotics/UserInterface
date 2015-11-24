#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->controll_combo->setEnabled(false);
    connection = false;

    connect(&Mserver, &MyServer::signal_connection_signal, this, &MainWindow::slot_set_connected);
    connect(&Mserver, &MyServer::signal_disconnection_signal, this, &MainWindow::slot_set_disconnected);
    connect(this, &MainWindow::signal_send_from_main, &Mserver, &MyServer::slot_send_data);
    connect(&Mserver, &MyServer::signal_got_data, this, &MainWindow::slot_got_data);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_inter_combo_currentTextChanged(const QString &arg1)
{

    if (arg1=="--Choose one--"){
        ui->interface_status_label->setText("Unavalible");
        ui->controll_combo->setEnabled(false);
    } else if (arg1=="Wifi(server)"){

        ui->controll_combo->setEnabled(true);
        ui->interface_status_label->setText("<font color='Blue'>Trying to connect</font>");
        Mserver.startServer();

//        Dialog_server server;
//        server.exec();
    }
}

void MainWindow::on_controll_combo_currentTextChanged(const QString &arg1)
{
    if (arg1=="--Choose one--"){
        ui->controll_status_label->setText("Unavalible");
    } else if (arg1=="Keyboard"){
        ui->controll_status_label->setText("<font color='Green'>Connected</font>");
    } else if (arg1=="Gamepad"){

        Gamepad *js;
        js = new Gamepad();
//        Controler controler;
//        connect(&controler, &Controler::signal_controller_connection_closed, this, &MainWindow::slot_controller_connection_closed);
//        connect(&controler, &Controler::signal_controller_value_changed, this, &MainWindow::slot_controller_value_changed);
//        connect(&controler, &Controler::signal_got_Gamepad_info, this, &MainWindow::slot_got_Gamepad_info);

//        if (js->active==true)
//       {
           QString info = QString("Name : %1\nVersion: %2\nAxes: %3\nButtons: %4")
                .arg(js->name,QString::number(js->version),QString::number(js->axes),QString::number(js->buttons));
        ui->contr_info->setText(info);
//        js->start();
        ui->controll_status_label->setText("<font color='Green'>Connected</font>");
//        }
//        else{
//            ui->controll_status_label->setText("<font color='red'>Connection problem</font>");
//        }
    }

}

void MainWindow::keyPressEvent(QKeyEvent* e)
{
//    qDebug() << ui->controll_combo->currentText();
    if ((connection == true)&(ui->controll_combo->currentText()=="Keyboard")){
            qDebug() << e->text();
      emit signal_send_from_main(e->text().toUpper());
    }
}

void MainWindow::slot_set_connected(){
    connection = true;
    ui->interface_status_label->setText("<font color='Green'>Connected</font>");

}
void MainWindow::slot_set_disconnected(){
    connection = false;
    ui->interface_status_label->setText("<font color='Red'>Disconnected</font>");
}

void MainWindow::slot_got_data(const QString &data){

    qDebug() << " Data in: " << data;
    newdata = data.split(";");
    QString text = newdata[0];

    if((text.contains("#Ultrasound"))&(newdata.length()>2)){
        this->ultrasound_detector_receiver(newdata);
    }

}

//#Ultrasound1;1234;123;
//#Ultrasound2;123we4;123;
//#Ultrasound4;1234;12dsad3;
//#Ultrasound5;12aa34;123;
void MainWindow::ultrasound_detector_receiver(const QStringList &data){

    qDebug() << " Data in: " << data;

    if(data[0]=="#Ultrasound1"){
        this->set_param_tabor(0,data[1],data[2]);
    } else if(data[0]=="#Ultrasound2"){
        this->set_param_tabor(1,data[1],data[2]);
    } else if(data[0]=="#Ultrasound3"){
        this->set_param_tabor(2,data[1],data[2]);
    } else if(data[0]=="#Ultrasound4"){
        this->set_param_tabor(3,data[1],data[2]);
    } else if(data[0]=="#Ultrasound5"){
        this->set_param_tabor(4,data[1],data[2]);
    } else if(data[0]=="#Ultrasound6"){
        this->set_param_tabor(5,data[1],data[2]);
    } else if(data[0]=="#Ultrasound7"){
        this->set_param_tabor(6,data[1],data[2]);
    }
}

void MainWindow::set_param_tabor(int row, const QString &time, const QString &val){

    QTableWidgetItem *set1 = new QTableWidgetItem;
    QTableWidgetItem *set2 = new QTableWidgetItem;

    set1->setText(time);
    set2->setText(val);
    ui->param_table->setItem(row,0,set1);
    ui->param_table->setItem(row,1,set2);

}



void MainWindow::slot_controller_value_changed(QString type, int number, int value){}
void MainWindow::slot_controller_connection_closed(){}
void MainWindow::slot_got_Gamepad_info(QStringList info){}
