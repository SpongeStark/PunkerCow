#include "floatcoordinate.h"
#include <iomanip>

FloatCoordinate::FloatCoordinate()
  :abscissa(0),ordinate(0)
{ }

FloatCoordinate::FloatCoordinate(double x, double y)
{
  this->abscissa = x;
  this->ordinate = y;
}

bool FloatCoordinate::operator==(const FloatCoordinate& coordinate)
{
  // initialize the result
  bool result = true;
  // check abscissa
  result = result && (this->abscissa == coordinate.abscissa);
  // check ordinate
  result = result && (this->ordinate == coordinate.ordinate);
  // return the comparison result
  return result;
}

std::ostream& operator<<(std::ostream& output, const FloatCoordinate& coordinate)
{// So the output format is (a,b)
  output << std::fixed;
  output << "(";
  output << std::setprecision(2) << coordinate.abscissa << " , ";
  output << std::setprecision(2) << coordinate.ordinate << ")";
  return output;
}

double FloatCoordinate::x()
{// As the variables are protected, use function to get the value.
  return this->abscissa;
}

double FloatCoordinate::y()
{
  return this->ordinate;
}