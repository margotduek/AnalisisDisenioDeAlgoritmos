#include "triangulo.h"
#include "ui_triangulo.h"

#include <QMessageBox>
#include <math.h>
#include <QLineEdit>


triangulo::triangulo(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::triangulo)
{
    ui->setupUi(this);
    centerX = width()/2;
    centerY = height()/2;
    QTransform center;
    center.translate(centerX,centerY);
    transforms.push_back(center);

}

triangulo::~triangulo()
{
    delete ui;
}


void triangulo::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    QPen pointPen(Qt::black);
    pointPen.setWidth(2);
    painter.setPen(pointPen);

    if (dibuja)
    {
        for(int i=0; i<transforms.size(); ++i)
        {
            painter.setTransform(transforms[i],true);
            imprimetriangulo(painter);

        }
    }
}


void triangulo::imprimetriangulo(QPainter &painter){
    int x1 = -25;
    int y1 = 25;
    int x2 = 25;
    int y2 = 25;
    int x3 = -25;
    int y3 = -25;
    int x4 = 25;
    int y4 = -25;
    int distProp = (x2-x1)/2;
    int _x1 = x1+distProp;
    int _y1 = y1-distProp;
    int _x2 = x2+distProp;
    int _y2 = y2-distProp;
    int _x3 = x3+distProp;
    int _y3 = y3-distProp;
    int _x4 = x4+distProp;
    int _y4 = y4-distProp;

    painter.drawLine(x1, y1, x2, y2);
    painter.drawLine(x1, y1, x3, y3);
    painter.drawLine(x2, y2, x4, y4);
    painter.drawLine(x3, y3, x4, y4);
    painter.drawLine(_x1, _y1, _x2, _y2);
    painter.drawLine(_x1, _y1, _x3, _y3);
    painter.drawLine(_x2, _y2, _x4, _y4);
    painter.drawLine(_x3, _y3, _x4, _y4);
    painter.drawLine(x1, y1, _x1, _y1);
    painter.drawLine(x2, y2, _x2, _y2);
    painter.drawLine(x3, y3, _x3, _y3);
    painter.drawLine(x4, y4, _x4, _y4);
    //All rights reseved
}




/*Zoom*/
void triangulo::on_pushButton_clicked()
{
    float z;
    z = ui->zoom->text().toFloat();
    QTransform zoomOut;
    zoomOut.scale(z,z);
    transforms.push_back(zoomOut);
    update();
}

/*trans*/
void triangulo::on_okTras_clicked()
{
    float tr = ui->trs->text().toFloat();
    //QString xStr = ui->transX->toPlainText();
    //QString yStr = ui->transY->toPlainText();
    QTransform translate;
    translate.translate(tr,tr);
    transforms.push_back(translate);

    update();
}

/*refle*/
void triangulo::on_pushButton_4_clicked()
{
    QTransform esca;
    esca.scale(-1,1);
    transforms.push_back(esca);
    update();
}

/*Rotacion*/
void triangulo::on_pushButton_2_clicked()
{
    int rota = ui->rot->text().toFloat();
    QTransform rotate;
    rotate.rotate(rota);
    transforms.push_back(rotate);
    update();

}
