/*
This part is the prototype of the algorithm,
which can be compiled and run separately,
for reference only when checking errors,
and has nothing to do with the main program
*/
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<vector>

#define EPSILON 0.000001

using namespace std;

struct point
{
	double x , y ;
	point()
    {
        x = 0.0;
        y = 0.0;
    }
    point(double dx, double dy)
    {
        x = dx;
        y = dy;
    }

};
int cas , n ;
double Area( point p0 , point p1 , point p2 )
{
	double area = 0 ;
	area =  p0.x * p1.y + p1.x * p2.y + p2.x * p0.y - p1.x * p0.y - p2.x * p1.y - p0.x * p2.y;
	return area / 2 ;
}

bool IfInPol(double x,double y, const vector<point> &pol)
{
	double sum=0,theta;
	int n=pol.size();
	for(int i=0,j=n-1; i<n; j=i++){
		point GSi=point(pol[j].x-x,pol[j].y-y);
		point GSi1=point(pol[i].x-x,pol[i].y-y);
		double dGSi=sqrt(pow(GSi.x,2)+pow(GSi.y,2));
		double dGSi1=sqrt(pow(GSi1.x,2)+pow(GSi1.y,2));
		double cosG=(GSi.x*GSi1.x+GSi.y*GSi1.y)/(dGSi*dGSi1);
		double DetGS=GSi.x*GSi1.y-GSi.y*GSi1.x;
		if(DetGS>=0) theta= acos(cosG);
		else theta=-acos(cosG);
		sum+=theta;
	}
	if(abs(sum-0)<=EPSILON) return false;
	else return true;
}

int main ()
{
	freopen("input.txt","r",stdin);
	point p0 , p1 , p2 ;
	double sum_x , sum_y , sum_area , area;
	vector<point> pol;
	scanf ( "%d" , &cas ) ;
	while ( cas -- )
	{
		pol.clear();
		sum_x = sum_y = sum_area = 0 ;
		scanf ( "%d" , &n ) ;
		scanf ( "%lf%lf" , &p0.x , &p0.y ) ;
		pol.push_back(point(p0.x,p0.y));
		
		scanf ( "%lf%lf" , &p1.x , &p1.y ) ;
		pol.push_back(point(p1.x,p1.y));
		
		for ( int i = 2 ; i < n ; ++ i )
		{
			scanf ( "%lf%lf" , &p2.x , &p2.y ) ;
			pol.push_back(point(p2.x,p2.y));
			
			area = Area(p0,p1,p2) ;
			sum_area += area ;
			sum_x += (p0.x + p1.x + p2.x) * area ;
			sum_y += (p0.y + p1.y + p2.y) * area ;
			p1 = p2 ;
		}
		printf("%lf\n",sum_area);
		double g_x , g_y ;
		g_x=sum_x / sum_area / 3;
		g_y=sum_y / sum_area / 3;
		printf ( "%lf %lf\n" , g_x , g_y ) ;
		if(IfInPol(g_x, g_y, pol)){
			puts("in pol");
		}else puts("not in pol");
	}
	return 0 ;
}