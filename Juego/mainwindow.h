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
    void on_pushButton_clicked();

    void on_Nivel1_clicked();
    void on_Nivel2_clicked();
    void on_Nivel3_clicked();
    void on_Inicio1_clicked();
    void on_Inicio2_clicked();
    void on_Inicio3_clicked();

    void on_Salir_clicked();



private:
    Ui::MainWindow *ui;
    QGraphicsScene* scene;
    QGraphicsRectItem* barra1;
    QGraphicsRectItem* barra2;


        float x,y,ancho,alto;
};
#endif // MAINWINDOW_H