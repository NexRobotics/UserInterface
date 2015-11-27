#ifndef BASECONTROLLER_H
#define BASECONTROLLER_H

#include <QObject>

class BaseController : public QObject
{
    Q_OBJECT
public:
    explicit BaseController(QObject *parent = 0);
    virtual QString xmlcreator(QString type, int number, int value);
signals:

public slots:
};



#endif // BASECONTROLLER_H
