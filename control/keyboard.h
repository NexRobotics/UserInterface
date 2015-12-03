#ifndef KEYBOARD_H
#define KEYBOARD_H
#include "basecontroller.h"
#include "basecontroller.h"

#define lin_speed   1000
#define rot         1000
#define range       32767

class Keyboard : public BaseController
{
public:
    Keyboard();
    int rotation;
    int linearSpeed;
    int turn;
    QString xmlcreator(QString type, int number, int value);

    void setTurn(int sturn);

    void setLinearSpeed(int slinearSpeed);

    void setRotation(int srotation);
};

#endif // KEYBOARD_H
