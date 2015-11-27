#include "controler.h"
#include <QDebug>
#include "gamepads/dualshok3.h"

Controler::Controler(QString typ, QObject *parent) : QObject(parent)
{
    if (typ == "Keyboard")
    {

    }
    else if (typ == "Gamepad")
    {

    pad_reader = new Padreader();
    if(pad_reader->active==true)
        pad_reader->start();
    connect(pad_reader, &Padreader::signal_controller_connection_closed, this, &Controler::slot_controller_connection_closed);
    connect(pad_reader, &Padreader::signal_controller_value_changed, this, &Controler::slot_controller_value_changed);
    connect(pad_reader, &Padreader::signal_got_gamepad_info, this, &Controler::slot_got_Gamepad_info);
    }
}

void Controler::slot_got_Gamepad_info(QStringList info){
    Controlerinfo = info;
    if(Controlerinfo[0]=="Sony PLAYSTATION(R)3 Controller"){
        gamepad = new DualShok3();
    }
    emit signal_got_Gamepad_info(info);
}

void Controler::slot_controller_value_changed(QString type, int number, int value){
    if(!(Controlerinfo.isEmpty())){
        if(Controlerinfo[0]=="Sony PLAYSTATION(R)3 Controller"){
            QString lo = gamepad->xmlcreator(type, number, value);
            qDebug ()<<lo;
            if (lo == "not important"){
            } else {
                emit signal_controller_value_changed(lo);
            }
        }else{
                    QString lo = QString("%1%2;%4;\n").arg(type,QString::number(number),QString::number(value));
            emit signal_controller_value_changed(lo);
        }



    }
}
void Controler::slot_controller_connection_closed(){
    emit signal_controller_connection_closed();
}
void Controler::slot_destroy_pad(){
    emit sinal_destroy_pad();
}
