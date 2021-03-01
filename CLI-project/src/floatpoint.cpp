#include "floatpoint.h"
#include <iomanip>

FloatPoint::FloatPoint(double x,double y)
{
  this->x = x;
  this->y = y;
}

bool FloatPoint::operator==(const FloatPoint& point)
{
  // initialize the result
  bool result = true;
  // check abscissa
  result = result && (this->x == point.x);
  // check ordinate
  result = result && (this->y == point.y);
  // return the comparison result
  return result;
}

FloatPoint FloatPoint::operator-(const FloatPoint& point)
{
  double xBuffer = this->x - point.x;
  double yBuffer = this->y - point.y;
  return FloatPoint(xBuffer, yBuffer);
}

ostream& operator<<(ostream& output, const FloatPoint& point)
{
  output << fixed;
  output << "(";
  output << setprecision(2) << point.x << " , ";
  output << setprecision(2) << point.y << ")";
  return output;
}