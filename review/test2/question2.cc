// (20 points) Identify what operations C++ will optimize following code into:
// a.
uint64_t optimized2(uint64_t a) {
  return a * 16; // what arm instruction(s) does that turn into? 2**4 = 16
  /*
  lsl x0, x0, 4
  ret
  */
}

//b.
uint64_t optimized3(uint64_t a) {
  return a / 32; // what arm instruction(s) does this turn into? 2**5 = 32
  /*
  lsr x0, x0, 5
  ret
  */
}

//c.
uint64_t optimized4(uint64_t a) {
  return a % 64; // what arm instruction(s) does this turn into?
  // eor x0, x0, 63 OR and x0, x0, 63
}

//d.
uint64_t optimized4() {
  return 5 + 6; // what arm instruction(s)does this turn into?
  // mov x0, #11 (right answer)
  /* not great, but would accept
  mov x1, #6
  add x0, x1, #5
  */
}