/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGraphicsView *graphicsView;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QLabel *label;
    QPushButton *Registrarse;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *Nivel2;
    QPushButton *Nivel3;
    QPushButton *Nivel1;
    QPushButton *Cargar;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QWidget *page_2;
    QPushButton *Inicio1;
    QWidget *page_3;
    QPushButton *Inicio2;
    QWidget *page_4;
    QPushButton *Inicio3;
    QPushButton *Salir;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1329, 843);
        MainWindow->setMinimumSize(QSize(0, 0));
        MainWindow->setMaximumSize(QSize(1920, 1080));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(120, 40, 1081, 761));
        graphicsView->setMaximumSize(QSize(1081, 761));
        graphicsView->setInteractive(true);
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(120, 30, 1091, 771));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        label = new QLabel(page);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 70, 1081, 181));
        QFont font;
        font.setPointSize(100);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        Registrarse = new QPushButton(page);
        Registrarse->setObjectName(QString::fromUtf8("Registrarse"));
        Registrarse->setGeometry(QRect(80, 410, 161, 71));
        label_2 = new QLabel(page);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(290, 400, 91, 41));
        QFont font1;
        font1.setPointSize(13);
        label_2->setFont(font1);
        label_3 = new QLabel(page);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(290, 450, 121, 31));
        label_3->setFont(font1);
        Nivel2 = new QPushButton(page);
        Nivel2->setObjectName(QString::fromUtf8("Nivel2"));
        Nivel2->setGeometry(QRect(460, 620, 191, 71));
        Nivel3 = new QPushButton(page);
        Nivel3->setObjectName(QString::fromUtf8("Nivel3"));
        Nivel3->setGeometry(QRect(800, 620, 191, 71));
        Nivel1 = new QPushButton(page);
        Nivel1->setObjectName(QString::fromUtf8("Nivel1"));
        Nivel1->setGeometry(QRect(80, 620, 191, 71));
        Cargar = new QPushButton(page);
        Cargar->setObjectName(QString::fromUtf8("Cargar"));
        Cargar->setGeometry(QRect(820, 400, 171, 71));
        lineEdit = new QLineEdit(page);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(410, 410, 251, 24));
        lineEdit_2 = new QLineEdit(page);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(410, 450, 251, 24));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        Inicio1 = new QPushButton(page_2);
        Inicio1->setObjectName(QString::fromUtf8("Inicio1"));
        Inicio1->setGeometry(QRect(20, 20, 181, 41));
        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        Inicio2 = new QPushButton(page_3);
        Inicio2->setObjectName(QString::fromUtf8("Inicio2"));
        Inicio2->setGeometry(QRect(30, 20, 181, 41));
        stackedWidget->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName(QString::fromUtf8("page_4"));
        Inicio3 = new QPushButton(page_4);
        Inicio3->setObjectName(QString::fromUtf8("Inicio3"));
        Inicio3->setGeometry(QRect(50, 30, 181, 41));
        stackedWidget->addWidget(page_4);
        Salir = new QPushButton(centralwidget);
        Salir->setObjectName(QString::fromUtf8("Salir"));
        Salir->setGeometry(QRect(1080, 60, 80, 25));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1329, 20));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QApplication::translate("MainWindow", "\302\241Bienvenido!", nullptr));
        Registrarse->setText(QApplication::translate("MainWindow", "Registrarse", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "Usuario:", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "Contrase\303\261a:", nullptr));
        Nivel2->setText(QApplication::translate("MainWindow", "Nivel 2", nullptr));
        Nivel3->setText(QApplication::translate("MainWindow", "Nivel 3", nullptr));
        Nivel1->setText(QApplication::translate("MainWindow", "Nivel 1", nullptr));
        Cargar->setText(QApplication::translate("MainWindow", "Cargar", nullptr));
        Inicio1->setText(QApplication::translate("MainWindow", "Menu inicial", nullptr));
        Inicio2->setText(QApplication::translate("MainWindow", "Menu inicial", nullptr));
        Inicio3->setText(QApplication::translate("MainWindow", "Menu inicial", nullptr));
        Salir->setText(QApplication::translate("MainWindow", "Salir", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
