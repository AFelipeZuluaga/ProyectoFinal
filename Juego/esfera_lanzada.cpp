#include "esfera_lanzada.h"

esfera_lanzada::esfera_lanzada(double _x, double _y, double _vx, double _vy, double _ax, double _ay)
{
    X=_x;
    Y=_y;
    VX=_vx;
    VY=_vy;
    VX=_ax;
    VY=_ay;
}

QRectF esfera_lanzada::boundingRect() const{
    return QRectF(X-20,Y-20,40,40);       //radio de 20
}


void esfera_lanzada::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *){
    painter->setBrush(Qt::yellow);
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


//funciones de movimiento

void esfera_lanzada::aceleracion()
{
    AX += 0;
    AY += 0;
    //ay = GRAV;
}

void esfera_lanzada::velocidades()
// calcula las aceleraciones
{
    VX = VX + (AX);
    VY = VY + (AY);
}

void esfera_lanzada::posiciones()
// calcula y Actualiza las posiciones
{
    X = X + (VX) + (0.5 * AX);
    Y = Y + (VY) + (0.5 * AY);

    // sin ajustar los cuadrantes
    // setPos((x/EX), (y/EY));

    // ajustando los cuadrantes
    //setPos((x/EX), (-y/EY));
}

