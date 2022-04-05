  // identify what is in each register
  .global main

  // SP = 7FFFFFC080
main:
0x5555507C8: mov x0, #3 // x0=__ pc=__
0x5555507CC: mov x0, #3 // x0=__ pc=__
0x555550780: mov x1, #4
0x555550784: stp lr, x0, [sp, #-16]!
0x555550788:
0x55555078C:
0x555550790:
0x555550794:
0x555550798:
0x55555079C:
0x5555507A0:
0x5555507A4:
0x5555507A8: