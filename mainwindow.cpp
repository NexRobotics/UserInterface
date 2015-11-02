#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_inter_combo_currentTextChanged(const QString &arg1)
{

    if (arg1=="--Choose one--"){
        ui->interface_status_label->setText("Unavalible");
    } else if (arg1=="Wifi(server)"){
        ui->interface_status_label->setText("Trying to Connect");
    }
}

void MainWindow::on_controll_combo_currentTextChanged(const QString &arg1)
{
    if (arg1=="--Choose one--"){
        ui->controll_status_label->setText("Unavalible");
    } else if (arg1=="Keyboard"){
        ui->controll_status_label->setText("Connection Success");
    }

}
