#include <cmath>
#include <cstdint>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

float mystery_sum1(int n) {
  float s = 0;
  for (int i = 1; i <= n; i++) s += (1.0 / (i * i));
  cout << s << '\n';
  cout << sqrt(6 * s) << '\n';

  return 0;
}

float mystery_sum1corrected(int n) {
  float s = 0;
  for (int64_t i = 1; i <= n; i++) s += (1.0 / (i * i));
  // s += (1.0/((float)i * (float)i))
  cout << "s = " << s << '\n';
  cout << "sqrt(6 * s) = " << sqrt(6 * s) << '\n';

  return 0;
}

// part 2:
float mystery_sum2corrected(int n) {
  float s = 0;
  for (int64_t i = n; i >= 1; i--) s += (1.0 / (i * i));
  cout << "s = " << s << '\n';
  cout << "sqrt(6 * s) = " << sqrt(6 * s) << '\n';

  return 0;
}

int main() {
  // test cases for question 2:
  cout << "answers for question 2:-------------------------" << endl;
  // input variable n = 100 for both functions,
  for (int n = 100; n <= 10000000; n *= 2) {
    float s1 = mystery_sum1(n);
    float s2 = mystery_sum1corrected(n);
    float s3 = mystery_sum2corrected(n);
    printf("%9d     %9.7lf %9.7lf %9.7lf %9.7lf %9.7lf %9.7lf\n", n, s1,
           sqrt(6 * s1), s2, sqrt(6 * s2), s3, sqrt(6 * s3));
#if 0
                cout << n << '\t' <<
                    s1 << '\t' << sqrt(6*s1) << '\t' <<
                    s2 << '\t' << sqrt(6*s2) << '\t' <<
                    s3 << '\t' << sqrt(6*s3) <<
                    '\n';
#endif
  }
  cout << "\n\n";
}