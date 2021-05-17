#include "floatpolygon.h"

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
}