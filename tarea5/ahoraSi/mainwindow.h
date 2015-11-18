#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void imprimeCuadrado(int x);
    void imprimePoligono(int x);
    void imprimeTriangulo(int x);
    void imprimeCirculo(int x);
    void imprimeFiguras(int x);
    void imprimeCurva(int x);
   // void imprimeCoche(int x);

private slots:
    void on_comboBox_currentIndexChanged(int index);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();


    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();


    void on_gotras_clicked();

    void on_okTras_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene = new QGraphicsScene;
};

#endif // MAINWINDOW_H
