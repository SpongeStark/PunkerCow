/**
 * @file floatcoordinate.h
 * @brief This is a class which record a coordinate, with format double precision float
 */
#ifndef FLOATCOORDINATE_H
#define FLOATCOORDINATE_H

#include <iostream>

class FloatCoordinate
{
protected:
  double abscissa; // abscissa
  double ordinate; // ordinate

public:
  FloatCoordinate();
  FloatCoordinate(double,double);
  ~FloatCoordinate(){};

  // overload the operations
  bool operator==(const FloatCoordinate&);
  friend std::ostream& operator<<(std::ostream&, const FloatCoordinate&);

  // "get" method
  double x();
  double y();
};

#endif