#include "floatvector.h"
#include <math.h>

FloatVector::FloatVector(FloatPoint point1, FloatPoint point2)
{
  FloatPoint point = point2 - point1;
  abscissa = point.x();
  ordinate = point.y();
}

FloatVector FloatVector::operator+(const FloatVector& vector)
{
  double xBuffer = abscissa + vector.abscissa;
  double yBuffer = ordinate + vector.ordinate;
  return FloatVector(xBuffer, yBuffer);
}

FloatVector FloatVector::operator-(const FloatVector& vector)
{
  double xBuffer = abscissa - vector.abscissa;
  double yBuffer = ordinate - vector.ordinate;
  return FloatVector(xBuffer, yBuffer);
}

double FloatVector::operator*(const FloatVector& vector)
{ // result = x_u * x_v + y_u * y_v
  double result = 0;
  result += abscissa * vector.abscissa;
  result += ordinate * vector.ordinate;
  return result;
}

double FloatVector::norm()
{
  return sqrt(abscissa * abscissa + ordinate * ordinate);
}

double FloatVector::getAngle(FloatVector v)
{
  FloatVector tmp(abscissa,ordinate);
  return acos(tmp * v/(this->norm()*v.norm()));
}