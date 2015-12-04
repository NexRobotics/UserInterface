#include "senderthread.h"
#include <qdebug.h>

SenderThread::SenderThread(QObject *parent) : QThread(parent)
{

}

void SenderThread::run(){
    qDebug()<<"hmm";
    while (1){

        emit signal_send_data(stream);
        msleep(100);
    }
}


void SenderThread::data_changed(QString data){
    this->stream = data;
}
