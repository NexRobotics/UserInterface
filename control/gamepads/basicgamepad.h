#ifndef BASICGAMEPAD_H
#define BASICGAMEPAD_H

#include <QObject>

class BasicGamepad : public QObject
{
    Q_OBJECT
public:
    explicit BasicGamepad(QObject *parent = 0);
    virtual QString xmlcreator(QString type, int number, int value);
signals:

public slots:
};

#endif // BASICGAMEPAD_H
