#include "esfera_lanzada.h"

esfera_lanzada::esfera_lanzada(double _x, double _y, double _vx, double _vy, double _ax, double _ay, string color)
{
    X=_x;
    Y=_y;
    VX=_vx;
    VY=_vy;
    VX=_ax;
    VY=_ay;
    Color=color;
}

QRectF esfera_lanzada::boundingRect() const{
    return QRectF(X-20,Y-20,40,40);       //radio de 20
}


void esfera_lanzada::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *){

    if(Color=="yellow"){
        painter->setBrush(Qt::yellow);
    }
    if(Color=="red"){
        painter->setBrush(Qt::red);
    }
    if(Color=="blue"){
        painter->setBrush(Qt::blue);
    }
    if(Color=="green"){
        painter->setBrush(Qt::green);
    }
    if(Color=="magenta"){
        painter->setBrush(Qt::magenta);
    }
    if(Color=="cyan"){
        painter->setBrush(Qt::cyan);
    }
    painter->drawEllipse(boundingRect());
}


//funciones para los get
double esfera_lanzada::getX() const{
    return X;
}
double esfera_lanzada::getY() const{
    return Y;
}
double esfera_lanzada::getVY() const{
    return VY;
}
double esfera_lanzada::getVX() const{
    return VX;
}
double esfera_lanzada::getAY() const{
    return AY;
}
double esfera_lanzada::getAX() const{
    return AX;
}
string esfera_lanzada::getColor() const{
    return Color;
}


//funciones para los set
void esfera_lanzada::setX(double value){
    X = value;
}
void esfera_lanzada::setY(double value){
    Y = value;
}
void esfera_lanzada::setVX(double value){
    VX = value;
}
void esfera_lanzada::setVY(double value){
    VY = value;
}
void esfera_lanzada::setAX(double value){
    AX = value;
}
void esfera_lanzada::setAY(double value){
    AY = value;
}
void esfera_lanzada::setColor(string value){
    Color = value;
}

//funciones de movimiento

void esfera_lanzada::aceleracion()
{
    AX += 0;
    AY = AY+grav;           //ay: +
    //ay = GRAV;
}

void esfera_lanzada::velocidades()
// calcula las aceleraciones
{
    VX = VX + (AX)*dt;
    VY = VY + (AY)*dt;  //vy: +
}

void esfera_lanzada::posiciones()
// calcula y Actualiza las posiciones
{
    X = X + (VX) *dt+ (0.5 * AX)*dt*dt;
    Y = Y + (VY) *dt+ (0.5 * AY)*dt*dt;     //y:+, entonces baja

    // sin ajustar los cuadrantes
    // setPos((x/EX), (y/EY));

    // ajustando los cuadrantes
    //setPos((x/EX), (-y/EY));
}

