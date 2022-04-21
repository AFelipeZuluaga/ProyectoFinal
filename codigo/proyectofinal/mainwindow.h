#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QDebug>
#include <QGraphicsItem>
#include <QRectF>
#include <QScreen>
#include <QGuiApplication>
#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QKeyEvent>
#include <QPainter>
#include <QTimer>
#include <iostream>
#include <QPixmap>
#include "esfera_lanzada.h"
#include "esferas.h"
#include <QDesktopWidget>
#include <QDebug>
#include <Windows.h>
#include <conio.h>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

public slots:
    //void on_pushButton_clicked();

    void on_Nivel1_clicked();
    void on_Nivel2_clicked();
    void on_Nivel3_clicked();
    void on_Inicio1_clicked();
    void on_Inicio2_clicked();
    void on_Inicio3_clicked();

    void on_Salir_clicked();

    void juguemos();
    void crear_bola_lanzada();

private:
    Ui::MainWindow *ui;
    QGraphicsScene* scene;
    QGraphicsRectItem* barra1;
    QGraphicsRectItem* barra2;
    QGraphicsEllipseItem* centro;
    esfera_lanzada* bola_lanz1;
    esferas* bolas[936];
    QTimer *timer;

        float x,y,ancho,alto;

        bool moverA;
        bool moverS;
        bool moverD;
        bool moverZ;
        bool moverP;
        bool resorte;
        bool crear_bola_lanz1;

        void keyPressEvent(QKeyEvent *ev);
        void keyReleaseEvent(QKeyEvent *ev);
};
#endif // MAINWINDOW_H
