// myserver.h

#ifndef MYSERVER_H
#define MYSERVER_H

#include <QTcpServer>
#include "mythread.h"

class MyServer : public QTcpServer
{
    Q_OBJECT
public:
    explicit MyServer(QObject *parent = 0);
    void startServer();
    MyThread *ServerThread;

signals:
    void signal_connection_signal();
    void signal_disconnection_signal();

public slots:
    void slot_cli_set_disconnected();
    void slot_cli_set_connected();
    void slot_send_data(const QString &);

protected:
    void incomingConnection(qintptr socketDescriptor);

};

#endif // MYSERVER_H