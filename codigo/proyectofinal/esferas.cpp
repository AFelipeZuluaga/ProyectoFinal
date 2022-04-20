#include "esferas.h"

#include <iostream>
#include <math.h>
#include <cmath>

using namespace std;

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>

esferas::esferas(double _x, double _y, double _vx, double _vy, double _ax, double _ay, string color)
{
    X=_x;
    Y=_y;
    VX=_vx;
    VY=_vy;
    VX=_ax;
    VY=_ay;
    Color=color;
}

QRectF esferas::boundingRect() const{
    return QRectF(X-20,Y-20,40,40);       //radio de 2
}


void esferas::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *){

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
double esferas::getX() const{
    return X;
}
double esferas::getY() const{
    return Y;
}
double esferas::getVY() const{
    return VY;
}
double esferas::getVX() const{
    return VX;
}
double esferas::getAY() const{
    return AY;
}
double esferas::getAX() const{
    return AX;
}
string esferas::getColor() const{
    return Color;
}


//funciones para los set
void esferas::setX(double value){
    X = value;
}
void esferas::setY(double value){
    Y = value;
}
void esferas::setVX(double value){
    VX = value;
}
void esferas::setVY(double value){
    VY = value;
}
void esferas::setAX(double value){
    AX = value;
}
void esferas::setAY(double value){
    AY = value;
}
void esferas::setColor(string value){
    Color = value;
}


//funciones de movimiento

void esferas::aceleracion()
{
    AX += 0;
    AY += 0;
    //ay = GRAV;
}

void esferas::velocidades()
// calcula las aceleraciones
{
    VX = VX + (AX);
    VY = VY + (AY);
}

void esferas::posiciones()
// calcula y Actualiza las posiciones
{
    X = X + (VX) + (0.5 * AX);
    Y = Y + (VY) + (0.5 * AY);

    // sin ajustar los cuadrantes
    // setPos((x/EX), (y/EY));

    // ajustando los cuadrantes
    //setPos((x/EX), (-y/EY));
}

