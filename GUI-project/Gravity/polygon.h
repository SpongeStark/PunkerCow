#ifndef POLYGON_H
#define POLYGON_H

#include<QVector>
#include<QPointF>

#define EPSILON 0.000001 //precision

class Polygon
{
public:
    Polygon(){}

    bool addPoint(QPointF);
    bool removeLastPoint();
    void clearAllPoints();
    int countPoints();
    QPointF pointAt(int index);
    void assignBorder(double* xMin, double* xMax, double* yMin, double* yMax);
    double getArea();
    QPointF getGravity();
    bool isPointInPolygon(QPointF);

private:
    QVector<QPointF> _Points;
    //a tool for calculating the area of a triangle
    double triangleArea(QPointF,QPointF,QPointF);
};

#endif // POLYGON_H
