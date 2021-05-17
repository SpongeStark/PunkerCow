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
        double getArea();
        FloatPoint getCentroid();
        bool isInPolycon();
        void addPoint();
        void removePoint();
        void setBorder(double&,double&,double&,double&);
};

#endif