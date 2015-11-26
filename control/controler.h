#ifndef CONTROLER_H
#define CONTROLER_H

#include <QObject>
#include "gamepad.h"
#include "gamepads/basicgamepad.h"
//#include "cjoystick.h"

class Controler : public QObject
{
    Q_OBJECT
public:
    explicit Controler(QString typ, QObject *parent = 0);
    Gamepad *pad_reader;
    BasicGamepad *gamepad;
private:
    QStringList Controlerinfo;
signals:
    void signal_controller_value_changed(QString xml);
    void signal_controller_connection_closed();
    void sinal_destroy_pad();
    void signal_got_Gamepad_info(QStringList info);
public slots:
    void slot_controller_value_changed(QString type, int number, int value);
    void slot_controller_connection_closed();
    void slot_destroy_pad();
    void slot_got_Gamepad_info(QStringList info);
};

#endif // CONTROLER_H
