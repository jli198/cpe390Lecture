  ldr x3, [x0]  //load mem loc x0
  ldr x4, [x0], #8  // load mem loc x0, x0 = x0+8 
  ldr x5, [x0, #8]  // load mem loc x0+8, x0 unchanged
  ldr x6, [x0, #8]! // x0=x0+8, then load mem loc x0

  str // (same as ldr but store)

  ldr w4, [x0]  // load 32 bit register from memory
  ldrb w5, [x0] // load 1 byte from memory (zero high bits)

  //C++ equivalents
  and // &
  eor // ^
  orr // |
  mvn  // (move and negate = NOT)  ~
  lsl // (logical shift left) <<
  lsr // (logical shift right)  >>

  add
  sub
  mul
  udiv

  //optimization

  // divide by power of 2 --> lsr
  // multiply by power of 2 --> lsl
  // mod by power of 2 --> AND with (n-1)

  // stack calls bl register calling convention ret
  // stack
  stp lr, x19, [sp, #-16]!
  ...
  ldp lr, x19, [sp], #16

  lsl x0, x0, #4
  lsl x0, #4  // <--- no longer allowed

  // wrong:
  ret x5

  // right
  mov x0, x5  // x0 holds return value
  ret 
