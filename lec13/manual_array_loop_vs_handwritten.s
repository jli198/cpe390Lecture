  // assume x4 points to start of array, w1 = length

1:
  ldr x3, [x4], #8 // x3 = read(x4) and increment
  add x0, x0, x3 // sum = sum + a[i]
  subs w1, w1, #1 // count down
  bgt 1b