#include <iostream>
#include "floatpoint.h"
#include "floatvector.h"
#include<vector>
#include "floatpolygon.h"

using namespace std;

int main()
{
  
  int nb_piquets;
  double x, y;
  
  //juge if the user input data correctly.
  Flag:
  cout << "give the number of stakes which you want to move(3-50):" << endl;
  cin >> nb_piquets;
  while( cin.fail() )
  {
    cin.clear();
    cin.ignore();
    cout << "error!you can only give the number,please retry:" << endl;
    cin >> nb_piquets;
  }
  
  if( nb_piquets > 50 || nb_piquets <= 2 )
  {
      cout << "the number isn't in rage" << endl;
      goto Flag;
  }

  //record coordinate of points
  FloatPolygon polygon;
  FloatPoint* piquet;

  for( int i=0; i<nb_piquets; i++ )
  {
    cout << "give the position of the stake " << i << ":" << endl;
    cout << "    the abscissa:" << endl;
    cin >> x;
    while( cin.fail() )
    {
      cin.clear();
      cin.ignore();
      cout << "error!you can only give the number,please retry:" << endl;
      cin >> x;
    }
    cout << "    the ordinate:" << endl;
    cin >> y;
    while( cin.fail() )
    {
      cin.clear();
      cin.ignore();
      cout << "error!you can only give the number,please retry:" << endl;
      cin >> y;
    }

    piquet = new FloatPoint(x,y);
    polygon.addPoint(*piquet);
  }
	
   
    //output the result 
    cout << "the area of polygon is:" << polygon.getArea() << endl;

    cout << "the centroid(center of gravity is)" << polygon.getCentroid() << endl; 

    if( polygon.isInPolycon( polygon.getCentroid() ) )
    {
      cout << "the cow is in the fence." <<endl; 
    }
      cout << "watch out! the cow is out of the fence!" << endl;

  return 0;
}



