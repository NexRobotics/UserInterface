#include "controler.h"
#include <QDebug>

Controler::Controler(QObject *parent) : QObject(parent)
{
    gamepad = new Gamepad();
    gamepad->start();

    connect(gamepad, &Gamepad::signal_controller_connection_closed, this, &Controler::slot_controller_connection_closed);
    connect(gamepad, &Gamepad::signal_controller_value_changed, this, &Controler::slot_controller_value_changed);
    connect(gamepad, &Gamepad::signal_got_gamepad_info, this, &Controler::slot_got_Gamepad_info);
}

void Controler::slot_got_Gamepad_info(QStringList info){
    emit signal_got_Gamepad_info(info);
}

void Controler::slot_controller_value_changed(QString type, int number, int value){
//    qDebug() << type;
    emit signal_controller_value_changed(type, number, value);
}
void Controler::slot_controller_connection_closed(){
    emit signal_controller_connection_closed();
}
void Controler::slot_destroy_pad(){
    emit sinal_destroy_pad();
}
