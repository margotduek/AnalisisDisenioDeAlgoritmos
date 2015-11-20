/********************************************************************************
** Form generated from reading UI file 'cuadrado.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CUADRADO_H
#define UI_CUADRADO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_cuadrado
{
public:
    QWidget *centralwidget;
    QPushButton *okTras;
    QLineEdit *refle;
    QPushButton *pushButton_4;
    QPushButton *pushButton;
    QLineEdit *trs;
    QLineEdit *zoom;
    QLineEdit *rot;
    QPushButton *pushButton_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *cuadrado)
    {
        if (cuadrado->objectName().isEmpty())
            cuadrado->setObjectName(QStringLiteral("cuadrado"));
        cuadrado->resize(800, 600);
        centralwidget = new QWidget(cuadrado);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        okTras = new QPushButton(centralwidget);
        okTras->setObjectName(QStringLiteral("okTras"));
        okTras->setGeometry(QRect(140, 40, 80, 23));
        refle = new QLineEdit(centralwidget);
        refle->setObjectName(QStringLiteral("refle"));
        refle->setGeometry(QRect(10, 70, 113, 23));
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(140, 70, 80, 23));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(140, 10, 80, 23));
        trs = new QLineEdit(centralwidget);
        trs->setObjectName(QStringLiteral("trs"));
        trs->setGeometry(QRect(10, 40, 113, 23));
        zoom = new QLineEdit(centralwidget);
        zoom->setObjectName(QStringLiteral("zoom"));
        zoom->setGeometry(QRect(10, 10, 113, 23));
        rot = new QLineEdit(centralwidget);
        rot->setObjectName(QStringLiteral("rot"));
        rot->setGeometry(QRect(10, 100, 113, 23));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(140, 100, 80, 23));
        cuadrado->setCentralWidget(centralwidget);
        menubar = new QMenuBar(cuadrado);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 20));
        cuadrado->setMenuBar(menubar);
        statusbar = new QStatusBar(cuadrado);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        cuadrado->setStatusBar(statusbar);

        retranslateUi(cuadrado);

        QMetaObject::connectSlotsByName(cuadrado);
    } // setupUi

    void retranslateUi(QMainWindow *cuadrado)
    {
        cuadrado->setWindowTitle(QApplication::translate("cuadrado", "MainWindow", 0));
        okTras->setText(QApplication::translate("cuadrado", "Ok", 0));
        refle->setText(QApplication::translate("cuadrado", "Reflexion", 0));
        pushButton_4->setText(QApplication::translate("cuadrado", "Ok", 0));
        pushButton->setText(QApplication::translate("cuadrado", "Ok", 0));
        trs->setText(QApplication::translate("cuadrado", "Traslacion", 0));
        zoom->setText(QApplication::translate("cuadrado", "Zoom", 0));
        rot->setText(QApplication::translate("cuadrado", "Rotaci\303\263n", 0));
        pushButton_2->setText(QApplication::translate("cuadrado", "Ok", 0));
    } // retranslateUi

};

namespace Ui {
    class cuadrado: public Ui_cuadrado {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CUADRADO_H
