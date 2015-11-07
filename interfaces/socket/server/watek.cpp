#include "watek.h"
#include <QtCore>
//#include"server.h"

watek::watek (QObject *parent) : QThread(parent)
{
    stop = 0;

}
void watek::gogo(){
    this->start();
}

void watek::run(){
//    Server serwer;
//    serwer.Bind(8888);
    puts("hej");
//    socket_server server;
//    server.start_server();
}


