#ifndef CONTROLER_H
#define CONTROLER_H

#include <QObject>
#include "gamepads/padreader.h"
#include "basecontroller.h"
//#include "cjoystick.h"

class Controler : public QObject
{
    Q_OBJECT
public:
    explicit Controler(QObject *parent = 0);
    Padreader *pad_reader;
    BaseController *actual_controller;
    void set_type(QString typ);
private:
    QStringList Controlerinfo;
signals:
    void signal_up_controller_value_changed(QString xml);
    void signal_controller_connection_closed();
    void sinal_destroy_pad();
    void signal_up_got_Gamepad_info(QStringList info);
public slots:    
    void slot_keyboard_value_changed(QString type);
    void slot_controller_value_changed(QString type, int number, int value);
    void slot_controller_connection_closed();
    void slot_destroy_pad();
    void slot_got_Gamepad_info(QStringList info);
};

#endif // CONTROLER_H
