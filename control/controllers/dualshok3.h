#ifndef DUALSHOK3_H
#define DUALSHOK3_H

#include <QObject>
#include "basicgamepad.h"

#define axis_range 32767
class DualShok3 : public BasicGamepad
{
    Q_OBJECT
public:
    DualShok3();
    int rotation;
    int linearSpeed;
    int turn;
    QString xmlcreator(QString type, int number, int value);

    void setTurn(int sturn);

    void setLinearSpeed(int slinearSpeed);

    void setRotation(int srotation);

signals:

public slots:
};

#endif // DUALSHOK3_H
