#include <iostream>
using namespace std;

uint32_t sum(uint32_t x[], int n) {
  cout << "sizeof(x)=" << sizeof(x) << '\n';
  // asking for sizeof array parameter is USELESS!! we will
  // always get size of pointer (8 bytes on 64 bit machine)
  for (int i = 0; i < 100; i++) cout << x[i];
}

/*
    2 errors: uninitialized variables, and going out of bounds
*/

int x;  // global variable (Is initialized to binary 0)

int main() {
  int a[10];                      // random garbage!!!
  uint32_t b[10] = {4, 9, 1, 7};  // rest are 0
  uint32_t c[10] = {0};           // all are 0
  uint32_t d[3] = {1, 2, 3};
  uint32_t big[1000];

  cout << "size of(a)" << sizeof(a) << '\n';
  cout << "size of(d)" << sizeof(d) << '\n';

  for (int i = 0; i < 10; i++) cout << a[i] << ' ';
  cout << '\n';

  cout << sum(d, 3) << '\n';
  cout << sum(b, 10) << '\n';
}
