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
        std::vector<FloatPoint> polygon;
    public:
        FloatPolygon(); // Constructor

        double getArea(); // Calculate area
        FloatPoint getCentroid(); // Calculate the coordinate of centroid
        bool isInPolycon(FloatPoint g); // Determine whether the point is within the polygon

        double triangleArea(FloatPoint pointA, FloatPoint pointB, FloatPoint pointC);
        // Calculate the area of ​​a triangle, used when calculating the area of ​​a polygon
        
        bool addPoint(FloatPoint point);
        bool removeLastPoint();
        void clearPolygon();
        // Record the maximum and minimum values ​​of the coordinates to ensure that the graphics are displayed correctly on the screen
        void assignBorder(double& xMin,double& xMax,double& yMin,double& yMax);
};

#endif