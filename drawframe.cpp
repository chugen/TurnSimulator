#include "drawframe.h"
#include "ui_drawframe.h"
#include "calcturn.h"
#include "QPainter"
#include "QWidget"
#include "QPainterPath"
#include "QColor"
#include <math.h>
#include <stdint.h>
#include "QDebug"
#include "QBrush"


DrawFrame::DrawFrame(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::DrawFrame)
{
    ui->setupUi(this);
    calcturn=new CalcTurn;
}


DrawFrame::~DrawFrame()
{
    delete ui;
    delete calcturn;
}

void DrawFrame::paintEvent(QPaintEvent *){

    DrawFrame::drawWall();
    DrawFrame::drawPath();
    DrawFrame::update();

}

void DrawFrame::drawWall(){
    QPainter painter(this);
    QBrush brush;
    QColor color;
    QPen pen;

    painter.setRenderHint(QPainter::Antialiasing,true);

    color.setHsv(200,255,0,255);

    brush.setColor(color.toHsv());
    brush.setStyle(Qt::SolidPattern);
    painter.fillRect(QRectF(0,0,this->geometry().width()
                            ,this->geometry().height()),brush);

    color.setHsv(0,0,255,255);
    brush.setStyle(Qt::Dense4Pattern);
    brush.setColor(color.toHsv());

    pen.setStyle(Qt::SolidLine);
    pen.setColor(color.toHsv());
    pen.setWidthF(0.5);
    painter.setPen(pen);

    brush.setStyle(Qt::SolidPattern);

    painter.translate(size_pillar/2,size_pillar/2);

    for(uint8_t i=0;i<5;i++){//縦
        painter.translate(size_section/2*i,0);
        painter.drawLine(0,0,0,size_section*2);
        painter.resetTransform();
        painter.translate(size_pillar/2,size_pillar/2);
    }
    for(uint8_t i=0;i<5;i++){//横
        painter.translate(0,size_section/2*i);
        painter.drawLine(0,0,size_section*2,0);
        painter.resetTransform();
        painter.translate(size_pillar/2,size_pillar/2);
    }
    for(uint8_t i=0;i<2;i++){//斜め
        for(uint8_t j=0;j<2;j++){
            painter.translate(size_section*i,size_section*j);
            painter.drawLine(size_section/2,0,0,size_section/2);
            painter.drawLine(0,size_section/2,size_section/2,size_section);
            painter.drawLine(size_section/2,size_section,size_section,size_section/2);
            painter.drawLine(size_section,size_section/2,size_section/2,0);
            painter.resetTransform();
            painter.translate(size_pillar/2,size_pillar/2);
        }
    }

    color.setHsv(0,255,255,255);
    brush.setColor(color.toHsv());

    painter.translate(-size_pillar/2,-size_pillar/2);

    for(uint8_t i=0;i<3;i++){
        for(uint8_t j=0;j<3;j++){
            painter.translate(size_section*i,size_section*j);
            painter.fillRect(QRectF(0,0,size_pillar,size_pillar),brush);
            painter.drawRect(0,0,size_pillar,size_pillar);
            painter.resetTransform();
        }
    }

    painter.translate(size_section,size_section);
    painter.fillRect(QRectF(0,size_pillar,size_pillar,size_wall),brush);
    painter.drawRect(0,size_pillar,size_pillar,size_wall);

    //brush.setStyle(Qt::SolidPattern);

}

void DrawFrame::drawPath(){
    QPainter painter(this);
    QVector <QPoint> vectorpoint;
    QBrush brush;
    QColor color;
    QPen pen;

    painter.resetTransform();
    painter.translate(size_pillar/2,size_pillar/2);
    painter.translate(size_section/2,3*size_section/2);
    painter.scale(1,-1);
    pen.setStyle(Qt::SolidLine);
    brush.setColor(color.toHsv());
    color.setHsv(270,255,255,255);
    color.setRgb(0,255,0,255);
    pen.setColor(color.toRgb());
    pen.setWidthF(2);
    painter.setPen(pen);

    painter.drawLines(vectorpoint);
}


