  .global main
main:
  bl f
  ret

f:
  sub sp, sp, #240
  bl f