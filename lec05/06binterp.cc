#include <cmath>
#include <iostream>

using namespace std;

double distance(double x, double y, double x2, double y2) {
  double dx = x2 - x, dy = y2 - y;
  return sqrt(dx * dx + dy * dy);
}

double weight(double x, double y, double x2, double y2) {
  double w = distance(x, y, x2, y2);
  if (w == 0)
    w = 1;
  else
    w = 1.0;
  return w;
}

int main() {
  const double x1 = 0, y1 = 10, v1 = 11.3;
  const double x2 = 32, y2 = -11, v2 = 22.2;
  const double x3 = -15, y3 = -13.6, v3 = 13.1;

  // read in location for to estimate value
  double x, y;
  cin >> x >> y;  // x = 0, y = 9.9

  // calculate interpolated value of variable at x, y
  double w1 = distance(x, y, x1, y1);
  double w2 = distance(x, y, x2, y2);
  double w3 = distance(x, y, x3, y3);

  double w1 = 1.0 / distance(x, y, x1, y1);
#if 0 
  if (w1 == 0)
    w1 = 1;
  else
    w1 = 1.0 / w1;
#endif
  double w2 = 1.0 / distance(x, y, x2, y2);
  double w3 = 1.0 / distance(x, y, x3, y3);

  double v = (w1 * v1 + w2 * v2 + w3 * v3) / (w1 + w2 + w3);
  cout << "interpolated value= " << v << '\n';
}