#include "mainwindow.h"
#include <QApplication>
//#include "interfaces/socket/server/server.h"
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}



