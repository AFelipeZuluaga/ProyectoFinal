#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <winuser.h> // FUNCIONES PARA EL CURSOR

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

    ui->stackedWidget->setCurrentIndex(0);

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_Nivel1_clicked()
{
    int matriz[6][48]={
        {6, 0, 6, 0, 6, 0, 1, 0, 1, 0, 4, 0, 4, 0, 5, 0, 5, 0, 6, 0, 6, 0, 6, 0, 6, 0, 6, 0, 6, 0, 6, 0, 5, 0, 5, 0, 4, 0, 4, 0, 1, 0, 1, 0, 6, 0, 6, 0},
        {0, 6, 0, 6, 0, 5, 0, 1, 0, 1, 0, 4, 0, 4, 0, 5, 0, 5, 0, 6, 0, 6, 0, 6, 0, 6, 0, 6, 0, 6, 0, 5, 0, 5, 0, 4, 0, 4, 0, 1, 0, 1, 0, 5, 0, 6, 0, 6},
        {6, 0, 6, 0, 5, 0, 2, 0, 2, 0, 2, 0, 4, 0, 4, 0, 5, 0, 5, 0, 6, 0, 6, 0, 6, 0, 6, 0, 6, 0, 5, 0, 5, 0, 4, 0, 4, 0, 2, 0, 2, 0, 2, 0, 5, 0, 6, 0},
        {0, 6, 0, 5, 0, 5, 0, 2, 0, 2, 0, 2, 0, 4, 0, 4, 0, 5, 0, 5, 0, 6, 0, 6, 0, 6, 0, 6, 0, 5, 0, 5, 0, 4, 0, 4, 0, 2, 0, 2, 0, 2, 0, 5, 0, 5, 0, 6},
        {6, 0, 5, 0, 5, 0, 3, 0, 3, 0, 3, 0, 3, 0, 4, 0, 4, 0, 5, 0, 5, 0, 6, 0, 6, 0, 6, 0, 5, 0, 5, 0, 4, 0, 4, 0, 3, 0, 3, 0, 3, 0, 3, 0, 5, 0, 5, 0},
        {0, 5, 0, 5, 0, 5, 0, 3, 0, 3, 0, 3, 0, 3, 0, 4, 0, 4, 0, 5, 0, 5, 0, 6, 0, 6, 0, 5, 0, 5, 0, 4, 0, 4, 0, 3, 0, 3, 0, 3, 0, 3, 0, 5, 0, 5, 0, 5}
     };

    ui->graphicsView->setBackgroundBrush(Qt::darkGreen);
    ui->graphicsView->setScene(scene);

    ui->stackedWidget->setCurrentIndex(1);



    //Creación de objetos estáticos
    barra1=new QGraphicsRectItem(35, 70, 20, 670);
    scene->addItem(barra1);
    barra1->setBrush(Qt::yellow);

    barra2=new QGraphicsRectItem(1035, 70, 20, 670);
    scene->addItem(barra2);
    barra2->setBrush(Qt::yellow);

    int p=0;
    for(int f=0; f<6; f++){
        for(int c=0; c<48; c++){

            if(matriz[f][c]==1){

                bolas[p]= new esferas(75, 90, 0, 0, 0, 0, "blue");
                bolas[p]->setPos((c*20),(f*35));
                scene->addItem(bolas[p]);
            }

            if(matriz[f][c]==2){

                bolas[p]= new esferas(75, 90, 0, 0, 0, 0, "yellow");
                bolas[p]->setPos((c*20),(f*35));
                scene->addItem(bolas[p]);
            }

            if(matriz[f][c]==3){

                bolas[p]= new esferas(75, 90, 0, 0, 0, 0, "green");
                bolas[p]->setPos((c*20),(f*35));
                scene->addItem(bolas[p]);
            }

            if(matriz[f][c]==4){

                bolas[p]= new esferas(75, 90, 0, 0, 0, 0, "cyan");
                bolas[p]->setPos((c*20),(f*35));
                scene->addItem(bolas[p]);
            }

            if(matriz[f][c]==5){

                bolas[p]= new esferas(75, 90, 0, 0, 0, 0, "red");
                bolas[p]->setPos((c*20),(f*35));
                scene->addItem(bolas[p]);
            }

            if(matriz[f][c]==6){

                bolas[p]= new esferas(75, 90, 0, 0, 0, 0, "magenta");
                bolas[p]->setPos((c*20),(f*35));
                scene->addItem(bolas[p]);
            }
            p++;

        }
    }
    //Bolas quietas
  //  bola1= new esferas(75, 90, 0, 0, 0, 0);
   // scene->addItem(bola1);
   // bola1->setBrush(Qt::yellow);


    centro=new QGraphicsEllipseItem(525, 630, 40, 40);
    scene->addItem(centro);
//    barra2->setBrush(Qt::yellow);


    //Bola para lanzar
    bola_lanz1= new esfera_lanzada(545, 650, 0, 0, 0, 0);
    scene->addItem(bola_lanz1);


}

void MainWindow::on_Nivel2_clicked()
{
    int matriz[6][48]={
        {1, 0, 2, 0, 3, 0, 4, 0, 5, 0, 6, 0, 6, 0, 5, 0, 4, 0, 3, 0, 2, 0, 1, 0, 1, 0, 2, 0, 3, 0, 4, 0, 5, 0, 6, 0, 6, 0, 5, 0, 4, 0, 3, 0, 2, 0, 1, 0},
        {0, 6, 0, 5, 0, 4, 0, 3, 0, 2, 0, 1, 0, 1, 0, 2, 0, 3, 0, 4, 0, 5, 0, 6, 0, 6, 0, 5, 0, 4, 0, 3, 0, 2, 0, 1, 0, 1, 0, 2, 0, 3, 0, 4, 0, 5, 0, 6},
        {1, 0, 2, 0, 3, 0, 4, 0, 5, 0, 6, 0, 6, 0, 5, 0, 4, 0, 3, 0, 2, 0, 1, 0, 1, 0, 2, 0, 3, 0, 4, 0, 5, 0, 6, 0, 6, 0, 5, 0, 4, 0, 3, 0, 2, 0, 1, 0},
        {0, 6, 0, 5, 0, 4, 0, 3, 0, 2, 0, 1, 0, 1, 0, 2, 0, 3, 0, 4, 0, 5, 0, 6, 0, 6, 0, 5, 0, 4, 0, 3, 0, 2, 0, 1, 0, 1, 0, 2, 0, 3, 0, 4, 0, 5, 0, 6},
        {1, 0, 2, 0, 3, 0, 4, 0, 5, 0, 6, 0, 6, 0, 5, 0, 4, 0, 3, 0, 2, 0, 1, 0, 1, 0, 2, 0, 3, 0, 4, 0, 5, 0, 6, 0, 6, 0, 5, 0, 4, 0, 3, 0, 2, 0, 1, 0},
        {0, 6, 0, 5, 0, 4, 0, 3, 0, 2, 0, 1, 0, 1, 0, 2, 0, 3, 0, 4, 0, 5, 0, 6, 0, 6, 0, 5, 0, 4, 0, 3, 0, 2, 0, 1, 0, 1, 0, 2, 0, 3, 0, 4, 0, 5, 0, 6}
     };


    ui->graphicsView->setBackgroundBrush(Qt::darkGreen);
    ui->graphicsView->setScene(scene);

    ui->stackedWidget->setCurrentIndex(2);


    //Creación de objetos estáticos
    barra1=new QGraphicsRectItem(35, 70, 20, 670);
    scene->addItem(barra1);
    barra1->setBrush(Qt::yellow);

    barra2=new QGraphicsRectItem(1035, 70, 20, 670);
    scene->addItem(barra2);
    barra2->setBrush(Qt::yellow);


    int p=0;

    for(int f=0; f<6; f++){
        for(int c=0; c<48; c++){

            if(matriz[f][c]==1){

                bolas[p]= new esferas(75, 90, 0, 0, 0, 0, "blue");
                bolas[p]->setPos((c*20),(f*35));
                scene->addItem(bolas[p]);
            }

            if(matriz[f][c]==2){

                bolas[p]= new esferas(75, 90, 0, 0, 0, 0, "yellow");
                bolas[p]->setPos((c*20),(f*35));
                scene->addItem(bolas[p]);
            }

            if(matriz[f][c]==3){

                bolas[p]= new esferas(75, 90, 0, 0, 0, 0, "green");
                bolas[p]->setPos((c*20),(f*35));
                scene->addItem(bolas[p]);
            }

            if(matriz[f][c]==4){

                bolas[p]= new esferas(75, 90, 0, 0, 0, 0, "cyan");
                bolas[p]->setPos((c*20),(f*35));
                scene->addItem(bolas[p]);
            }

            if(matriz[f][c]==5){

                bolas[p]= new esferas(75, 90, 0, 0, 0, 0, "red");
                bolas[p]->setPos((c*20),(f*35));
                scene->addItem(bolas[p]);
            }

            if(matriz[f][c]==6){

                bolas[p]= new esferas(75, 90, 0, 0, 0, 0, "magenta");
                bolas[p]->setPos((c*20),(f*35));
                scene->addItem(bolas[p]);
            }
            p++;

        }
    }


}

void MainWindow::on_Nivel3_clicked()
{

    int matriz[6][48]={
        {1, 0, 2, 0, 3, 0, 4, 0, 5, 0, 6, 0, 6, 0, 5, 0, 4, 0, 3, 0, 2, 0, 1, 0, 1, 0, 2, 0, 3, 0, 4, 0, 5, 0, 6, 0, 6, 0, 5, 0, 4, 0, 3, 0, 2, 0, 1, 0},
        {0, 6, 0, 5, 0, 4, 0, 3, 0, 2, 0, 1, 0, 1, 0, 2, 0, 3, 0, 4, 0, 5, 0, 6, 0, 6, 0, 5, 0, 4, 0, 3, 0, 2, 0, 1, 0, 1, 0, 2, 0, 3, 0, 4, 0, 5, 0, 6},
        {1, 0, 2, 0, 3, 0, 4, 0, 5, 0, 6, 0, 6, 0, 5, 0, 4, 0, 3, 0, 2, 0, 1, 0, 1, 0, 2, 0, 3, 0, 4, 0, 5, 0, 6, 0, 6, 0, 5, 0, 4, 0, 3, 0, 2, 0, 1, 0},
        {0, 6, 0, 5, 0, 4, 0, 3, 0, 2, 0, 1, 0, 1, 0, 2, 0, 3, 0, 4, 0, 5, 0, 6, 0, 6, 0, 5, 0, 4, 0, 3, 0, 2, 0, 1, 0, 1, 0, 2, 0, 3, 0, 4, 0, 5, 0, 6},
        {1, 0, 2, 0, 3, 0, 4, 0, 5, 0, 6, 0, 6, 0, 5, 0, 4, 0, 3, 0, 2, 0, 1, 0, 1, 0, 2, 0, 3, 0, 4, 0, 5, 0, 6, 0, 6, 0, 5, 0, 4, 0, 3, 0, 2, 0, 1, 0},
        {0, 6, 0, 5, 0, 4, 0, 3, 0, 2, 0, 1, 0, 1, 0, 2, 0, 3, 0, 4, 0, 5, 0, 6, 0, 6, 0, 5, 0, 4, 0, 3, 0, 2, 0, 1, 0, 1, 0, 2, 0, 3, 0, 4, 0, 5, 0, 6}
    };


    int y=0;
    for(int f=0; f<6; f=f+2){
        for(int c=0; c<48; c=c+2){
            y=1+rand()%(6);
            matriz[f][c]=y;
        }
     }

    for(int f=1; f<6; f=f+2){
        for(int c=1; c<48; c=c+2){
            y=1+rand()%(6);
            matriz[f][c]=y;
        }
    }


    ui->graphicsView->setBackgroundBrush(Qt::darkGreen);
    ui->graphicsView->setScene(scene);

    ui->stackedWidget->setCurrentIndex(3);


    //Creación de objetos estáticos
    barra1=new QGraphicsRectItem(35, 70, 20, 670);
    scene->addItem(barra1);
    barra1->setBrush(Qt::yellow);

    barra2=new QGraphicsRectItem(1035, 70, 20, 670);
    scene->addItem(barra2);
    barra2->setBrush(Qt::yellow);

    int p=0;

    for(int f=0; f<6; f++){
        for(int c=0; c<48; c++){

            if(matriz[f][c]==1){

                bolas[p]= new esferas(75, 90, 0, 0, 0, 0, "blue");
                bolas[p]->setPos((c*20),(f*35));
                scene->addItem(bolas[p]);
            }

            if(matriz[f][c]==2){

                bolas[p]= new esferas(75, 90, 0, 0, 0, 0, "yellow");
                bolas[p]->setPos((c*20),(f*35));
                scene->addItem(bolas[p]);
            }

            if(matriz[f][c]==3){

                bolas[p]= new esferas(75, 90, 0, 0, 0, 0, "green");
                bolas[p]->setPos((c*20),(f*35));
                scene->addItem(bolas[p]);
            }

            if(matriz[f][c]==4){

                bolas[p]= new esferas(75, 90, 0, 0, 0, 0, "cyan");
                bolas[p]->setPos((c*20),(f*35));
                scene->addItem(bolas[p]);
            }

            if(matriz[f][c]==5){

                bolas[p]= new esferas(75, 90, 0, 0, 0, 0, "red");
                bolas[p]->setPos((c*20),(f*35));
                scene->addItem(bolas[p]);
            }

            if(matriz[f][c]==6){

                bolas[p]= new esferas(75, 90, 0, 0, 0, 0, "magenta");
                bolas[p]->setPos((c*20),(f*35));
                scene->addItem(bolas[p]);
            }
            p++;

        }
    }

}

void MainWindow::on_Inicio1_clicked()
{
/*
    int v=0;
    while (v<5){
    ui->graphicsView->scene()->destroyed(bolas[v]);
        //scene->removeItem(bolas[v]);
        v++;
    }
*/

   //removeItem(bolas);

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




    /*
        for(int v=0; v<312; v++){
            bolas[v]->hide();
        }
        */
}


void MainWindow::on_Inicio3_clicked()
{
    ui->graphicsView->setBackgroundBrush(Qt::darkGray);
    ui->graphicsView->setScene(scene);

    ui->stackedWidget->setCurrentIndex(0);
    barra1->hide();
    barra2->hide();

    /*
        for(int v=0; v<312; v++){
            bolas[v]->hide();
        }
        */
}

void MainWindow::on_Salir_clicked()
{
    this->close();
}

/*
void MainWindow::on_boton_esfera_pressed()
{

    // VARIABLES PARA LAS POSICIONES
    int x=0,y=0;

    // BUCLE WHILE PARA QUE SE ACTUALIZEN LAS CORDENADAS SIN CERRARSE EL PROGRAMA
   // while (1)
   // {
        Sleep(1000);

        // VARIABLE DE TIPO CURSOR
        POINT cursor;

        // OBTENEMOS LA POSICION Y LA GUARDAMOS EN LA VARIABLE DE ARRIBA
        GetCursorPos(&cursor);
        // ACTUALIZAMOS LOS VALORES
        x = cursor.x;
        y = cursor.y;

        // IMPRIMIMOS LA POSICION X & Y
        //printf("\r X = %i , Y = %i ", x , y);

        bola_lanz1->setX(x);
        bola_lanz1->setY(y);

   // }


}

void MainWindow::on_pushButton_pressed()
{
    ui->pushButton->setVisible(false);

    // VARIABLES PARA LAS POSICIONES
    int x=0,y=0;

    // BUCLE WHILE PARA QUE SE ACTUALIZEN LAS CORDENADAS SIN CERRARSE EL PROGRAMA
    //while (x<1000)
    //{

      //  Sleep(100);

        // VARIABLE DE TIPO CURSOR
        POINT cursor;

        // OBTENEMOS LA POSICION Y LA GUARDAMOS EN LA VARIABLE DE ARRIBA
        GetCursorPos(&cursor);
        // ACTUALIZAMOS LOS VALORES
        x = cursor.x;
        y = cursor.y;

        // IMPRIMIMOS LA POSICION X & Y
        //printf("\r X = %i , Y = %i ", x , y);

        bola_lanz1->setX(x);
        bola_lanz1->setY(y);
        bola_lanz1->setVX(3);

    //}
}
*/
