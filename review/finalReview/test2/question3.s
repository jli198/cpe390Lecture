// (20 points) Write AARCH 64 function that takes array of int and returns all elements ANDed together. For example:
/* 
  int a[] = {1, 2, 4};
  int y = andall(a, 3); // y = 0

  int b[] = {6, 12};
  y = andall(b, 2); // y = 4
*/

  // in x0 = address of array, x1 = length
  mov w3, 0
  mov w5, 0
1:
  ldr w2, x0, #4 // load x0 into w2 then autoincrement by 4
  ldr w4, x0
  and w5, w4, w2 
  sub w1, w1, 0
  cmp w1, 0
  bne 1b
  mov x0, w2 // x0 = w2
  ret