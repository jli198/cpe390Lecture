  // add elements of array of 32-bit integers
  // x0 = array
  // x1 = len
countdown:
  mov x3, #0 // sum = 0
1:
  ldr w2, [x0], #4 // read in and advance by 4 bits
  add x3, x3, x2
  sub x1, x1, #1
  cmp x1, #0
  bgt 1b
  mov x0, x3
  ret

/* add elements of array of uint32_t
sum:
  mov x3, #0 // sum = 0

1:
  ldr __, _____, #4 // read in and advance by 4 bits
  add x3, x3, __
  ___ x1, x1, #1
  bgt __
  mov __, x3
  ret
 */

sumsq:
  mov x3, #0 // sum = 0
  mov x3, #0 // i = 0
1:
  ldr __, [x0, x4 lsl #2] // read in array element
  mul x2, x2, __
  add x3, x3, __
  ___ x4, x4, #1
  cmp x4, __
  __ 1b
  mov __, x3
  ret

/*
1:
  ldr __, [___] // read in and 
  mul x2, x2, __
  add x3, x3, __
  ___ x4, x4, #1
  cmp x4, __
  __ 1b
  mov __, x3
  ret
*/

// wrtie function that replaces every element of array by 2* value
// do not use multiply for speed
//x0 = pointer to array of uint64_t
//x1 = length of array

doubleme:
  add x3, x3, x3 // multiply x3 by 2...
  lsl x3, x3, #1 // ditto

// wrtie function that replaces every element of array by 5* value
// do not use multiply for speed
//x0 = pointer to array of uint64_t
//x1 = length of array
fiveme:
  add x3, x3, x3, lsl #2 // x3 + 4 *x3 = 5*x3 (x3 does not  change)


  // add only even numbers in array starting at x0 with length x1
  // example: arr[] = {2, 3, 9, 1, 6, 5, 7, 8}
  // sumeven(arr, 8) should return 2+6+8=16
sumeven:
  tst x3, #1
  addeq x2, x2, x3