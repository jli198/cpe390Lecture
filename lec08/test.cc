#include <iostream>
using namespace std;

int add(int a, int b) { 
  return a + b;
}

int sub(int a, int b) { 
  return a - b; 
}

int mul(int a, int b) { 
  return a * b;
}

int divide(int a, int b) { 
  return a / b;
}

int mul_add(int a, int b, int c) { 
  return a*b + c; 
}

int add_mul(int a, int b, int c) { 
  return (a+b)* c;
}

uint64_t add(uint64_t a, uint64_t b) { 
  return a + b;
}

bool is_prime(uint64_t n) { 
  for (uint64_t i = 2; i < n; i++) {
    if (n % i == 0) 
      return false;
    return true;
  }
 }