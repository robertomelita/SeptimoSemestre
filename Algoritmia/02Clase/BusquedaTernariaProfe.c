#include <math.h>
#include <iostream>
#include <algorithm>

double f (double x, double xh, double yh, double xa, double ya); 
#define EPS 1E-9

 int main () {
 double xh, yh, xa, ya, right, left;
 std::cin >> xh >> yh;
 std::cin >> xa >> ya;
 if (xh < xa){
               std::swap(xh, xa) ; std::swap(yh, ya) ;}

 left = xh;
 right = xa;
 while( fabs ( right-left ) > EPS) {
 double pl = (2*left + right ) / 3.;
 double pr = ( left + 2*right ) / 3.;
 if ( f (pl , xh, yh, xa, ya) < f (pr , xh, yh, xa, ya)-EPS)
 right = pr ;
 else left = pl ;
 }
std:: cout << f (( left+right ) /2. , xh, yh, xa, ya) << std::endl ;
std:: cout << sqrt (  (xh-xa)*(xh-xa) +  (yh+ya*(yh+ya)) ) << std::endl ;
 return 0;
 }
double f (double x, double xh, double yh, double xa, double ya) {
return sqrt (  (xh-x)*(xh-x) + (yh*yh )) + sqrt (  (xa-x)*(xa-x) +  (ya*ya )) ;}
