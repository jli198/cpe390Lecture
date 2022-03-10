add x0, x1, #2 // x0 = x1 + 2 | pc = pc + 4

bl f // pc = pc + 4, lr = pc, pc = f         lc is link register

// you should know how to compile C++ program, look at call
// and figure out what function is called
// g++ -O2 -S main.cc

// AARCH64
// how many integer registers are there? x0 ... x30
// w0 to w30 are low half of each x register <-- sets high end to 0
// x31 is zero

//x30 = SP stack pointer
//x29 = LR link register
//x28 = frame pointer? probably won't cover
// use x0-x27 maybe x29-x30

// for practical purposes x0...x27

//floating point
//32 128-bit vector registers
//q0..q31 <- 128 bit registers maybe covering that
//d0 is low half of q0
//s0 is low half of d0
// d = a*b+c
// ARM Neon 2 double per instruction
// ARM Neon 4 float per instruction

// Intel AVX2 = 256 bit AVX512 = 512 bits

  .global f
f:
  mov w0, w5 // w0 = w5 high part of w0 = 0
  // x0 = 0x00000000 [whatever is in w0]
  mov w0, 0 // 00000000000000000000000000000000 32 zeros
  sub w0, w0, 1 // 11111111111111111111111111111111  - 1 32 ones

  // 0000000000000000000000000000000011111111111111111111111111111111 - 1

    // sxtw x0, w0
  // 1111111111111111111111111111111111111111111111111111111111111111 - 1

  // 1111111111111111111111111111 -1 
  // 0000000000000001111111111111

  mov x2, #254 // immediate mode <- move value into register (number built into instruction)
  add x3, x4, x5 // x3 = x4 + x5 register mode
  add x3, x5, #7 // x3 = x5+7 (immediate mode)

// MATH: Load INTO REGISTER THEN DO MATH SEPARATELY

  // address modes
  ldr x3, [x4] // x3 = load from memory at location x4 (indexed)
  ldr x3, [x4], #8 // x3 = load from memory[x4], then x4 = x4 + 8 (post increment)

  // this is pseudo instruction
  ldr x5, = 0x0123456789ABCDEF
  //this really happens: ldr x5, [pc, #20 ] <-- #20 is # of rows left in code until branch data is reached:

  //we dont't write this ldr x5, [pc, ####] // pc relative
  ldr x5, [x4, #8] load x5 = memory[x4+8] // x4 is unchanged

  ldr x5, =0x0123456789ABCDEF
  mov x5, 255

  // for every ldr there is corresponding str (store)

  str x3, [x0, #4] // wrtie x3 to location x0+4

  ret
data: // 64 bits
  .dword 0x0123456789ABCDEF

  // integer x, y, z given location in memory x0
loadxyz:
  ldr x3, [x0]
  ldr x4, [x0, #8]
  ldr x5, [x0, #16]

  // double x, y, z given location in memory x0
loadxyzdouble:
  ldr d0, [x0]
  ldr d1, [x0, #8]
  ldr d2, [x0, #16]

  // load 128 bits into quad vector register?
  ldr q0, [x0]
