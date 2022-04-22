
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
    actualiza=false;
    borra_bolas=false;


    timer=new QTimer();

    connect(timer,SIGNAL(timeout()),this,SLOT(juguemos()));
    connect(timer,SIGNAL(timeout()),this,SLOT(crear_bola_lanzada()));
    connect(timer,SIGNAL(timeout()),this,SLOT(Actualizar()));

   // timer->start(33);

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
        timer->start(33);


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

            if(matriz1[f][c]==1){

                bolas[p]= new esferas(75, 90, 0, 0, 0, 0, "blue");
                bolas[p]->setPos((c*20),(f*35));
                scene->addItem(bolas[p]);
            }

            if(matriz1[f][c]==2){

                bolas[p]= new esferas(75, 90, 0, 0, 0, 0, "yellow");
                bolas[p]->setPos((c*20),(f*35));
                scene->addItem(bolas[p]);
            }

            if(matriz1[f][c]==3){

                bolas[p]= new esferas(75, 90, 0, 0, 0, 0, "green");
                bolas[p]->setPos((c*20),(f*35));
                scene->addItem(bolas[p]);
            }

            if(matriz1[f][c]==4){

                bolas[p]= new esferas(75, 90, 0, 0, 0, 0, "cyan");
                bolas[p]->setPos((c*20),(f*35));
                scene->addItem(bolas[p]);
            }

            if(matriz1[f][c]==5){

                bolas[p]= new esferas(75, 90, 0, 0, 0, 0, "red");
                bolas[p]->setPos((c*20),(f*35));
                scene->addItem(bolas[p]);
            }

            if(matriz1[f][c]==6){

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


    crear_bola_lanz1=true;



  //  juguemos();

}

void MainWindow::crear_bola_lanzada(){

    if(crear_bola_lanz1){

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

void MainWindow::Actualizar(){

    if(actualiza){

        int i=0, j=0,r=0;

    //    for (r=0 ; r<5 ; r++)
        //{
            bola_lanz1->aceleracion();
            bola_lanz1->velocidades();
            bola_lanz1->posiciones();
       // }

        actualiza=false;
    }

    ui->lcdNumber->display(puntuacion);

}

void MainWindow::juguemos(){


    double posi=0;


    //for(r=0; r<20; r++){
    if(moverA)
    {
        bola_lanz1->setX(bola_lanz1->getX()-2.0);
        posi=bola_lanz1->getX();
        bola_lanz1->setVX(0);
        bola_lanz1->setVY(0);
        bola_lanz1->setAX(0);
        bola_lanz1->setAY(0);
        bola_lanz1->setY(bola_lanz1->getY());
        actualiza=true;
    }

    if(moverD)
    {
        bola_lanz1->setX(bola_lanz1->getX()+2.0);
        posi=bola_lanz1->getX();
        bola_lanz1->setVX(0);
        bola_lanz1->setVY(0);
        bola_lanz1->setAX(0);
        bola_lanz1->setAY(0);
        bola_lanz1->setY(bola_lanz1->getY());
    }
    if(moverS)
    {
        bola_lanz1->setY(bola_lanz1->getY()-2.0);
        posi=bola_lanz1->getY();
        bola_lanz1->setVX(0);
        bola_lanz1->setVY(0);
        bola_lanz1->setAX(0);
        bola_lanz1->setAY(0);
        bola_lanz1->setX(bola_lanz1->getX());
    }
    if(moverZ)
    {
        bola_lanz1->setY(bola_lanz1->getY()+2.0);
        posi=bola_lanz1->getY();
        bola_lanz1->setVX(0);
        bola_lanz1->setVY(0);
        bola_lanz1->setAX(0);
        bola_lanz1->setAY(0);
        bola_lanz1->setX(bola_lanz1->getX());
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
        }

        actualiza=true;
/*
        for(int i=0; i<5; i++){
        bola_lanz1->aceleracion();
        bola_lanz1->velocidades();
        bola_lanz1->posiciones();
        }
*/
        posi=bola_lanz1->getX();


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

        //Choque con las bolas
        /*
        for(o=0; o<900; o++){
            if(bola_lanz1->collidesWithItem(bolas[o]))
            {
                bola_lanz1->setAX(0);
                bola_lanz1->setAY(0);
                bola_lanz1->setVX(0);
                bola_lanz1->setVY(0);
                }
            }
        */

        ///Choque
        ///
        double posx= bola_lanz1->getX();
        double posy= bola_lanz1->getY();
        int posx_matr= 0;
        int posy_matr= 0;
        int num_bola= 0;
        string color1;
        string color2;

        cout<<"posicion en y: "<<posy<<endl;
        cout<<"posicion en y de la matriz: "<<posy_matr<<endl;


        if(posy<280){
            posx_matr= ((posx-75)/40);
            posy_matr= ((posy-90)/35);

            cout<<"Estamos dentro!!!!"<<endl;
             cout<<"posx_matr"<<posx_matr<<endl;
              cout<<"posy_matr"<<posy_matr<<endl;

              //bola_lanz1->setColor("cyan");



              num_bola=24*posy_matr+posx_matr;

              cout<<"num_bola: "<<num_bola<<endl;

             color1=bola_lanz1->getColor();
             cout<<"color1"<<color1<<endl;

             if(bola_lanz1->getColor()=="blue"){
                 cout<<"Si reconoce el color. "<<endl;
                 cout<<"numero de la matriz: "<<matriz1[posy_matr][(posx_matr*2)];
                 if(matriz1[posy_matr][(posx_matr*2)]==1){

                     num_bola=48*posy_matr+posx_matr;
                  //   bolas[num_bola]->setAY(-9.8);
                     bola_lanz1->setVX(-bola_lanz1->getVX());
                     bola_lanz1->setVY(-bola_lanz1->getVY());
                     bola_lanz1->setAX(0);
                     bola_lanz1->setAY(0);
                     cout<<"Reconoce el 6"<<endl;

                     puntuacion++;

                                 }
             }


             if(bola_lanz1->getColor()=="yellow"){
                 cout<<"Si reconoce el color. "<<endl;
                 cout<<"numero de la matriz: "<<matriz1[posy_matr][(posx_matr*2)];
                 if(matriz1[posy_matr][(posx_matr*2)]==2){

                     num_bola=48*posy_matr+posx_matr;
                  //   bolas[num_bola]->setAY(-9.8);
                     bola_lanz1->setVX(-bola_lanz1->getVX());
                     bola_lanz1->setVY(-bola_lanz1->getVY());
                     bola_lanz1->setAX(0);
                     bola_lanz1->setAY(0);
                     cout<<"Reconoce el 6"<<endl;

                     puntuacion++;

                                 }
             }


             if(bola_lanz1->getColor()=="green"){
                 cout<<"Si reconoce el color. "<<endl;
                 cout<<"numero de la matriz: "<<matriz1[posy_matr][(posx_matr*2)];
                 if(matriz1[posy_matr][(posx_matr*2)]==3){

                     num_bola=48*posy_matr+posx_matr;
                  //   bolas[num_bola]->setAY(-9.8);
                     bola_lanz1->setVX(-bola_lanz1->getVX());
                     bola_lanz1->setVY(-bola_lanz1->getVY());
                     bola_lanz1->setAX(0);
                     bola_lanz1->setAY(0);
                     cout<<"Reconoce el 6"<<endl;

                     puntuacion++;

                                 }
             }

            // ui->lcdNumber->display(puntuacion);


             if(bola_lanz1->getColor()=="cyan"){
                 cout<<"Si reconoce el color. "<<endl;
                 cout<<"numero de la matriz: "<<matriz1[posy_matr][(posx_matr*2)];
                 if(matriz1[posy_matr][(posx_matr*2)]==4){

                     num_bola=48*posy_matr+posx_matr;
                  //   bolas[num_bola]->setAY(-9.8);
                     bola_lanz1->setVX(-bola_lanz1->getVX());
                     bola_lanz1->setVY(-bola_lanz1->getVY());
                     bola_lanz1->setAX(0);
                     bola_lanz1->setAY(0);
                     cout<<"Reconoce el 6"<<endl;

                     puntuacion++;

                                 }
             }


             if(bola_lanz1->getColor()=="red"){
                 cout<<"Si reconoce el color. "<<endl;
                 cout<<"numero de la matriz: "<<matriz1[posy_matr][(posx_matr*2)];
                 if(matriz1[posy_matr][(posx_matr*2)]==5){

                     num_bola=48*posy_matr+posx_matr;
                  //   bolas[num_bola]->setAY(-9.8);
                     bola_lanz1->setVX(-bola_lanz1->getVX());
                     bola_lanz1->setVY(-bola_lanz1->getVY());
                     bola_lanz1->setAX(0);
                     bola_lanz1->setAY(0);
                     cout<<"Reconoce el 6"<<endl;

                     puntuacion++;

                                 }
             }


             if(bola_lanz1->getColor()=="magenta"){
                 cout<<"Si reconoce el color. "<<endl;
                 cout<<"numero de la matriz: "<<matriz1[posy_matr][(posx_matr*2)];
                 if(matriz1[posy_matr][(posx_matr*2)]==6){

                     num_bola=48*posy_matr+posx_matr;
                  //   bolas[num_bola]->setAY(-9.8);
                     bola_lanz1->setVX(-bola_lanz1->getVX());
                     bola_lanz1->setVY(-bola_lanz1->getVY());
                     bola_lanz1->setAX(0);
                     bola_lanz1->setAY(0);
                     cout<<"Reconoce el 6"<<endl;

                     puntuacion++;


                                 }
             }




        actualiza=true;

        }
/////


        choca=true;

        //Si bola lanzada sale del tablero, que vuelva a la posición inicial con los parámetros iniciales
        if(900<bola_lanz1->getY() || bola_lanz1->getY()<-20){
            //Inicio: bola:lanz1(545, 650)
            crear_bola_lanz1=true;
            moverP=false;
        }
    }
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
  //  }
}

void MainWindow::Chocar(){

    /*
    if(choca){
        double posx= bola_lanz1->getX();
        double posy= bola_lanz1->getY();
        int posx_matr= 0;
        int posy_matr= 0;
        int num_bola= 0;

        cout<<"posicion en y: "<<posy<<endl;
        cout<<"posicion en y de la matriz: "<<posy_matr<<endl;


        if(posy<165){
            posx_matr= (posx/35)-90;
            posy_matr= (posy/35)-90;
        }

        if(bola_lanz1->getColor()=="blue"){
            if(matriz1[posy_matr][posx_matr]==1){
                num_bola=48*posy_matr+posx_matr;
                bolas[num_bola]->setAY(-9.8);
                bola_lanz1->setX(0);
                bola_lanz1->setY(0);
                bola_lanz1->setVX(0);
                bola_lanz1->setVY(0);
                bola_lanz1->setAX(0);
                bola_lanz1->setAY(-1);
            }

        }


        if(bola_lanz1->getColor()=="magenta"){
            if(matriz1[posy_matr][posx_matr]==6){
                num_bola=48*posy_matr+posx_matr;
                bolas[num_bola]->setAY(-9.8);
                bola_lanz1->setX(0);
                bola_lanz1->setY(0);
                bola_lanz1->setVX(0);
                bola_lanz1->setVY(0);
                bola_lanz1->setAX(0);
                bola_lanz1->setAY(-1);
            }

        }


        if(bola_lanz1->getX())



        choca=false;
    }
    */
}

void MainWindow::on_Nivel2_clicked()
{
    timer->start(33);


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

            if(matriz2[f][c]==1){

                bolas[p]= new esferas(75, 90, 0, 0, 0, 0, "blue");
                bolas[p]->setPos((c*20),(f*35));
                scene->addItem(bolas[p]);
            }

            if(matriz2[f][c]==2){

                bolas[p]= new esferas(75, 90, 0, 0, 0, 0, "yellow");
                bolas[p]->setPos((c*20),(f*35));
                scene->addItem(bolas[p]);
            }

            if(matriz2[f][c]==3){

                bolas[p]= new esferas(75, 90, 0, 0, 0, 0, "green");
                bolas[p]->setPos((c*20),(f*35));
                scene->addItem(bolas[p]);
            }

            if(matriz2[f][c]==4){

                bolas[p]= new esferas(75, 90, 0, 0, 0, 0, "cyan");
                bolas[p]->setPos((c*20),(f*35));
                scene->addItem(bolas[p]);
            }

            if(matriz2[f][c]==5){

                bolas[p]= new esferas(75, 90, 0, 0, 0, 0, "red");
                bolas[p]->setPos((c*20),(f*35));
                scene->addItem(bolas[p]);
            }

            if(matriz2[f][c]==6){

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
    timer->start(33);

    int y=0;
    for(int f=0; f<6; f=f+2){
        for(int c=0; c<48; c=c+2){
            y=1+rand()%(6);
            matriz1[f][c]=y;
        }
     }

    for(int f=1; f<6; f=f+2){
        for(int c=1; c<48; c=c+2){
            y=1+rand()%(6);
            matriz1[f][c]=y;
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

            if(matriz1[f][c]==1){

                bolas[p]= new esferas(75, 90, 0, 0, 0, 0, "blue");
                bolas[p]->setPos((c*20),(f*35));
                scene->addItem(bolas[p]);
            }

            if(matriz1[f][c]==2){

                bolas[p]= new esferas(75, 90, 0, 0, 0, 0, "yellow");
                bolas[p]->setPos((c*20),(f*35));
                scene->addItem(bolas[p]);
            }

            if(matriz1[f][c]==3){

                bolas[p]= new esferas(75, 90, 0, 0, 0, 0, "green");
                bolas[p]->setPos((c*20),(f*35));
                scene->addItem(bolas[p]);
            }

            if(matriz1[f][c]==4){

                bolas[p]= new esferas(75, 90, 0, 0, 0, 0, "cyan");
                bolas[p]->setPos((c*20),(f*35));
                scene->addItem(bolas[p]);
            }

            if(matriz1[f][c]==5){

                bolas[p]= new esferas(75, 90, 0, 0, 0, 0, "red");
                bolas[p]->setPos((c*20),(f*35));
                scene->addItem(bolas[p]);
            }

            if(matriz1[f][c]==6){

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
    timer->stop();

    ui->graphicsView->setBackgroundBrush(Qt::darkGray);
    ui->graphicsView->setScene(scene);

    ui->stackedWidget->setCurrentIndex(0);

    barra1->hide();
    barra2->hide();

    bola_lanz1->hide();
    centro->hide();

    borra_bolas=true;
}


void MainWindow::Borrar_bolas(){
    if (borra_bolas){
        timer->stop();

        for(int i=0; i<144; i++){

            bolas[i]->hide();
        }
        borra_bolas=false;
    }
/*
    scene->removeItem(bolas[0]);
    scene->removeItem(bolas[1]);
    scene->removeItem(bolas[2]);
    scene->removeItem(bolas[3]);
*/

    /*
    for(int i=0; i<144; i++){


        scene->removeItem(bolas[i]);
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
    timer->start(33);
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
{        timer->start(33);
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


