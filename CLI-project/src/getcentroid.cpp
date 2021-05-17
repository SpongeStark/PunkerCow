#include <iostream>
#include <vector>
#include "floatpoint.h"
#include "floatvector.h"

using namespace std;

double triangleArea(FloatPoint pointA, FloatPoint pointB, FloatPoint pointC){
    double area = 0;
    FloatVector VectorAB(pointA,pointB);
    FloatVector VectorAC(pointA,pointC);
    area=abs(VectorAB*VectorAC)/2;
    return area;
}

double getArea(const vector<FloatPoint> &polygon){
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

FloatPoint getCentroid(double areaPolygon,vector<FloatPoint> &polygon){
    double Gx=0,Gy=0;
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