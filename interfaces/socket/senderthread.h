#ifndef SENDERTHREAD_H
#define SENDERTHREAD_H


#include <QThread>
class SenderThread : public QThread
{
    Q_OBJECT
public:
    explicit SenderThread(QObject *parent = 0);
    void run();
    QString stream;
signals:
    void signal_send_data(QString data);
public:
    void data_changed(QString data);
};

#endif // SENDERTHREAD_H
