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
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGraphicsView *graphicsView;
    QComboBox *comboBox;
    QLineEdit *zoom;
    QLineEdit *trs;
    QLineEdit *refle;
    QPushButton *pushButton;
    QPushButton *okTras;
    QPushButton *pushButton_4;
    QLabel *label;
    QPushButton *pushButton_2;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1011, 463);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(295, 50, 711, 351));
        comboBox = new QComboBox(centralWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(300, 10, 701, 23));
        zoom = new QLineEdit(centralWidget);
        zoom->setObjectName(QStringLiteral("zoom"));
        zoom->setGeometry(QRect(10, 50, 113, 23));
        trs = new QLineEdit(centralWidget);
        trs->setObjectName(QStringLiteral("trs"));
        trs->setGeometry(QRect(10, 80, 113, 23));
        refle = new QLineEdit(centralWidget);
        refle->setObjectName(QStringLiteral("refle"));
        refle->setGeometry(QRect(10, 110, 113, 23));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(140, 50, 80, 23));
        okTras = new QPushButton(centralWidget);
        okTras->setObjectName(QStringLiteral("okTras"));
        okTras->setGeometry(QRect(140, 80, 80, 23));
        pushButton_4 = new QPushButton(centralWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(140, 110, 80, 23));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 150, 91, 21));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(10, 170, 41, 23));
        pushButton_5 = new QPushButton(centralWidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(60, 170, 41, 23));
        pushButton_6 = new QPushButton(centralWidget);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(110, 170, 41, 23));
        pushButton_7 = new QPushButton(centralWidget);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setGeometry(QRect(160, 170, 41, 23));
        pushButton_8 = new QPushButton(centralWidget);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setGeometry(QRect(210, 170, 41, 23));
        MainWindow->setCentralWidget(centralWidget);
        pushButton_2->raise();
        graphicsView->raise();
        comboBox->raise();
        zoom->raise();
        trs->raise();
        refle->raise();
        pushButton->raise();
        okTras->raise();
        pushButton_4->raise();
        label->raise();
        pushButton_5->raise();
        pushButton_6->raise();
        pushButton_7->raise();
        pushButton_8->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1011, 20));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Elige Figura", 0)
         << QApplication::translate("MainWindow", "Cuadrado", 0)
         << QApplication::translate("MainWindow", "Poligono", 0)
         << QApplication::translate("MainWindow", "Sombrero", 0)
         << QApplication::translate("MainWindow", "Triangulo", 0)
         << QApplication::translate("MainWindow", "Pesa(ejercicio)", 0)
         << QApplication::translate("MainWindow", "Circulo", 0)
         << QApplication::translate("MainWindow", "Carroza", 0)
        );
        zoom->setText(QApplication::translate("MainWindow", "Zoom", 0));
        trs->setText(QApplication::translate("MainWindow", "Traslacion", 0));
        refle->setText(QApplication::translate("MainWindow", "Reflexion", 0));
        pushButton->setText(QApplication::translate("MainWindow", "Ok", 0));
        okTras->setText(QApplication::translate("MainWindow", "Ok", 0));
        pushButton_4->setText(QApplication::translate("MainWindow", "Ok", 0));
        label->setText(QApplication::translate("MainWindow", "Rotacion", 0));
        pushButton_2->setText(QApplication::translate("MainWindow", "45\302\260", 0));
        pushButton_5->setText(QApplication::translate("MainWindow", "90\302\260", 0));
        pushButton_6->setText(QApplication::translate("MainWindow", "135\302\260", 0));
        pushButton_7->setText(QApplication::translate("MainWindow", "180\302\260", 0));
        pushButton_8->setText(QApplication::translate("MainWindow", "260\302\260", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
