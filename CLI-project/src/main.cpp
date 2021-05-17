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
  double area;
  vector<FloatPoint> polygon;
  bool isInPolygon;
  

  Flag:
  cout << "give the number of stakes which you want to move:" << endl;
  cin >> nb_piquets;
  while( cin.fail() )
  {
    cin.clear();
    cin.ignore();
    cout << "error!you can only give the number,please retry:" << endl;
    cin >> nb_piquets;
  }
  
  if( nb_piquets > 50 || nb_piquets <= 0 )
  {
      cout << "the number isn't in rage" << endl;
      goto Flag;
  }

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
    polygon.push_back(*piquet);
  }
	
    // area=getArea(polygon);
    // cout << "the area of polygon is:" << area << endl;
    
    // FloatPoint* centroid;
    // *centroid = getCentroid(area,polygon);
    // cout << "the centroid(center of gravity is)" << *centroid << endl; 

    // isInPolygon = checkPointInPolygon(*centroid,polygon);
    // if(isInPolygon)
    // {
    //   cout << "the cow is in the fence." <<endl; 
    // }
    //   cout << "watch out! the cow is out of the fence!" << endl;

  return 0;
}



