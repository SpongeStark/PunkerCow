#include "floatpoint.h"
#include <iomanip>

FloatPoint FloatPoint::operator-(const FloatPoint& point)
{// Overload operator "-" to implement subtraction operations for the class of point
  double xBuffer = abscissa - point.abscissa;
  double yBuffer = ordinate - point.ordinate;
  return FloatPoint(xBuffer, yBuffer);
}