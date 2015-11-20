#ifndef CUADRADO_H
#define CUADRADO_H

#include <QMainWindow>
#include <QDialog>
#include <QtGui>
#include <QtCore>

namespace Ui {
class cuadrado;
}

class cuadrado : public QMainWindow
{
    Q_OBJECT

public:
    explicit cuadrado(QWidget *parent = 0);
    ~cuadrado();
       void imprimeCuadrado(QPainter &painter);

private slots:
    void on_pushButton_clicked();

    void on_okTras_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();
protected:
    void paintEvent(QPaintEvent *e);

private:
    Ui::cuadrado *ui;
   bool dibuja = false;
   double centerX;
   double centerY;

       QVector<QTransform> transforms;

};

#endif // CUADRADO_H
