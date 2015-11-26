#include "dualshok3.h"
#include "qdebug.h"

DualShok3::DualShok3()
{
     setRotation(0);
     setLinearSpeed(-axis_range);
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
//    if (turn==1)
    linearSpeed =(slinearSpeed+axis_range)>>1;
//    else if (turn==-1)
//    linearSpeed =-(slinearSpeed+32767)/2;
}

void DualShok3::setRotation(int srotation)
{
    rotation=srotation;
}


//        axis13
//        button13
//        axis0
QString DualShok3::xmlcreator(QString type, int number, int value){
    if (type =="axis"){
        if (number ==0)         setRotation(value);
         else if(number ==13)   setLinearSpeed(value);
         else                   return "not important";
    } else if (type =="button"){
        if (number == 13)       setTurn(value);
        else                    return "not important";


    }else{
        return "not important";        
    }
    QString str = QString("<?xml version=\"1.0\" encoding=\"UTF-8\"?> <SteeringCommands> "
                          "<Speed value=%1>Linear speed value</Speed> <Rotation value=%2>Rotational speed value</Rotation>"
                          " </SteeringCommands>\n").arg( QString::number(turn*linearSpeed), QString::number(rotation));
    return str;

}
