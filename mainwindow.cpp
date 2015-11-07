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
void MainWindow::ultrasound_detector_receiver(const QStringList &data){

    qDebug() << " Data in: " << data;

//    QTableWidgetItem *set1 = new QTableWidgetItem;
//    QTableWidgetItem *set2 = new QTableWidgetItem;

//    set1->setText(data[1]);
//    set2->setText(data[2]);
//    ui->param_table->setItem(0,0,set1);
//    ui->param_table->setItem(0,1,set2);

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
