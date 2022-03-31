  .global main

main:
  // write to memory, first one takes x=30 clock cycles, next=1
  stp lr, x0 [sp, #-16]! // store 2 registers to stack: lr, x0
  mov x0, #22
  mov x1, #13
  bl f //lr = pc | pc = f | bl = branch and link (for function calls)
//pc->
  mov x0, #5
  mov x1, #4
  bl g //lr = pc | pc = g

//pc ->
  bl func_calls_func //lr = pc

  ldp lr, x0, [sp], #16 // net stack used? ZERO
  ret

  //      x0     x1
  // f(int a, int  b)
f:
  add x0, x0, x1
  ret //pc=lr
g:
  mul x0, x0, x1
  ret
  
  // function MUST net use no stack memory
  // in other words, whatever take, must give back
func_calls_func:

  mov x0, #3
  mov x1, #4
  // convention is always write pairs of registers
  stp lr, x0, [sp], #16 // first read lr,x0 from [sp], then sp=sp+16

  ret // pc=lr


