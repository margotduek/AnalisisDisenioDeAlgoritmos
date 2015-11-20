#ifndef TRIANGULO_H
#define TRIANGULO_H


#include <QMainWindow>
#include <QDialog>
#include <QtGui>
#include <QtCore>

namespace Ui {
class triangulo;
}

class triangulo : public QMainWindow
{
    Q_OBJECT

public:
    explicit triangulo(QWidget *parent = 0);
    ~triangulo();
       void imprimetriangulo(QPainter &painter);

private slots:
    void on_pushButton_clicked();

    void on_okTras_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();
protected:
    void paintEvent(QPaintEvent *e);

private:
    Ui::triangulo *ui;
   bool dibuja = false;
   double centerX;
   double centerY;

       QVector<QTransform> transforms;

};

#endif // TRIANGULO_H
