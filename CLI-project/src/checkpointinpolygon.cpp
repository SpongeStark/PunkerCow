//no use
#include <iostream>
#include <vector>
#include <cmath>
#include "floatpoint.h"
#include "floatvector.h"

#define EPSILON 0.000001

using namespace std;

bool checkPointInPolygon(FloatPoint G, const vector<FloatPoint> &polygon)
{
    double sum=0,theta;
    int numPoint=polygon.size();
    for(int i=0, j=numPoint-1; i < numPoint; j=i++)
    {
        FloatVector vectorGA(G,polygon[j]);
        FloatVector vectorGB(G,polygon[i]);
        double cosG=(vectorGA*vectorGB)/(sqrt(pow(vectorGA.x(),2)+pow(vectorGA.y(),2))*sqrt(pow(vectorGB.x(),2)+pow(vectorGB.y(),2)));
        double DetGAGB=vectorGA.x()*vectorGB.y()-vectorGA.y()*vectorGB.x();
        if(DetGAGB>=0) theta= acos(cosG);
        else theta=-acos(cosG);
        sum+=theta;
    }
    if(abs(sum-0)<=EPSILON) return false;
	else return true;
}