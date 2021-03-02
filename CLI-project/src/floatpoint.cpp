#include "floatpoint.h"
#include <iomanip>

FloatPoint FloatPoint::operator-(const FloatPoint& point)
{
  double xBuffer = abscissa - point.abscissa;
  double yBuffer = ordinate - point.ordinate;
  return FloatPoint(xBuffer, yBuffer);
}