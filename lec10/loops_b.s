  .global main
main:
  mov x1, 0 // sum = 0
  mov x0, 1
loop:

                //add x0, x5, x6 x0 = x5 + x6
  add x1, x0, x1 // sum = sum + x0
  add x0, x0, 1 // immediate mode | x0 = x0 + 1;
  cmp x0, 10
  bne loop

loop2:

loop3:





  mov w0, 0
  ret