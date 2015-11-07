#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>
#include <QTcpSocket>
#include <QDebug>

class MyThread : public QThread
{
    Q_OBJECT
public:
    explicit MyThread(qintptr ID, QObject *parent = 0);
    void send_data(QString data);

    void run();

signals:
    void error(QTcpSocket::SocketError socketerror);
    void signal_client_disconnected();
    void signal_client_connected();
    void signal_got_data(QString data);

public slots:
    void slot_read_data();
    void slot_disconnected();

private:
    QTcpSocket *socket;
    qintptr socketDescriptor;
};

#endif // MYTHREAD_H
