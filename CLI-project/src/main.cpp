#include <iostream>
#include "floatpoint.h"
#include "floatvector.h"
#include<vector>
#include "floatpolygon.h"

using namespace std;

void testFloatPoint();
void testVector();

int main()
{
  
  int nb_piquets;
	double sum_x, sum_y, sum_area, area;
  double x, y;
  vector<FloatPoint> polygon;

  Flag:
  cout << "Donnez le nombre de piquets ce que vous voulez bouger:"<<endl;
  cin >> nb_piquets;
  while(cin.fail())
  {
    cin.clear();
    cin.ignore();
    cout <<"Erreur!Retapez le nombre SVP:" << endl;
    cin >> nb_piquets;
  }
  
  if(nb_piquets > 50 || nb_piquets <= 0)
  {
      cout<<"le nombre est null"<<endl;
      goto Flag;
  }

  FloatPoint* piquet;  

  for( int i=0; i<nb_piquets; i++ )
  {
    cout<<"saisir le piquet " << i << ":" << endl;
    cout << "   le abscissa:" << endl;
    cin >> x;
    cout << "   le ordinate:" << endl;
    cin >> y;
    
    piquet = new FloatPoint(x,y);
    polygon.push_back(*piquet);
  }
	






  testFloatPoint();
  testVector();
  testPolygon();
  return 0;
}

void testFloatPoint()
{
  cout  <<  "Test the class : FloatPoint"  <<  endl;
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

void testVector()
{
  cout << "Test the class : FloatVector" << endl;
  FloatVector vector1(2.34, 4.56);
  cout << "Test <<" << endl;
  cout << vector1 << endl;
  FloatPoint point1(2.1, 3);
  FloatPoint point2(2, 5);
  cout << "Test constructor" << endl;
  FloatVector vector2(point1, point2);
  cout << vector2 << endl;
  cout << "Test + and -" << endl;
  cout << "1+2 : " << vector1 + vector2 << endl;
  cout << "1-2 : " << vector1 - vector2 << endl;
  cout << "Test *" << endl;
  cout << "1*2 : " << vector1 * vector2 << endl;
}

void testPolygon()
{

}