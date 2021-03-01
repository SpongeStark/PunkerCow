#include <iostream>
#include "floatpoint.h"
using namespace std;

int main(int argc, char* agrv[]){
  
  cout << "Hello World!" << endl;
  testFloatPoint();
  return 0;
}

void testFloatPoint()
{
  FloatPoint point1(2.1, 3);
  FloatPoint point2(2, 5);
  cout << point2 - point1 << endl;
}