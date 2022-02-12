  .glbl main
main:
  movq $0, %rax
  xorq %rax, %rax // fastest wa
  movq $7, %rbx
  movq $255, %rsi

  movq $1, %r9
  movq $1, %r10
  movq $1, %r11

  ret