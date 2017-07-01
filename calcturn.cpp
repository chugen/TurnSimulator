#include "calcturn.h"
#define _USE_MATH_DEFINES
#include "math.h"



CalcTurn::CalcTurn()
{

}

CalcTurn::~CalcTurn(){

}
void CalcTurn::resetValue(){

}

void CalcTurn::calcurate(){
    uint32_t i=0;
    QPoint point;

    coord.clear();
    coord.squeeze();

    calc_alpha_peak=9.0*M_PI/16*pow(value_omega,2)/value_degree;
    calc_peaktime=3.0*value_omega/calc_alpha_peak/2;

    point.setX(0);
    point.setY(0);
    coord.append(point);

    point.setX(0);
    point.setY(value_offset1);
    coord.append(point);
    coord.append(point);

    while(i*value_period<2*calc_peaktime){

        if(1-pow((i*value_period-calc_peaktime)/calc_peaktime,2)>0){


            calc_alpha=-2*calc_alpha_peak*(i*value_period-calc_peaktime)/calc_peaktime*sqrt(1-pow((i*value_period-calc_peaktime)/calc_peaktime,2));

            calc_omega+=calc_alpha*value_period;
            calc_degree+=calc_omega*value_period;
            point.setX(value_velocity*value_period*cos(calc_degree));
            point.setY(value_velocity*value_period*sin(calc_degree));
            coord.append(point);
            coord.append(point);
        }

    }
}


/************************************************
Getter
 ************************************************/
 QVector <QPoint> CalcTurn::getPathOfTurn(){
    return coord;
 }

 QVector <QPoint> CalcTurn::getPathOfTurnWithSlip(){
    return coord_slip;
 }
/************************************************
Setter
 ************************************************/
void CalcTurn::setVelocity(double value){
    value_velocity=value;
}
void CalcTurn::setOmega(double value){
    value_omega=value;
}
void CalcTurn::setOffset1(double value){
    value_offset1=value;
}
void CalcTurn::setSlip(double value){
    value_slip=value;
}

void CalcTurn::setWeight(double value){
    value_weight=value;
}

void CalcTurn::setTurnType(QString value){
    value_turntype=value;
}

