/**
 * @file floatpoint.h
 * @brief This is a class which record the coordinate of a point, with format double precision float
 */
#include <iostream>
using namespace std;

class FloatPoint
{
private:
  double x; // abscissa
  double y; // ordinate

public:
  FloatPoint(double,double);
  ~FloatPoint(){};

  // overload the operations
  bool operator==(const FloatPoint&);
  FloatPoint operator-(const FloatPoint&);
  friend ostream& operator<<(ostream&, const FloatPoint&);
};
