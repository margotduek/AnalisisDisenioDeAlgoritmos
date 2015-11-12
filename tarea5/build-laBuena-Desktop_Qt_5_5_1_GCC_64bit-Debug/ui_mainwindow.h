/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGraphicsView *graphicsView;
    QLineEdit *zoom;
    QLineEdit *rota;
    QLineEdit *trasla;
    QLineEdit *reflex;
    QComboBox *comboBox;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(400, 300);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(130, 60, 256, 192));
        zoom = new QLineEdit(centralWidget);
        zoom->setObjectName(QStringLiteral("zoom"));
        zoom->setGeometry(QRect(10, 10, 113, 23));
        rota = new QLineEdit(centralWidget);
        rota->setObjectName(QStringLiteral("rota"));
        rota->setGeometry(QRect(10, 40, 113, 23));
        trasla = new QLineEdit(centralWidget);
        trasla->setObjectName(QStringLiteral("trasla"));
        trasla->setGeometry(QRect(10, 70, 113, 23));
        reflex = new QLineEdit(centralWidget);
        reflex->setObjectName(QStringLiteral("reflex"));
        reflex->setGeometry(QRect(10, 100, 113, 23));
        comboBox = new QComboBox(centralWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(138, 10, 251, 23));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 20));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        zoom->setText(QApplication::translate("MainWindow", "Zoom", 0));
        rota->setText(QApplication::translate("MainWindow", "Rotacion", 0));
        trasla->setText(QApplication::translate("MainWindow", "Traslacion ", 0));
        reflex->setText(QApplication::translate("MainWindow", "Reflexion", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Cuadrado", 0)
         << QApplication::translate("MainWindow", "Triangulo", 0)
         << QApplication::translate("MainWindow", "Figuras", 0)
         << QApplication::translate("MainWindow", "Curva", 0)
         << QApplication::translate("MainWindow", "Poligono", 0)
         << QApplication::translate("MainWindow", "Circulo", 0)
        );
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
