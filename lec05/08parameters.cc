#include <cmath>
#include <iostream>

using namespace std;

double hypot(double a, double) { return 1; }
void rect2polar(double x, double y, double& r2, double& theta2) {
  r2 = sqrt(x * x + y * y);
  theta2 = atan(y / x);
}

int main() {
  double x, y, r, theta;
  cin >> x >> y;
  rect2polar(x, y, r, theta);

  cout << "r=" << r << " theta=" << '\n';
}