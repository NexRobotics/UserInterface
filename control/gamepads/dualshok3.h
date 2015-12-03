#ifndef DUALSHOK3_H
#define DUALSHOK3_H

#include <QObject>
#include "../basecontroller.h"

#define axis_rotation_number    0
#define axis_liear_number       13
#define direction_button_number    13
#define range                   32767

class DualShok3 : public BaseController
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
