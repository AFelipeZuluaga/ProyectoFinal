#ifndef ESFERAS_H
#define ESFERAS_H

#include <QGraphicsItem>
#include <QPainter>

#include <iostream>
#include <math.h>
#include <cmath>

using namespace std;

#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>


class esferas:  public QGraphicsItem
{
private:
    double X;
    double Y;
    double VX;
    double VY;
    double AX;
    double AY;
    string Color;

public:
    esferas();
    esferas(double _x, double _y, double _vx, double _vy, double _ax, double _ay, string color);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    double getX() const;
    double getY() const;
    double getVX() const;
    double getVY() const;
    double getAX() const;
    double getAY() const;
    string getColor() const;

    void setX(double value);
    void setY(double value);
    void setVX(double value);
    void setVY(double value);
    void setAX(double value);
    void setAY(double value);
    void setColor(string value);


    // Funciones mvto
    void aceleracion();
    void velocidades();
    void posiciones();

};

#endif // ESFERAS_H
