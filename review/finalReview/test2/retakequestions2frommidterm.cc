#include <iostream>
using namespace std;
  //x0
uint64_t optimized2(uint64_t a) {
  return a*16; // lsl x0, x0, #4 (lsl x0, #4 is acceptable in only 32 bit register only)
}

uint64_t optimized3(uint64_t a) {
  return a/32; // lsr x0, x0, #5
}

uint64_t optimized2(uint64_t a) {
  return a%32; // and x0, x0, #31 (right answer, 1 clock)
  /*
  crazy, but works
  mov x1, x0
  lsr x1, x1, #5
  lsl x1, x1, #5
  sub x0, x0, x1
*/
}

uint64_t optimized4(uint64_t a) {
  return a % 64; // what arm instruction(s) does this turn into? ror 63 eor x0, x0, 63
}

uint64_t optimized4(uint64_t a) {
  return 5+6; // mov x0, #11 (right answer)
}
  // not great, but we would accept:
  // mov x1, #6
  // add x0, x1, #5