/**
 * @file floatvector.h
 * @brief This is a class to record a vector
 * 
 */
#ifndef FLOATVECTOR_H
#define FLOATVECTOR_H

#include "floatcoordinate.h"
#include "floatpoint.h"

class FloatVector : public FloatCoordinate
{
public:
  FloatVector(double x, double y):FloatCoordinate(x,y){}
  FloatVector(FloatPoint, FloatPoint);
  ~FloatVector(){}

  // overload of operator
  FloatVector operator+(const FloatVector&);
  FloatVector operator-(const FloatVector&);
  double operator*(const FloatVector&);

  // member functions
  double norm(); // get the norm of this vector

  double getAngle(FloatVector);
};

#endif