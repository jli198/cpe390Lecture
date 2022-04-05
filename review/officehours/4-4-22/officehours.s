  // identify what is in each register
  .global main
main:
0x555550750: mov x0, #3 // x0=3, pc=0x555550750
0x555550754: mov x1, #4
0x555550758: stp lr, x0, [sp, #-16]!
0x55555075C: bl f (0x555550768) // lr=0x555550760, pc=0x555550768
0x555550760: ldr lr, x0, [sp], #16 
0x555550764: ret // back to caller
0x555550768: add x0, x0, x1
0x55555076C: stp lr, x0, [sp, #-16]!
0x555550770: bl g (0x55555077C) // lr=0x555550774, pc=0x55555077C
0x555550774: ldr lr, x0, [sp], #16 // lr=0x555550760
0x555550778: ret //pc=0x555550760
0x55555077C: add x4, x5, x6
0x555550780: ret //pc=lr=0x555550774

   // 5    5   5    6 bits
  add x0, x5, x6 lsl #63
  sub
  and
  orr
  eor

  ldr x3, [x0], #8 // x3 = load from location [x0], pc=
  // ^^^ don't solve for pc
