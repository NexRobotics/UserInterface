// myserver.cpp

#include "myserver.h"
#include "mythread.h"

MyServer::MyServer(QObject *parent) :
    QTcpServer(parent)
{
}

void MyServer::startServer()
{
    connected = false;
    sender = new SenderThread();
    int port = 9000;

    if(!this->listen(QHostAddress::Any, port))
    {
        qDebug() << "Could not start server";
    }
    else
    {
        qDebug() << "Listening to port " << port << "...";
    }
}

// This function is called by QTcpServer when a new connection is available.
void MyServer::incomingConnection(qintptr socketDescriptor)
{
    // We have a new connection
    qDebug() << socketDescriptor << " Connecting...";

    // Every new connection will be run in a newly created thread
    ServerThread = new MyThread(socketDescriptor, this);

    connect(ServerThread, &MyThread::signal_client_connected, this, &MyServer::slot_cli_set_connected);
    connect(ServerThread, &MyThread::signal_client_disconnected, this, &MyServer::slot_cli_set_disconnected);
    connect(ServerThread, &MyThread::signal_got_data, this, &MyServer::slot_got_data);
    connect(sender, &SenderThread::signal_send_data, ServerThread, &MyThread::slot_send_data);

    // connect signal/slot
    // once a thread is not needed, it will be beleted later
    connect(ServerThread, SIGNAL(finished()), ServerThread, SLOT(deleteLater()));

//    connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));

    ServerThread->start();
}

void MyServer::slot_set_data(const QString &data)
{

    sender->data_changed(data);
//    if (connected==true){
//        ServerThread->send_data(data);
//    }
}

void MyServer::slot_cli_set_connected(){
    sender->data_changed("");
    connected = true;
    sender->start();
    emit signal_connection_signal();
}

void MyServer::slot_cli_set_disconnected(){
    connected = false;
    sender->terminate();
    emit signal_disconnection_signal();
}

void MyServer::slot_got_data(const QString &data){
    emit signal_got_data(data);

}
