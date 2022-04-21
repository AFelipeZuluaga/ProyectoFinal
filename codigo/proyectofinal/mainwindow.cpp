#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <stdlib.h>
#include <QDebug>


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


    moverA=false;
    moverS=false;
    moverD=false;
    moverZ=false;
    moverP=false;
    resorte=true;
    crear_bola_lanz1=false;
    timer=new QTimer();

    connect(timer,SIGNAL(timeout()),this,SLOT(juguemos()));
    connect(timer,SIGNAL(timeout()),this,SLOT(crear_bola_lanzada()));

    timer->start(10);

    scene=new QGraphicsScene(x,y,1090,770);

    QGraphicsView* view = new QGraphicsView(scene);
    ui->graphicsView->setBackgroundBrush(Qt::darkGray);

    ui->graphicsView->setScene(scene);

//    QPushButton* N1= new QPushButton();
//    scene->addItem(N1);



    ui->stackedWidget->setCurrentIndex(0);
    QRect Desktop = QApplication::desktop()->screenGeometry();


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Nivel1_clicked()
{
        timer->start(10);
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

    cout<<"crear_bola_lanz1: "<<crear_bola_lanz1<<endl;

    crear_bola_lanz1=true;

    cout<<"crear_bola_lanz1: "<<crear_bola_lanz1<<endl;


  //  juguemos();

}

void MainWindow::crear_bola_lanzada(){

    cout<<"No ha entrado a la creación de la bola lanzada."<<endl;
    if(crear_bola_lanz1){

        cout<<"Entró a la creación de la bola lanzada."<<endl;

        int aleat=1+rand()%(6);

        if(aleat==1){
            bola_lanz1= new esfera_lanzada(545, 650, 0, 0, 0, 0, "blue");
            scene->addItem(bola_lanz1);
        }

        if(aleat==2){
            bola_lanz1= new esfera_lanzada(545, 650, 0, 0, 0, 0, "yellow");
            scene->addItem(bola_lanz1);
        }

        if(aleat==3){
            bola_lanz1= new esfera_lanzada(545, 650, 0, 0, 0, 0, "green");
            scene->addItem(bola_lanz1);
        }

        if(aleat==4){
            bola_lanz1= new esfera_lanzada(545, 650, 0, 0, 0, 0, "cyan");
            scene->addItem(bola_lanz1);
        }

        if(aleat==5){
            bola_lanz1= new esfera_lanzada(545, 650, 0, 0, 0, 0, "red");
            scene->addItem(bola_lanz1);
        }

        if(aleat==6){

            bola_lanz1= new esfera_lanzada(545, 650, 0, 0, 0, 0, "magenta");
            scene->addItem(bola_lanz1);
        }

        crear_bola_lanz1=false;
    }
}

void MainWindow::juguemos(){


    int o=0;
    //while(moverA || moverD || moverS || moverZ){
  //      bolas[1]->setY(30.0);


    double posi=0;
    if(moverA)
    {
        bola_lanz1->setX(bola_lanz1->getX()-2.0);
        posi=bola_lanz1->getX();
        cout<<"posicion en x con A: "<<posi<<endl;
    }

    if(moverD)
    {
        bola_lanz1->setX(bola_lanz1->getX()+2.0);
        posi=bola_lanz1->getX();
        cout<<"posicion en x con D: "<<posi<<endl;
    }
    if(moverS)
    {
        bola_lanz1->setY(bola_lanz1->getY()-2.0);
        posi=bola_lanz1->getY();
        cout<<"posicion en x con S: "<<posi<<endl;
    }
    if(moverZ)
    {
        bola_lanz1->setY(bola_lanz1->getY()+2.0);
        posi=bola_lanz1->getY();
        cout<<"posicion en x con Zd: "<<posi<<endl;
    }

    if(moverP){
        //ax=-k*dx/m; ay=-k*dy/m
        //Inicio: bola:lanz1(545, 650)
        //Masa de borrador: 5.1g=0.0051kg
        //k de resorte: 13
        //k/m=13/0.0051kg=2549
        if(resorte){
        double dx=545-bola_lanz1->getX();
        double dy=650-bola_lanz1->getY();
        bola_lanz1->setAX(2549*dx); //2549
        bola_lanz1->setAY(2549*dy);
        bola_lanz1->setVX(0);
        bola_lanz1->setVY(0);
        resorte=false;
        posi=bola_lanz1->getX();
        cout<<"posicion en x: "<<posi<<endl;
        }

        bola_lanz1->aceleracion();
        bola_lanz1->velocidades();
        bola_lanz1->posiciones();

        posi=bola_lanz1->getX();
        cout<<"posicion en x: "<<posi<<endl;


        //Choque elástico con las barras
        if(bola_lanz1->collidesWithItem(barra1))
        {
            bola_lanz1->setVX(-bola_lanz1->getVX());
        }

        //Choque elástico con las barras
        if(bola_lanz1->collidesWithItem(barra2))
        {
            bola_lanz1->setVX(-bola_lanz1->getVX());
        }
/*
        //Choque con las bolas
        for(o=0; o<144; o++){
            if(bola_lanz1->collidesWithItem(bolas[o]))
            {
                bola_lanz1->setAX(0);
                bola_lanz1->setAY(0);
                bola_lanz1->setVX(0);
                bola_lanz1->setVY(0);
                }
            }
*/
        //Si bola lanzada sale del tablero, que vuelva a la posición inicial con los parámetros iniciales
        if(900<bola_lanz1->getY() || bola_lanz1->getY()<0){
            //Inicio: bola:lanz1(545, 650)
            bola_lanz1->setAX(0);
            bola_lanz1->setAY(0);
            bola_lanz1->setVX(0);
            bola_lanz1->setVY(0);
            bola_lanz1->setX(545);
            bola_lanz1->setY(650);
            moverP=false;
        }

        //Choque con las bolas
      /*  for(int o=0; o<144; o++){
            if(bola_lanz1->collidesWithItem(bolas[o]))
            {
                moverP=false;
                if(bolas[o]->isVisible()){
                    bolas[o]->hide();
                }
            }
            }
*/

        if(moverA){
            moverP=false;
        }


        }


   // }


/*
    if(kbhit()){
        char tecla= getch();
        //gotoxy(x,y);printf(" ");
        if(tecla =='a') bola_lanz1->setX(bola_lanz1->getX()-7.0);
        if(tecla =='s') bola_lanz1->setY(bola_lanz1->getY()-7.0);
        if(tecla =='d') bola_lanz1->setX(bola_lanz1->getX()+7.0);
        if(tecla =='z') bola_lanz1->setY(bola_lanz1->getY()+7.0);

        //gotoxy(x,y);printf("*");
    }
*/

}

void MainWindow::on_Nivel2_clicked()
{
    timer->start(10);
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
    timer->start(10);

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
    ui->graphicsView->setBackgroundBrush(Qt::darkGray);
    ui->graphicsView->setScene(scene);

    ui->stackedWidget->setCurrentIndex(0);

    barra1->hide();
    barra2->hide();

    bola_lanz1->hide();

/*
    for(int v=0; v<312; v++){
        bolas[v]->hide();
    }
    */
}

void MainWindow::on_Inicio2_clicked()
{
    ui->graphicsView->setBackgroundBrush(Qt::darkGray);
    ui->graphicsView->setScene(scene);

    ui->stackedWidget->setCurrentIndex(0);
    barra1->hide();
    barra2->hide();


    bola_lanz1->hide();

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

    bola_lanz1->hide();

    /*
        for(int v=0; v<312; v++){
            bolas[v]->hide();
        }
        */
}

void MainWindow::keyPressEvent(QKeyEvent *ev)
{
            timer->start(10);
    if(ev->key()==Qt::Key_A)
    {
        moverA=true;
       // bola_lanz1->setX(bola_lanz1->getX()-7.0);
    }
    else if(ev->key()==Qt::Key_S)
    {
        moverS=true;
    }
    else if(ev->key()==Qt::Key_Z)
    {
        moverZ=true;
    }
    else if(ev->key()==Qt::Key_D)
    {
        moverD=true;
    }
    else if(ev->key()==Qt::Key_P)
    {
        moverP=true;
    }
}

void MainWindow::keyReleaseEvent(QKeyEvent *ev)
{        timer->start(10);
    if(ev->key()==Qt::Key_A)
    {
        moverA=false;
    }
    else if(ev->key()==Qt::Key_S)
    {
        moverS=false;
    }
    else if(ev->key()==Qt::Key_D)
    {
        moverD=false;
    }
    else if(ev->key()==Qt::Key_Z)
    {
        moverZ=false;
    }
    else if(ev->key()==Qt::Key_P)
    {
        //moverP=false;
    }
}

void MainWindow::on_Salir_clicked()
{
    this->close();
            timer->stop();
}
