#include <iostream>
#include <cstdint>
using namespace std;

int f(int a);

/*int f(int a) {
  uint32_t x = 2;
  uint32_t y = 5;
  uint32_t a[10] = {0};
  x = x + 9;
  y = y & 10; // 1010
  arr[3] = 22;
  return 19;
}
*/

int main() {
  int a;
  cin >> a;
  int y = f(a);
  cout << y;
}