#ifndef CALCTURN_H
#define CALCTURN_H

#include <QObject>
#include <QVector>
#include <QPoint>
#include <QFrame>
#include <QString>
#include "calcturn.h"
#include "stdint.h"

class CalcTurn
{
public:
    explicit CalcTurn();
    ~CalcTurn();

    /************************************************
    Setter
     ************************************************/
    void setVelocity(double);
    void setOmega(double);
    void setOffset1(double);
    void setSlip(double);
    void setWeight(double);

    void setTurnType(QString);
    /************************************************
    Getter
     ************************************************/
    QVector <QPoint> getPathOfTurn();
    QVector <QPoint> getPathOfTurnWithSlip();
private:
    QVector <QPoint> coord;
    QVector <QPoint> coord_slip;

    double value_velocity;
    double value_omega;
    double value_offset1;
    double value_offset2;
    double value_weight;
    double value_slip;

    double value_degree;

    double calc_alpha;
    double calc_alpha_peak;
    double calc_omega;
    double calc_degree;

    double calc_peaktime;

    const double value_period=0.001;

    QString value_turntype;

    void resetValue();
    void calcurate();


};

#endif // CALCTURN_H
