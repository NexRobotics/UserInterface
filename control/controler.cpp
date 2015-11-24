#include "controler.h"

Controler::Controler(QObject *parent) : QObject(parent)
{

    connect(&gamepad, &Gamepad::signal_controller_connection_closed, this, &Controler::slot_controller_connection_closed);
    connect(&gamepad, &Gamepad::signal_controller_value_changed, this, &Controler::slot_controller_value_changed);
    connect(&gamepad, &Gamepad::signal_got_Gamepad_info, this, &Controler::slot_got_Gamepad_info);
}


void Controler::slot_controller_value_changed(QString type, int number, int value){
    emit signal_controller_value_changed(type, number, value);
}
void Controler::slot_controller_connection_closed(){
    emit signal_controller_connection_closed();
}
void Controler::slot_destroy_pad(){
    emit sinal_destroy_pad();
}
void Controler::slot_got_Gamepad_info(QStringList info){}
