#include <iostream>
#include "floatpoint.h"
using namespace std;

void testFloatPoint();

int main(int argc, char* agrv[]){
  
  cout << "Hello World!" << endl;
  testFloatPoint();
  return 0;
}

void testFloatPoint()
{
  cout << "Test the class : FloatPoint" << endl;
  FloatPoint point1(2.1, 3);
  FloatPoint point2(2, 5);
  cout << "Test << and -" << endl;
  cout << point2 - point1 << endl;

  FloatPoint point3(2,5);
  cout << "Test == (true)" << endl;
  if (point2 == point3)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  cout << "Test == (false)" << endl;
  if (point1 == point3)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}