#include <immintrin.h>
#include <cmath>
#include <iostream>
using namespace std;

double slow_dot_product(const double a[], const double b[], int n) {
  double answer = 0.0;
  for(int i = 0; i < n; ++i)
    answer += a[i]*b[i];
  return answer;
}

double dot_product(const double a[], const double b[], int n) {
  __m256d sum = _mm256_set_pd(0.0, 0.0, 0.0, 0.0);

  /* Add up partial dot-products in blocks of 256 bits */
  for(int i = 0; i < n; i += 4) {
    __m256d x = _mm256_load_pd(a+i); // load 4 doubles in burst
    __m256d y = _mm256_load_pd(b+i); // same
    __m256d z = _mm256_mul_pd(x, y); // multiply each corresponding
    sum = _mm256_add_pd(sum, z); // add them in parallel
  }
  __m256d temp = _mm256_hadd_pd(sum, sum); // add each half
  __m128d sum_high = _mm256_extractf128_pd(temp, 1); // pull out each half
  __m128d sum_low = _mm256_castpd256_pd128(temp);
  __m128d result = _mm_add_pd(sum_high, sum_low); // add two halves
  return ((double*) &result) [0];
}

double benchmarkSlowDotProduct(const double a[], const double b[], int n, int numIterations) {
  double sum = 0;
  for (int i = 0; i < numIterations; i++)
    sum += slow_dot_product(a, b, n);
  return sum;
}

double benchmarkAVXDotProduct(const double a[], const double b[], int n, int numIterations) {
  double sum = 0;
  for (int i = 0; i < numIterations; i++)
    sum += slow_dot_product(a, b, n);
  return sum;
}

const char* equalityTest(double a, double b) {
  return a == b ? "Passed" : "Failed";
}
template<typename Func>
void bench(const char msg[], Func f)