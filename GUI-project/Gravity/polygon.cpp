#include "polygon.h"
#include "vectorf.h"

bool Polygon::addPoint(QPointF point)
{
    if(!_Points.contains(point))
    {
        _Points.append(point);
        return true;
    }
    else
    {
        return false;
    }
}

bool Polygon::removeLastPoint()
{
    if(_Points.empty())
    {
        return false;
    }
    else
    {
        _Points.removeLast();
        return true;
    }
}

void Polygon::clearAllPoints()
{
    _Points.clear();
}

int Polygon::countPoints()
{
    return _Points.size();
}

QPointF Polygon::pointAt(int index)
{
    if(index > _Points.size() - 1)
        return QPointF(0,0);
    return _Points[index];
}

void Polygon::assignBorder(double *xMin, double *xMax, double *yMin, double *yMax)
{
    if(_Points.isEmpty())
    {
        *xMin = -1; *xMax = 1;
        *yMin = -1; *yMax = 1;
    }
    else if(1 == _Points.size())
    {
        *xMin = _Points[0].x()-1, *xMax = _Points[0].x()+1;
        *yMin = _Points[0].y()-1, *yMax = _Points[0].y()+1;
    }
    else
    {
        double xMinNow = _Points[0].x(), xMaxNow = _Points[0].x();
        double yMinNow = _Points[0].y(), yMaxNow = _Points[0].y();
        for(int i=1; i<_Points.size(); i++)
        {
            double xNow = _Points[i].x(), yNow = _Points[i].y();
            if(xNow<xMinNow) xMinNow=xNow;
            if(xNow>xMaxNow) xMaxNow=xNow;
            if(yNow<yMinNow) yMinNow=yNow;
            if(yNow>yMaxNow) yMaxNow=yNow;
        }
        *xMin=xMinNow;
        *xMax=xMaxNow;
        *yMin=yMinNow;
        *yMax=yMaxNow;
    }
}

double Polygon::getArea()
{
    if(_Points.size() <= 2)
        return 0;
    double sumArea = 0;
    QPointF point0 = _Points[0];
    QPointF point1 = _Points[1];
    for (int i = 2; i < _Points.size(); i++)
    {
        QPointF point2 = _Points[i];
        sumArea += triangleArea(point0, point1, point2);
        point1 = point2;
    }
    return sumArea;
}

QPointF Polygon::getGravity()
{
    double Gx = 0, Gy = 0;
    double areaPolygon = this->getArea();
    int numPoint = _Points.size();
    for(int i = 0, j = numPoint-1; i < numPoint ; j=i++)
    {
        Gx += (_Points[j].x() + _Points[i].x()) * \
                (_Points[j].x() * _Points[i].y() - _Points[i].x() * _Points[j].y());
        Gy += (_Points[j].y() + _Points[i].y()) * \
                (_Points[j].x() * _Points[i].y() - _Points[i].x() * _Points[j].y());
    }
    Gx /= (6 * areaPolygon);
    Gy /= (6 * areaPolygon);
    QPointF pointCentroid(Gx,Gy);
    return pointCentroid;
}

bool Polygon::isPointInPolygon(QPointF g)
{
    double sum = 0;
    int numPoint=_Points.size();
    for(int i=0, j=numPoint-1; i < numPoint; j=i++)
    {
        VectorF vectorGA(g,_Points[j]);
        VectorF vectorGB(g,_Points[i]);
        double Det = vectorGA.x() * vectorGB.y() - vectorGA.y() * vectorGB.x();
        double sign = Det < 0 ? -1 : 1;
        //double theta = sign * acos(vectorGA * vectorGB / (vectorGA.norm() * vectorGB.norm()));
        double theta = sign * VectorF::getAngle(vectorGA, vectorGB);
        sum+=theta;
    }
//    if(abs(sum-0)<=EPSILON)
//        return false;
//    else
//        return true;
    return !(abs(sum-0) < EPSILON);
}

double Polygon::triangleArea(QPointF pointA, QPointF pointB, QPointF pointC)
{
    VectorF VectorAB(pointA,pointB);
    VectorF VectorAC(pointA,pointC);
    double theta = VectorF::getAngle(VectorAB, VectorAC);
    return 0.5 * VectorAB.norm() * VectorAC.norm() * sin(theta);
}
