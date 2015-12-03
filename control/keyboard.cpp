#include "keyboard.h"
#include <qdebug.h>


Keyboard::Keyboard()
{
     turn=1;
     rotation =0;
     linearSpeed=0;
}

void Keyboard::setTurn(int sturn)
{
}

void Keyboard::setLinearSpeed(int slinearSpeed)
{
    if (abs(linearSpeed+slinearSpeed)<range)
    linearSpeed +=slinearSpeed;
//    else if (turn==-1)
//    linearSpeed =-(slinearSpeed+32767)/2;
}

void Keyboard::setRotation(int srotation)
{
    if (abs(rotation+srotation)<range)
    rotation+=srotation;
}


QString Keyboard::xmlcreator(QString type, int number, int value){

//    qDebug ()<<type;
//    if (type =="axis"){
//        if (number ==axis_rotation_number){
//            setRotation(value);

//        } else if(number ==axis_liear_number){
//            setLinearSpeed(value);

//        }else{
//            return "not important";
//        }
//    } else if (type =="button"){
//        if (number == direction_button_number){
//            setTurn(value);
//        }else {
//            return "not important";
//        }

//    }else{
//        return "not important";
//    }
//    return "gh";
    qDebug() << type;

    if (type=="W"){
        setLinearSpeed(lin_speed);
    }
    else if (type=="S"){
        setLinearSpeed(-lin_speed);
    }
    else if (type=="A"){
        setRotation(-rot);
    }
    else if (type=="D"){
        setRotation(rot);
    }
    else {
        return "not important";
    }



 QString str = QString("<?xml version=\"1.0\" encoding=\"UTF-8\"?> <SteeringCommands> "
                          "<Speed value=%1>Linear speed value</Speed> "
                          "<Rotation value=%2>Rotational speed value</Rotation> "
                          "</SteeringCommands>\n").arg( QString::number(turn*linearSpeed), QString::number(rotation));
    return str;

}
