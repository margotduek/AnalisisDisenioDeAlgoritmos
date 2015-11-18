#include "mainwindow.h"
#include "ui_mainwindow.h"


#include <QtGui>
#include <iostream>
#include <QDebug>

using namespace std;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qDebug() << "1" << endl;

    //QGraphicsScene *scene = new QGraphicsScene;
    scene = new QGraphicsScene;
    scene->setSceneRect(0,0,256,192);
    qDebug() << "hola" << endl;
    scene->addLine(0, 96,256,96, QPen(Qt::green));

    imprimeCuadrado(258);

  //QGraphicsScene *scene = new QGraphicsScene;
  //scene->setSceneRect(0, 0, 256, 192);
  //drawPolygon(scene);
  ui->graphicsView->setScene(scene);
  ui->graphicsView->show();


  //setupShapes();
}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::imprimeCuadrado(int x){
   //aqui dibujo

    scene->addLine(5,5,20,5);
    scene->addLine(20,5,20,20);
    scene->addLine(20,20,5,20);
    scene->addLine(5,20,5,5);

    ui->graphicsView->setScene(scene);
    ui->graphicsView->show();
}


void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    switch(index){
    case 0:
        imprimeCuadrado(1);
    break;
    }
}




void MainWindow::on_pushButton_4_clicked()
{

}












/*
void MainWindow::setupShapes(){
  QPainterPath cuadrado;
  /*esta linea colorea la figura*//*
  cuadrado.setFillRule(Qt::WindingFill);
  cuadrado.moveTo(-20,-20);
  cuadrado.lineTo(20,-20);
  cuadrado.lineTo(20,20);
  cuadrado.lineTo(-20,20);
  cuadrado.lineTo(-20,-20);


  /*Revisar si si sirve*//*
  QPainterPath arco;
  arco.arcMoveTo(0,0,50,50,20);
  arco.arcTo(0,0,50,50,20, 90);


  QPainterPath poli;
  poli.moveTo(-20.0, -20.0);
  poli.lineTo(20.0, -20.0);
  poli.lineTo(10.0, 20.0);
  poli.lineTo(-10.0, 20.0);
  poli.lineTo(-20.0, -20.0);


  QPainterPath figuras;
  figuras.moveTo(10.0, -20);
  figuras.lineTo(20, 20);
  figuras.lineTo(30, -20);
  figuras.lineTo(10, -20);
  figuras.moveTo(35.0, 35.0);
  figuras.lineTo(-25.0, 35.0);
  figuras.lineTo(10.0, -25.0);
  figuras.lineTo(-10.0, -25.0);
  figuras.lineTo(35.0, 35.0);


  QPainterPath triangulo;
  triangulo.moveTo(10.0, -20);
  triangulo.lineTo(20, 20);
  triangulo.lineTo(30, -20);
  triangulo.lineTo(10, -20);

  QPainterPath circulo;
  circulo.addEllipse(-50.0, -50.0, 100.0, 100.0);

/*
  shapes.append(cuadrado);
  shapes.append(arco);
  shapes.append(poli);
  shapes.append(figuras);
  shapes.append(triangulo);
  shapes.append(circulo);
*
}*/



scene->moveTo(10.0, -20);
scene->lineTo(20, 20);
scene->lineTo(30, -20);
scene->lineTo(10, -20);
scene->moveTo(35.0, 35.0);
scene->lineTo(-25.0, 35.0);
scene->lineTo(10.0, -25.0);
scene->lineTo(-10.0, -25.0);
scene->lineTo(35.0, 35.0);
