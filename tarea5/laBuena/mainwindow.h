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
    void setupShapes();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene = new QGraphicsScene;
};

#endif // MAINWINDOW_H
