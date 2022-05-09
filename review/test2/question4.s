// (20 points) Write AARCH function that takes array of 64-bit integers and replaces each element by its square. For example:
/*
uint64_t a[] = {3, 4, 5};
squareme(a, 3); // a is now 9, 16, 25
 */

// in x0 = address of array a[], x1 = length
1:
  ldr x2, [x0], 8 // loads x2 from x0 then advances by 8 bytes auto-increment
  mul x2, x2, x2 // x2 = x2 * x2
  str x2, [x0], 8 // stores x2 into x0 then auto-increment by 8
  sub x1, x1, 1 // count down from len to 0
  cmp x1, 0 // if (x1 != 0)
  bne 1b // branch != back to 1:
  mov x0, x2 // x0 = x2
  ret