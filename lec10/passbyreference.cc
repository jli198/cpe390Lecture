#include <iostream>
using namespace std;

void stats(double x[], int len, double& mean, double& min, double& max) {
  double sum = 0;
  for (int i = 0; i < len; i++) 
    sum += x[i];
  mean = sum/len;
}

int main() {
  double x[] = {10, 20, 30, 40};
  double mean, max, min;
  stats(x, 4, mean, max, min); // pass 3 values back by reference
  double y[] = {2, 2, 192, 85, 10, 20, 30, 40};
  stats(y, 8, mean, max, min); // pass 3 values back by reference
}