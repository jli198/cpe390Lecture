// (30 points) Complete all code so that it performs stated task
/*
a. Given x0 = destination array, x1 = source array, x2 = length
copy all elements from source to destination
*/
copy:
1:
  ldr x3, [x1]
  str x3, [x0]
  add x1, x1, 8 // x register = 64 bit so advance by 8 bytes. w register would be 32-bit so advance by 4 then
  add x0, x0, 8
  subs x2, x2, 1
  bne 1b
  ret

/*
b. Given: x0 = desintation array, x1 = source array, x2 = length
copy all elements from source to destination
*/
copy2:
1:
  ldr x3, [x1], 8 // x register = 64 bit so advance by 8 bytes. w register would be 32-bit so advance by 4 then
  str x3, [x0], 8
  sub x2, x2, 1
  cmp x2, 0
  bne 1b
  ret

/*
c. Given x0 = destination array, x1 = length
add one to each element
*/
addone:
  mov x2, #0
1:
  ldr x3, [x0, 8] // increment first x3 = [x0 + 8]
  add x3, x3, #1  // x3 = x3 + 1
  str x3, [x0, 8] // increment first x3 = [x0 + 8]
  add x2, x2, 1
  cmp x2, x1
  bne 1b
  ret

/*
d. Complete code showing how to call function and still return to function that called
*/
  stp lr, x0, [sp, #-16]!
  bl thefunction
  ldp lr, x0, [sp], #16
  ret