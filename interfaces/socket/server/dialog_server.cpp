#include "dialog_server.h"
#include "ui_dialog_server.h"
#include "myserver.h"


Dialog_server::Dialog_server(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
//    thread = new watek(this);
//    connect(this,SIGNAL(sostart()),thread,SLOT(gogo()));
}

Dialog_server::~Dialog_server()
{
    delete ui;
}

void Dialog_server::on_pushButton_clicked()
{

//    serverstartServer();

//    emit sostart();
//    thread->start();
//    MyServer server;
//    server.startServer();
}
