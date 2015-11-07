#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "interfaces/socket/server/dialog_server.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->controll_combo->setEnabled(false);
    connection = false;

    connect(&Mserver, SIGNAL(signal_connection_signal()), this, SLOT(slot_set_connected()));
    connect(&Mserver, SIGNAL(signal_disconnection_signal()), this, SLOT(slot_set_disconnected()));
    connect(this, SIGNAL(signal_send_from_main(const QString&)), &Mserver, SLOT(slot_send_data(const QString&)));
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
