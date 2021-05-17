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
  double x, y;
  vector<FloatPoint> polygon;

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
	
  


  return 0;
}



