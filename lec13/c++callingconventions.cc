#include <iostream>
using namespace std;
//w0     w0

int f(int a);

//x0            w0          x1
uint64_t g(int a, uint64_t b);

//0x7ffffffyyyyyyyyy

//d0               x0          x1            w2         d0
double h(uint64_t a, uint64_t b[], uint32_t len, double x);

int main() {
  int y = f(3);
}