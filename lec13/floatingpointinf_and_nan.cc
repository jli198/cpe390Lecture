#include <cmath>

int main() {
  float x = 1.0f; // floating point constant (literal)
  double d = 1.5; // 1.5 is double
  double d2 = 0.1f; // bottom half is garbage!

  int y = 1 / 0;

  double a = 1.0 / 0.0; // value is infinity (on gcc inf)
  double b = -1.0 / 0.0; // value is -infinity
  double c = a + 1; // still infinity
  double d = c*2; // still infinity
  double e = sqrt(d); // still infinity
  double f = a + b; // NOT ZERO NaN (we don't know)
  double g = 0.0 / 0.0; // NaN
  // if (something that didn't happen) {
  // double h = 0/0;
  //}
}