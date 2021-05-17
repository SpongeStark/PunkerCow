#include "floatpolygon.h"
#define EPSILON 0.000001

FloatPolygon::FloatPolygon(){}

double triangleArea(FloatPoint pointA, FloatPoint pointB, FloatPoint pointC){
    double area = 0;
    FloatVector VectorAB(pointA,pointB);
    FloatVector VectorAC(pointA,pointC);
    double theta=VectorAB.getAngle(VectorAC);
    return 0.5*VectorAB.norm()*VectorAC.norm()*sin(theta);
}
double FloatPolygon::getArea()
{
    double sumArea=0;
    FloatPoint point0=polygon[0];
    FloatPoint point1=polygon[1];
    for (int i = 2; i < polygon.size(); i++)
    {
        FloatPoint point2=polygon[i];
        sumArea+=triangleArea(point0, point1, point2);
        point1=point2;
    }
    return sumArea;
}

FloatPoint FloatPolygon::getCentroid()
{
    double Gx=0,Gy=0,areaPolygon=this->getArea();
    int numPoint=polygon.size();
    for(int i = 0, j = numPoint-1; i < numPoint ; j=i++)
    {
        Gx+=(polygon[j].x()+polygon[i].x())*(polygon[j].x()*polygon[i].y()-polygon[i].x()*polygon[j].y());
        Gy+=(polygon[j].y()+polygon[i].y())*(polygon[j].x()*polygon[i].y()-polygon[i].x()*polygon[j].y());
    }
    Gx/=(6*areaPolygon);
    Gy/=(6*areaPolygon);
    FloatPoint pointCentroid(Gx,Gy);
    return pointCentroid;
}

bool FloatPolygon::isInPolycon(FloatPoint g)
{
    double sum=0,theta;
    int numPoint=polygon.size();
    for(int i=0, j=numPoint-1; i < numPoint; j=i++)
    {
        FloatVector vectorGA(g,polygon[j]);
        FloatVector vectorGB(g,polygon[i]);
        double Det=vectorGA.x()*vectorGB.y()-vectorGA.y()*vectorGB.x();
        theta=(Det<0?-1:1)*acos(vectorGA*vectorGB/(vectorGA.norm()*vectorGB.norm()));
        sum+=theta;
    }
    if(abs(sum-0)<=EPSILON) return false;
	else return true;
}

bool FloatPolygon::addPoint(FloatPoint point)
{
    for(int i=0; i<polygon.size(); i++)
    {
        if(point.x()==polygon[i].x()&&point.y()==polygon[i].y())
        {
            return false;
        }
        else
        {
            polygon.push_back(point);
            return true;
        }
    }
}

bool FloatPolygon::removeLastPoint()
{
    if(polygon.empty())
    {
        return false;
    }
    else
    {
        polygon.pop_back();
        return true;
    }
}

void FloatPolygon::clearPolygon()
{
    polygon.clear();
}

void FloatPolygon::assignBorder(double& xMin,double& xMax,double& yMin,double& yMax)
{
    if(polygon.empty())
    {
        xMin=0; xMax=0; yMin=0; yMax=0;
    }
    else
    {
        double xMinNow=0x7f, xMaxNow=-0x7f, yMinNow=0x7f, yMaxNow=-0x7f;
        for(int i=0; i<polygon.size(); i++)
        {
            double xNow=polygon[i].x(),yNow=polygon[i].y();
            if(xNow<xMinNow) xMinNow=xNow;
            if(xNow>xMaxNow) xMaxNow=xNow;
            if(yNow<yMinNow) yMinNow=yNow;
            if(yNow>yMaxNow) yMaxNow=yNow;
        }
        xMin=xMinNow; xMax=xMaxNow; yMin=yMinNow; yMax=yMaxNow;
    }
}