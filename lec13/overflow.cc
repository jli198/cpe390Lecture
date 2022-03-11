#include <iostream>
using namespace std;

int main() {
  uint16_t a = 1; // 00000000000000000001
  for (int i = 0; i < 20; i++) {
    a *= 2;
    cout << a << '\n';
  }
}