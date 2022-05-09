/* (10 points) Write equivalent ARM assembler to implement this C++ function
uint64_t f(uint64_t a, uint64_t b, uint64_t c) {
  return ((a << 2) & (b >> 2)) ^ c;
}
  uint64_t v = f(3, 9, 18); v = 18

  ^ means XOR

  ((3 * 4) & (9 / 4)) EOR 18 (12 & 2) EOR 18

  1100 & 0010 = 0000 -> 00000 ^ 10010 = 10010 -> 10010 = 16 + 2 = 18
 */

  add x0, x0, lsl 1
  add x1, x1, lsr 1
  add x1, x2
  eor x1, x3
  mov x0, x1
  ret