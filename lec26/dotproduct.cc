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





  
}