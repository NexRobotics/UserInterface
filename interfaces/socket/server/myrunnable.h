// myrunnable.h

#ifndef MYRUNNABLE_H
#define MYRUNNABLE_H

#include <QRunnable>
#include <QTcpSocket>
#include <QDebug>


class MyRunnable : public QRunnable
{
public:
    MyRunnable();

protected:
    void run();

public:
    qintptr socketDescriptor;

};

#endif // MYRUNNABLE_H
