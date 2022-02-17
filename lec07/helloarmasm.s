  .global main
main:
  mov x0, #0 // x0 = 0
  mov x1, #7
  mov x2, #255   //lim
  ret
  
  .global x
x:

//------------------------------------------------
//ECE Repo

.global main // export this symbol
main:
	// all instructions =32 bits
	mov	x0, #0	// x0 = 0
	mov	x1, #7
	mov	x2, #255	//limited to 8 bits (but with a shift)
	
	ret
x:
	