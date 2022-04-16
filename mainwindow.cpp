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

    scene=new QGraphicsScene(x,y,1090,770);

    QGraphicsView* view = new QGraphicsView(scene);
    ui->graphicsView->setBackgroundBrush(Qt::darkGray);

    ui->graphicsView->setScene(scene);

    QPushButton* N1= new QPushButton();
//    scene->addItem(N1);

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_Nivel1_clicked()
{
    ui->graphicsView->setBackgroundBrush(Qt::darkGreen);
    ui->graphicsView->setScene(scene);

    ui->stackedWidget->setCurrentIndex(1);



    //Creación de objetos estáticos
    barra1=new QGraphicsRectItem(35, 70, 20, 670);
    scene->addItem(barra1);
    barra1->setBrush(Qt::yellow);

    barra2=new QGraphicsRectItem(1030, 70, 20, 670);
    scene->addItem(barra2);
    barra2->setBrush(Qt::yellow);

}

void MainWindow::on_Nivel2_clicked()
{
    ui->graphicsView->setBackgroundBrush(Qt::darkGreen);
    ui->graphicsView->setScene(scene);

    ui->stackedWidget->setCurrentIndex(2);


    //Creación de objetos estáticos
    barra1=new QGraphicsRectItem(35, 70, 20, 670);
    scene->addItem(barra1);
    barra1->setBrush(Qt::yellow);

    barra2=new QGraphicsRectItem(1030, 70, 20, 670);
    scene->addItem(barra2);
    barra2->setBrush(Qt::yellow);

}

void MainWindow::on_Nivel3_clicked()
{
    ui->graphicsView->setBackgroundBrush(Qt::darkGreen);
    ui->graphicsView->setScene(scene);

    ui->stackedWidget->setCurrentIndex(3);


    //Creación de objetos estáticos
    barra1=new QGraphicsRectItem(35, 70, 20, 670);
    scene->addItem(barra1);
    barra1->setBrush(Qt::yellow);

    barra2=new QGraphicsRectItem(1030, 70, 20, 670);
    scene->addItem(barra2);
    barra2->setBrush(Qt::yellow);

}

void MainWindow::on_Inicio1_clicked()
{
    ui->graphicsView->setBackgroundBrush(Qt::darkGray);
    ui->graphicsView->setScene(scene);

    ui->stackedWidget->setCurrentIndex(0);

    barra1->hide();
    barra2->hide();
}

void MainWindow::on_Inicio2_clicked()
{
    ui->graphicsView->setBackgroundBrush(Qt::darkGray);
    ui->graphicsView->setScene(scene);

    ui->stackedWidget->setCurrentIndex(0);
    barra1->hide();
    barra2->hide();
}

void MainWindow::on_Inicio3_clicked()
{
    ui->graphicsView->setBackgroundBrush(Qt::darkGray);
    ui->graphicsView->setScene(scene);

    ui->stackedWidget->setCurrentIndex(0);
    barra1->hide();
    barra2->hide();
}

void MainWindow::on_Salir_clicked()
{
    this->close();
}

