#include <iostream>

using namespace std;

uint32_t sum(int a, int b) {
 uint32_t x = 0;
 for (int i = a; i <= b; i++) {
     x = x + i; // x += i;
 }
 return x;
 }

int main() {
    uint32_t s = sum(5, 10); // 5 + 6 + 7 + 8 + 9 + 10
    cout << s << '\n';
    s = sum(1, 1000000);
    cout << s << '\n';
}