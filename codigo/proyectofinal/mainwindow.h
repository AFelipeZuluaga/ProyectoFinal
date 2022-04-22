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
#include <fstream>
#include <sstream>
#include <string>


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


    void on_Registrarse_clicked();

    void on_lineEdit_returnPressed();

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
    void Actualizar();
    void Borrar_bolas();
    void Chocar();

private:
    Ui::MainWindow *ui;
    QGraphicsScene* scene;
    QGraphicsRectItem* barra1;
    QGraphicsRectItem* barra2;
    QGraphicsEllipseItem* centro;
    esfera_lanzada* bola_lanz1;
    //QList <esferas*> bolas;
    esferas* bolas[900];
    QTimer *timer;
    QString usuario;
    string para_registrar;

        float x,y,ancho,alto;

        int puntuacion=0;
        bool moverA;
        bool moverS;
        bool moverD;
        bool moverZ;
        bool moverP;
        bool resorte;
        bool crear_bola_lanz1;        
        bool actualiza;
        bool borra_bolas;
        bool juega2;
        bool juega1;
        bool choca;
         int matriz1[6][48]={
             {6, 0, 6, 0, 6, 0, 1, 0, 1, 0, 4, 0, 4, 0, 5, 0, 5, 0, 6, 0, 6, 0, 6, 0, 6, 0, 6, 0, 6, 0, 6, 0, 5, 0, 5, 0, 4, 0, 4, 0, 1, 0, 1, 0, 6, 0, 6, 0},
             {0, 6, 0, 6, 0, 5, 0, 1, 0, 1, 0, 4, 0, 4, 0, 5, 0, 5, 0, 6, 0, 6, 0, 6, 0, 6, 0, 6, 0, 6, 0, 5, 0, 5, 0, 4, 0, 4, 0, 1, 0, 1, 0, 5, 0, 6, 0, 6},
             {6, 0, 6, 0, 5, 0, 2, 0, 2, 0, 2, 0, 4, 0, 4, 0, 5, 0, 5, 0, 6, 0, 6, 0, 6, 0, 6, 0, 6, 0, 5, 0, 5, 0, 4, 0, 4, 0, 2, 0, 2, 0, 2, 0, 5, 0, 6, 0},
             {0, 6, 0, 5, 0, 5, 0, 2, 0, 2, 0, 2, 0, 4, 0, 4, 0, 5, 0, 5, 0, 6, 0, 6, 0, 6, 0, 6, 0, 5, 0, 5, 0, 4, 0, 4, 0, 2, 0, 2, 0, 2, 0, 5, 0, 5, 0, 6},
             {6, 0, 5, 0, 5, 0, 3, 0, 3, 0, 3, 0, 3, 0, 4, 0, 4, 0, 5, 0, 5, 0, 6, 0, 6, 0, 6, 0, 5, 0, 5, 0, 4, 0, 4, 0, 3, 0, 3, 0, 3, 0, 3, 0, 5, 0, 5, 0},
             {0, 5, 0, 5, 0, 5, 0, 3, 0, 3, 0, 3, 0, 3, 0, 4, 0, 4, 0, 5, 0, 5, 0, 6, 0, 6, 0, 5, 0, 5, 0, 4, 0, 4, 0, 3, 0, 3, 0, 3, 0, 3, 0, 5, 0, 5, 0, 5}
          };


         int matriz2[6][48]={
             {1, 0, 2, 0, 3, 0, 4, 0, 5, 0, 6, 0, 6, 0, 5, 0, 4, 0, 3, 0, 2, 0, 1, 0, 1, 0, 2, 0, 3, 0, 4, 0, 5, 0, 6, 0, 6, 0, 5, 0, 4, 0, 3, 0, 2, 0, 1, 0},
             {0, 6, 0, 5, 0, 4, 0, 3, 0, 2, 0, 1, 0, 1, 0, 2, 0, 3, 0, 4, 0, 5, 0, 6, 0, 6, 0, 5, 0, 4, 0, 3, 0, 2, 0, 1, 0, 1, 0, 2, 0, 3, 0, 4, 0, 5, 0, 6},
             {1, 0, 2, 0, 3, 0, 4, 0, 5, 0, 6, 0, 6, 0, 5, 0, 4, 0, 3, 0, 2, 0, 1, 0, 1, 0, 2, 0, 3, 0, 4, 0, 5, 0, 6, 0, 6, 0, 5, 0, 4, 0, 3, 0, 2, 0, 1, 0},
             {0, 6, 0, 5, 0, 4, 0, 3, 0, 2, 0, 1, 0, 1, 0, 2, 0, 3, 0, 4, 0, 5, 0, 6, 0, 6, 0, 5, 0, 4, 0, 3, 0, 2, 0, 1, 0, 1, 0, 2, 0, 3, 0, 4, 0, 5, 0, 6},
             {1, 0, 2, 0, 3, 0, 4, 0, 5, 0, 6, 0, 6, 0, 5, 0, 4, 0, 3, 0, 2, 0, 1, 0, 1, 0, 2, 0, 3, 0, 4, 0, 5, 0, 6, 0, 6, 0, 5, 0, 4, 0, 3, 0, 2, 0, 1, 0},
             {0, 6, 0, 5, 0, 4, 0, 3, 0, 2, 0, 1, 0, 1, 0, 2, 0, 3, 0, 4, 0, 5, 0, 6, 0, 6, 0, 5, 0, 4, 0, 3, 0, 2, 0, 1, 0, 1, 0, 2, 0, 3, 0, 4, 0, 5, 0, 6}
          };


        void keyPressEvent(QKeyEvent *ev);
        void keyReleaseEvent(QKeyEvent *ev);
};
#endif // MAINWINDOW_H
