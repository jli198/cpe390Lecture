// (20 points)

#include <iostream>
#include <cmath>
using namespace std;

void dividebyRMS(double x[], int len) {
  int sq;
  int sum = 0;
  int rms;
  for (int i = 0; i < len; i++) {
    sq = x[i] * x[i];
    sum += sq;
  }
  rms = sqrt(sum);

  for (int i = 0; i < len; i++) {
    sq = x[i] * x[i];
    x[i] = sq/rms;
  }
}

int main() {
  double x[] = {10, 20, 30, 40};
  cout << dividebyRMS(x, 4); // calculate root-mean-square (square root of sum of squares)
  // then divide each element of x by that number. For example
  // rms = sqrt(10 ** 2 + 20 ** 2 + 30 ** 2 + 40 ** 2) and array should end up 10/rms, 20/rms, etc.
}