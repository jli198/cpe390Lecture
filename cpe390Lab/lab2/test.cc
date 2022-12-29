#include <iostream>
#include <math.h>
using namespace std;

double areaOfTriangle(double x1, double y1, double x2, double y2, double x3, double y3) {
  double a, b, c, s, area;
  a = sqrt((pow((x2-x1),2) + pow((y2-y1),2))); 
  b = sqrt((pow((x3-x2),2) + pow((y3-y2),2)));
  c = sqrt((pow((x3-x1),2) + pow((y3-y1),2)));
  s = 0.5*(a+b+c);

  return area = sqrt(s * (s-a) * (s-b) * (s-c));
}

int main() {
  cout << areaOfTriangle(0,0, 10,0, 10,5) << '\n'; // should be approx 25
  cout << areaOfTriangle(0.0,0.0, 5.2,3.0, 2.0,6.0) << '\n'; //should be approx 12
}