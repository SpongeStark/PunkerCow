#include "floatpolygon.h"
#define EPSILON 0.000001

FloatPolygon::FloatPolygon(){}

double FloatPolygon::triangleArea(FloatPoint pointA, FloatPoint pointB, FloatPoint pointC){
    // SABC= 1/2 * |AB| * |AC| * sin(A)
    double area = 0;
    FloatVector VectorAB(pointA, pointB);
    FloatVector VectorAC(pointA, pointC);
    double theta = VectorAB.getAngle(VectorAC);
    return 0.5 * VectorAB.norm() * VectorAC.norm() * sin(theta);
}
double FloatPolygon::getArea()
{
    //Because the polygon is irregular, it is divided into multiple triangles for calculation
    //One point is fixed, and then two points of the polygon are taken to form a triangle
    double sumArea = 0;
    FloatPoint point0 = polygon[0];
    FloatPoint point1 = polygon[1];
    for (int i = 2; i < polygon.size(); i++)
    {
        FloatPoint point2 = polygon[i];
        sumArea += triangleArea(point0, point1, point2);
        point1 = point2;
    }
    return sumArea;
}

FloatPoint FloatPolygon::getCentroid()
{
    //The calculation of the centroid coordinate is completed according to the given formula
    double Gx=0, Gy=0, areaPolygon= this->getArea();
    int numPoint = polygon.size();
    for(int i = 0, j = numPoint-1; i < numPoint ; j = i++)
    {
        Gx += (polygon[j].x() + polygon[i].x()) * (polygon[j].x() * polygon[i].y() - polygon[i].x() * polygon[j].y());
        Gy += (polygon[j].y() + polygon[i].y()) * (polygon[j].x() * polygon[i].y() - polygon[i].x() * polygon[j].y());
    }
    Gx /= (6 * areaPolygon);
    Gy /= (6 * areaPolygon);
    FloatPoint pointCentroid(Gx, Gy);
    return pointCentroid;
}

bool FloatPolygon::isInPolycon(FloatPoint g)
{
    double sum = 0, theta;
    int numPoint = polygon.size();
    // Calculate theta using the given formula
    for(int i = 0, j = numPoint-1; i < numPoint; j = i++)
    {
        FloatVector vectorGA(g, polygon[j]);
        FloatVector vectorGB(g, polygon[i]);
        double Det = vectorGA.x() * vectorGB.y() - vectorGA.y() * vectorGB.x();
        theta = ( Det < 0 ? -1 : 1 ) * acos(vectorGA * vectorGB / (vectorGA.norm() * vectorGB.norm()));
        sum += theta;
    }
    // The role of EPSILON is to reduce floating point errors and residuals
    if(abs(sum - 0) <= EPSILON) return false;
	else return true;
}

bool FloatPolygon::addPoint(FloatPoint point)
{
    bool flag=true;
    for(int i=0; i<polygon.size(); i++)
    {
        if(point.x()==polygon[i].x()&&point.y()==polygon[i].y())
        {
            // Cannot add duplicate points
            flag=false;
        }
    }
    if(flag)
    {
        polygon.push_back(point);
        return true;
    }else return false;
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
        xMin=xMax=yMin=yMax=0;
    }
    else
    {
        double xMinNow=polygon[0].x(), xMaxNow=polygon[0].x(), yMinNow=polygon[0].y(), yMaxNow=polygon[0].y();
        for(int i=1; i<polygon.size(); i++)
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