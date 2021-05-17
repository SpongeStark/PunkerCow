/**
 * @file floatpolygon.h
 * @brief This is a class to record a polygon
 * 
 */
#ifndef FLOATPOLYCON_H
#define FLOATPOLYCON_H

#include "floatcoordinate.h"
#include "floatpoint.h"
#include "floatvector.h"
#include <vector>

class FloatPolygon
{
    private:
        vector<FloatPoint> polygon;
    public:
        FloatPolygon();

        double getArea();
        FloatPoint getCentroid();
        bool isInPolycon(FloatPoint g);

        bool addPoint(FloatPoint point);
        bool removeLastPoint();
        void clearPolygon();
        void assignBorder(double& xMin,double& xMax,double& yMin,double& yMax);
};

#endif