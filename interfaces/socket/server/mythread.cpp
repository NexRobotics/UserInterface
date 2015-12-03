#include "mythread.h"

MyThread::MyThread(qintptr ID, QObject *parent) :
    QThread(parent)
{
    this->socketDescriptor = ID;
}

void MyThread::run()
{
    // thread starts here
    qDebug() << " Thread started";

    socket = new QTcpSocket();

    // set the ID
    if(!socket->setSocketDescriptor(this->socketDescriptor))
    {
        // something's wrong, we just emit a signal
        emit error(socket->error());
        return;
    }

    // connect socket and signal
    // note - Qt::DirectConnection is used because it's multithreaded
    //        This makes the slot to be invoked immediately, when the signal is emitted.

    connect(socket, &QIODevice::readyRead, this, &MyThread::slot_read_data, Qt::DirectConnection);
    connect(socket, &QAbstractSocket::disconnected, this, &MyThread::slot_disconnected);

    // We'll have multiple clients, we want to know which is which
    qDebug() << socketDescriptor << " Client connected";
    emit signal_client_connected();




    // make this thread a loop,
    // thread will stay alive so that signal/slot to function properly
    // not dropped out in the middle when thread dies

    exec();


}

void MyThread::slot_read_data()
{
    // get the information
    QByteArray Data = socket->readAll();

    // will write on server side window
//    qDebug() << socketDescriptor << " Data in: " << Data;
    emit signal_got_data(Data);


//    socket->write(Data);
}


void MyThread::send_data(QString data)
{
    if (data=="W")
        socket->write("UP;1;\n");
    else if (data=="S")
        socket->write("DOWN;1;\n");
    else if (data=="A")
        socket->write("LEFT;1;\n");
    else if (data=="D")
        socket->write("RIGHT;1;\n");
    else {
        socket->write(data.toStdString().c_str());
    }
    qDebug()<<data;
}



void MyThread::slot_disconnected()
{
    qDebug() << socketDescriptor << " Disconnected";
    emit signal_client_disconnected();


    socket->deleteLater();
    exit(0);
}
