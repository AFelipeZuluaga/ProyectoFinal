#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QScreen *screen = QGuiApplication::primaryScreen();
    QRect  screenGeometry = screen->geometry();
    alto = screenGeometry.height()-100;
    ancho = screenGeometry.width()-100;
    x = screenGeometry.x();
    y = screenGeometry.y();

    scene=new QGraphicsScene(x,y,1081,761);

    QGraphicsView* view = new QGraphicsView(scene);
    ui->graphicsView->setBackgroundBrush(Qt::darkGray);

    ui->graphicsView->setScene(scene);


}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_Nivel1_clicked()
{
    ui->graphicsView->setBackgroundBrush(Qt::yellow);
    ui->graphicsView->setScene(scene);
}


void MainWindow::on_Salir_clicked()
{
    this->close();
}

