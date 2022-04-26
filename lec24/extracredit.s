// 6. add only odd numbers
_Z6sumoddPKmm:
// x0 = array
// x1 = length
  mov x2, #0 // sum = 0
1:
  ldr w3, [x0], #4
  tst w3, #1
  beq skip
  add x2, x2, #1
skip:
  subs x1, #1
  bne 1b
  mov x0, x2
  ret

/* 
7. (3 points extra credit) Write function in ARM assembler that takes single 64-bit integer
parameter and counts number of 1 bits 
*/
_Z9countonesm:
// x0=101010101010101010101010101001111001110010100
//    000000000000000000000000000000000000000000001
  mov x2, #0
  mov x3, 64
1:
  and x1, x0, #1 // x1 = x0 AND 1
  cmp x1, #0
  beq skip
  add x2, x2, #1
skip:
  lsr x0, x0, #1 // keep peeling off 1 bit at time
  subs x3, x3, #1
  bne 1b
  mov x0, x2
  ret

_Z9countonesm:
// x0=101010101010101010101010101001111001110010100
//    000000000000000000000000000000000000000000001
  mov x2, #0
1:
  and x1, x0, #1 // x1 = x0 AND 1
  add x2, x2, 1
  lsrs x0, x0, #1 // x0 = x0 >> 1 and set flags
  bne 1b
  mov x0, x2
  ret

