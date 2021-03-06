#include "dualshok3.h"
#include "qdebug.h"

DualShok3::DualShok3()
{
     setRotation(0);
     setLinearSpeed(-range);
     setTurn(0);
}

void DualShok3::setTurn(int sturn)
{
    if (sturn==0){
    turn=1;
    }
    else if(sturn == 1)
    turn=-1;
}

void DualShok3::setLinearSpeed(int slinearSpeed)
{
    linearSpeed =(slinearSpeed+range)>>1;
}

void DualShok3::setRotation(int srotation)
{
    rotation=srotation;
}


QString DualShok3::xmlcreator(QString type, int number, int value){

    qDebug ()<<type;
    if (type =="axis"){
        if (number ==axis_rotation_number){
            setRotation(value);

        } else if(number ==axis_liear_number){
            setLinearSpeed(value);

        }else{
            return "not important";
        }
    } else if (type =="button"){
        if (number == direction_button_number){
            setTurn(value);
        }else {
            return "not important";
        }

    }else{
        return "not important";
    }





    QString str = QString(";%1,%2;\n").arg( QString::number(turn*linearSpeed), QString::number(rotation));


// QString str = QString("<?xml version=\"1.0\" encoding=\"UTF-8\"?> <SteeringCommands> "
//                          "<Speed value=%1>Linear speed value</Speed> "
//                          "<Rotation value=%2>Rotational speed value</Rotation> "
//                          "</SteeringCommands>\n").arg( QString::number(turn*linearSpeed), QString::number(rotation));
    return str;

}
