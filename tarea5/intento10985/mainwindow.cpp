#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "cuadrado.h"


#include <QtGui>
#include <iostream>
#include <QDebug>
#include <QPainterPath>
#include <QTransform>
#include <QPainter>
#include <QPaintEvent>
#include <QGraphicsItem>
#include <QList>
#include <QRect>
#include <QWidget>
#include <QInputDialog>
#include <QPainter>
#include <QDialog>
#include <QtCore>
#include <QGraphicsView>
/*
int indexx;
float zoom;
//QPainterPath cuadrado;
QPainter cuad;
QPainterPath poli;
QPainterPath sombrero;
QPainterPath circulo;
QPainterPath pesa;
//QPainterPath coche;
QPainterPath triangulo;

*/


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
/*
    scene = new QGraphicsScene;
    scene->setSceneRect(0,0,711,351);
    //scene->addLine(0, 96,341,96, QPen(Qt::green));
    int centerX = width()/3;
    int centerY = height()/5;
    QTransform center;
    center.translate(centerX,centerY);
    transforms.push_back(center);


    //ui->graphicsView->setScene(scene);
    //ui->graphicsView->show();
    */
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_comboBox_currentIndexChanged(int index)
{

    switch(index){
        case 1:
            cuadrado cu;
            cu.show();
        break;
        case 2:
            cuadrado cu;
            cu.show();
        break;
        case 3:
            cuadrado cu;
            cu.show();
        break;
        case 4:
            cuadrado cu;
            cu.show();
        break;
        case 5:
            cuadrado cu;
            cu.show();
        break;
        case 6:
            cuadrado cu;
            cu.show();
        break;

    }
}

/*
void MainWindow::imprimeCuadrado(QPainter &painter){
   //aqui dibujo

    QPainterPath cuadrado;
    cuadrado.moveTo(200,200);
    cuadrado.lineTo(350,200);
    cuadrado.lineTo(350,350);
    cuadrado.lineTo(200,350);
    cuadrado.lineTo(200,200);
    painter.drawPath(cuadrado);
    //ui->graphicsView->acceptDrops()


    //scene->addPath(cuadrado);

/*
    ui->graphicsView->setScene(scene);
    ui->graphicsView->show();

}

void MainWindow::imprimeCirculo(int x){
    circulo.addEllipse(150,60,100,100);
    scene->addPath(circulo);
}

void MainWindow::imprimeCurva(int x){
    sombrero.moveTo(50,150);
    sombrero.lineTo(250,150);
    sombrero.lineTo(250,120);
    sombrero.lineTo(225,120);
    sombrero.lineTo(225,70);
    sombrero.lineTo(75,70);
    sombrero.lineTo(75,120);
    sombrero.lineTo(50,120);
    sombrero.lineTo(50,150);
    scene->addPath(sombrero);


}

void MainWindow::imprimeFiguras(int x){
    pesa.addEllipse(20,100,75,75);
    pesa.addEllipse(200,100,75,75);
    pesa.moveTo(95,140);
    pesa.lineTo(200,140);
    scene->addPath(pesa);
}

void MainWindow::imprimePoligono(int x){

    poli.moveTo(75,50);
    poli.lineTo(125,50);
    poli.lineTo(150,150);
    poli.lineTo(50,150);
    poli.lineTo(75,50);

    scene->addPath(poli);
}

/*
void MainWindow::imprimeCoche(int x){
    scene->addLine(x*50,x*150,x*250,x*150);

    scene->addLine(x*50,x*150,x*50,x*120);
    scene->addLine(x*50,x*120,x*75,x*120);
    scene->addLine(x*75,x*120,x*75,x*70);

    scene->addLine(x*250,x*150,x*250,x*120);
    scene->addLine(x*250,x*120,x*225,x*120);
    scene->addLine(x*225,x*120,x*225,x*70);

    scene->addLine(x*225,x*70,x*75,x*70);
    scene->addEllipse(x*20,x*125,x*50,x*50);
    scene->addEllipse(x*225,x*125,x*50,x*50);

}

void MainWindow::imprimeTriangulo(int x){
    triangulo.moveTo(50,50);
    triangulo.lineTo(75,150);
    triangulo.lineTo(150,50);
    triangulo.lineTo(50,50);
    scene->addPath(triangulo);


    //ui->graphicsView->setScene(scene);
    //ui->graphicsView->show();
}


void MainWindow::paintEvent(QPaintEvent *e){
    QPainter painter(this);
    switch(indexx){
        case 1:
            //scene->addItem(cuadrado);
            for(int i = 0; i < transforms.size(); ++i){
                painter.setTransform(transforms[i],true);
            }

            imprimeCuadrado(painter);
        break;

        case 2:
            //imprimePoligono(painter);
        break;

        case 3:
            //imprimeCurva(painter);
        break;

        case 4:
            //imprimeTriangulo(painter);
        break;

        case 5:
            //imprimeFiguras(painter);
        break;

        case 6:
            //imprimeCirculo(painter);
        break;
    }

}
*/



/* Cada que llega un evento esta función actualiza todo
void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.fillRect(event->rect(), QBrush(Qt::darkRed));

    /* Se divide esntre estos numeros para uqe siemrpe esté en el centro
    painter.translate(this->width()/3, this->height()/2.5);
    painter.save();
    transformPainter(painter);
    drawShape(painter);
    painter.restore();
    //drawOutline(painter);
    transformPainter(painter);
}
*/

/* Escala
void MainWindow::on_pushButton_clicked(){
    float z;
    z = ui->zoom->text().toFloat();
    zoom = z;

    switch(indexx){
    case 1:
    {

        QTransform zoomito;
        zoomito.scale(zoom,zoom);
        transforms.push_back(zoomito);
        update();



        //QPainter cuadrado;
        //QTransform trasform;
        //cuadrado.scale(zoom,zoom);
        //cuadrado.fillPath(cuadrado, Qt::red);
        /*scene->addLine(zoom*50,zoom*100,zoom*100,zoom*50);
        scene->addLine(zoom*50,zoom*100,zoom*100,zoom*150);
        scene->addLine(zoom*150,zoom*100,zoom*100,zoom*50);
        scene->addLine(zoom*100,zoom*150,zoom*150,zoom*100);

        //imprimeCuadrado(1);
        qDebug() << "cuadrado" ;
        //cuadrado.scale(9,9);
    }
    break;
    case 2:{
        QTransform poli;
        poli.scale(zoom,zoom);
        imprimePoligono(zoom);

    }
    break;

    case 3:{
        QTransform sombrero;
        sombrero.scale(zoom,zoom);
        imprimeCurva(zoom);
    }

    case 4:
        imprimeTriangulo(zoom);
    break;

    case 5:
        imprimeFiguras(zoom);
    break;

    case 6:
        imprimeCirculo(zoom);
    break;
    case 7:
        //imprimeCoche(zoom);
    break;

    }

}

/* Rotación de 45°
void MainWindow::on_pushButton_2_clicked()
{
    int zoom = 1;

    switch(indexx){
    case 1:
        scene->addLine(zoom*50,zoom*100,zoom*100,zoom*50);
        scene->addLine(zoom*50,zoom*100,zoom*100,zoom*150);
        scene->addLine(zoom*150,zoom*100,zoom*100,zoom*50);
        scene->addLine(zoom*100,zoom*150,zoom*150,zoom*100);
    break;
    case 2:{
        QTransform poli;
        poli.scale(zoom,zoom);
        imprimePoligono(zoom);

    }
    break;

    case 3:{
        QTransform sombrero;
        sombrero.scale(zoom,zoom);
        imprimeCurva(zoom);
    }
    break;

    case 4:
        imprimeTriangulo(zoom);

    break;

    case 5:
        imprimeFiguras(zoom);
    break;

    case 6:
        imprimeCirculo(zoom);
    break;
    case 7:
        //imprimeCoche(zoom);
    break;
    }
}

void MainWindow::on_pushButton_5_clicked()
{
    int zoom = 1;
    switch(indexx){
    case 1:
       //imprimeCuadrado(zoom);
    break;
    case 2:
        imprimePoligono(zoom);
    break;

    case 3:
        imprimeCurva(zoom);
    break;

    case 4:
        imprimeTriangulo(zoom);

    break;

    case 5:
        imprimeFiguras(zoom);
    break;

    case 6:
        imprimeCirculo(zoom);
    break;
    case 7:
        //imprimeCoche(zoom);
    break;
    }
}

void MainWindow::on_pushButton_6_clicked()
{
    int zoom = 1;
    switch(indexx){
    case 1:
        scene->addLine(zoom*50,zoom*100,zoom*100,zoom*50);
        scene->addLine(zoom*50,zoom*100,zoom*100,zoom*150);
        scene->addLine(zoom*150,zoom*100,zoom*100,zoom*50);
        scene->addLine(zoom*100,zoom*150,zoom*150,zoom*100);
    break;
    case 2:
        imprimePoligono(zoom);
    break;

    case 3:
        imprimeCurva(zoom);
    break;

    case 4:
        imprimeTriangulo(zoom);

    break;

    case 5:
        imprimeFiguras(zoom);
    break;

    case 6:
        imprimeCirculo(zoom);
    break;
    case 7:
        //imprimeCoche(zoom);
    break;
    }
}

void MainWindow::on_pushButton_7_clicked()
{
    int zoom = 1;
    switch(indexx){
    case 1:
        //imprimeCuadrado(zoom);
    break;
    case 2:
        imprimePoligono(zoom);
    break;

    case 3:
        imprimeCurva(zoom);
    break;

    case 4:
        imprimeTriangulo(zoom);

    break;

    case 5:
        imprimeFiguras(zoom);
    break;

    case 6:
        imprimeCirculo(zoom);
    break;
    case 7:
        //imprimeCoche(zoom);
    break;
    }
}

void MainWindow::on_okTras_clicked()
{
    int trans;
    trans = ui->trs->text().toInt();

    switch(indexx){
    case 1:
        //cuadrado.translate(trans,trans);
        //imprimeCuadrado(1);
    break;
    case 2:
        poli.translate(trans,trans);
        imprimePoligono(1);
    break;

    case 3:
        sombrero.translate(trans,trans);
        imprimeCurva(1);
    break;

    case 4:
        triangulo.translate(trans,trans);
        imprimeTriangulo(1);
    break;

    case 5:
        pesa.translate(trans,trans);
        imprimeFiguras(1);
    break;

    case 6:
        circulo.translate(trans,trans);
        imprimeCirculo(1);
    break;
    }

}
*/

void MainWindow::on_pushButton_3_clicked()
{
    cuadrado cu;
    cu.show();
}
