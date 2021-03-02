/**
 * @file floatpoint.h
 * @brief This is a class which record the coordinate of a point, with format double precision float
 */
#ifndef FLOATPOINT_H
#define FLOATPOINT_H

#include <iostream>
#include "floatcoordinate.h"

class FloatPoint : public FloatCoordinate
{
public:
  FloatPoint(double x,double y):FloatCoordinate(x,y){}
  ~FloatPoint(){}

  // overload the operations
  FloatPoint operator-(const FloatPoint&);
};

#endif