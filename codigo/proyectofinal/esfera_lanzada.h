#ifndef ESFERA_LANZADA_H
#define ESFERA_LANZADA_H

#define grav -9.8
#define dt 0.001

#include <QGraphicsItem>
#include <QPainter>

using namespace std;

#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>

class esfera_lanzada : public QGraphicsItem
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
    esfera_lanzada();
    esfera_lanzada(double _x, double _y, double _vx, double _vy, double _ax, double _ay, string color);
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

#endif // ESFERA_LANZADA_H
