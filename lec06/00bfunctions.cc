#include <iostream>
#include <cmath>
using namespace std;

int add(int a, int b) { 
  return a + b; 
}

/* void f() {
  kdsakfkfkdfd 
    ekfkfsdkfdf 
    fefkefkefek 
    afdakfdfk 
  for (int i = 1; i < 1000000; i++)
} */

/*
advantages of functions
1. don't rewrite code (faster? less maintenance)
if copy code n times, then fix one
2. one monumental program is VERY HARD to debug
3. 
*/

double hypot(double a, double b);

void rect2polar(double x, double y, double& r, double& theta) {
  r = sqrt(x * x + y * y);
  theta = atan2(y, x);
  x = 99;
}

int main() {
  /// write 10,000 lines in main 
  cout << (5) << '\n'; // can be optimized, inlined
  //cout << hypot(3, 4);  // cannot be optimized, compiler does not know

  double x, y, r, theta;
  cin >> x >> y;
  rect2polar(x, y, r, theta);

  cout << "r= " << r << " theta= " << theta << '\n';

  // f(); f(); f();
}