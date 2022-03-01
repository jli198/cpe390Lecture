  .global _Z3sumPKii
  // x0 = address of array
  // w1 = len
_Z3sumPKii:
  // for (int i = 0; i < n; i++)
  // x[i]
  mov w2, 0 // sum = 0
1: 
  ldr w3, [x0] // w3 = read memory location (x0, x0+1, x0+2, x0+3)
  add w2, w2, w3 // w2 = w2 + w3
  add x0, x0, 4 // advance to next int
  sub w1, w1, 1 //count
  cmp w1, 0
  bgt 1b
  ret