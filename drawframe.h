#ifndef DRAWFRAME_H
#define DRAWFRAME_H


#include <QFrame>
#include <QString>
#include <stdint.h>
#include "calcturn.h"


namespace Ui {
class DrawFrame;
}

class DrawFrame : public QFrame
{
    Q_OBJECT

public:
    explicit DrawFrame(QWidget *parent = 0);
    ~DrawFrame();
protected:
    void paintEvent(QPaintEvent*);
private:
    CalcTurn *calcturn;
    Ui::DrawFrame *ui;
    void drawWall();
    void drawPath();


    double scale_ratio=1.5;

    double size_section=180*scale_ratio;
    double size_wall=168*scale_ratio;
    double size_pillar=12*scale_ratio;

    double value_velocity;
    double value_omega;
    double value_offset1;
    double value_offset2;
    double value_weight;
    double value_degree;

    QString value_turntype;
private slots:


};

#endif // DRAWFRAME_H
