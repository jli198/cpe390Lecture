#include <iostream>
using namespace std;
int main() {
  int a = 2;
  int b = 3;
  int c = a << b; //00000000000000000000000000000000010000 = 16
  // lsl w0, w1 <-- immediate mode
  // lsl w0, #3

  uint64_t d = 0xFEEDF001U >> 2; // 11111110111011011111000000000001
  // 00111111

  int64_t d2 = 0xFEEDF001 >> 2; //
  //

  int32_t e = 7 >> 1;
  int32_t e2 = -7 >> 1;

  cout << e2 << '\n';
  // asr x0, #1

  //2s-complement arithmetic
  int8_t e3 = 0b10010011;
  //
  //
}