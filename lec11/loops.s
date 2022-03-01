  .global f
  // w0 = n
f:
  mov w1, w0 // w1 = n for (int i = n; i > 0; i--)
  mov w0, 0 // sum = 0
1.
  add w0, w0, w1 // sum = sum + i
  sub w1, w1, 1 // w1 = w1 - 1
  cmp w1, 0 // is w1 = 0?
  bne 1b //if not equal, go to 1b | b = GNU (could be called 1 loop) | 1-99. is temprorary can jump to adjacent branches only
  ret

  .global f2
  // w0 = n
f2:
  mov w1, w0 // w1 = n for (int i = 0; i < n; i++)
  mov w0, 0 // sum = 0
  mov w2, 1 // for (int i = 1; i <= n; i++)
loop2:
  add w0, w0, w2 // sum = sum + i
  add w2, w2, 1 // w2 = w2 + 1
  cmp w2, w1 // is w2 = w1?
  ble loop2 //if not equal, go back to loop2
  ret
main:
  mov w0, 5
  bl f