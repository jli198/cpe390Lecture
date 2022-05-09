// (20 points) Write each function called in main
#include <iostream>
using namespace std;

uint64_t sumofproducts(uint64_t a) {
  uint64_t prod = 1;
  uint64_t sum = 0;
  for (int i = 1; i < a; i++) {
    prod = i * (i+1);
    sum = sum + prod;
  }
  return sum;
}

int main() {
  // compute sum of products of adjacent numbers up to n
  cout << sumofproducts(7) << '\n';
  // should compute 1*2 + 2*3 + 3*4 + 4*5 + 5*6 +6*7 = 112
}