#ifndef ESFERA_LANZADA_H
#define ESFERA_LANZADA_H

//#define g -9.8

#include <QGraphicsItem>
#include <QPainter>

class esfera_lanzada : public QGraphicsItem
{
private:
    double X;
    double Y;
    double VX;
    double VY;
    double AX;
    double AY;
public:
    esfera_lanzada();
    esfera_lanzada(double _x, double _y, double _vx, double _vy, double _ax, double _ay);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    double getX() const;
    double getY() const;
    double getVX() const;
    double getVY() const;
    double getAX() const;
    double getAY() const;

    void setX(double value);
    void setY(double value);
    void setVX(double value);
    void setVY(double value);
    void setAX(double value);
    void setAY(double value);


    // Funciones mvto
    void aceleracion();
    void velocidades();
    void posiciones();

};

#endif // ESFERA_LANZADA_H
