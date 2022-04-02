ordermatters:
  // order matters! you can't shift first parameter?
  add x5, x3, #22
  //add x5, #22, x3
  sub x6, x4, x2 lsl #3
  // sub x6, x4 lsl #3, x2

  //rsub x5, x3, #22 can you do x5=22-x3? No

  //Intel:
  //add %r9, %rax, %rbx (Intel doesn't have 3-operand instructions!)
  // and by way, it's left to right!
  //mov %rax, %r9
  //add %rbx, %rax