//  write your arm code below
	.global _Z3sumi
// in: x0
_Z3sumi:
	mov x1, x0 // x1 = x0
	mov x0, 0 // x0 = 0 | iterator i
 	 mov x2, 0 // x2 = 0 | sum value
loop:
	add x0, x0, 1 // x0 = x0 + 1
 	add x2, x2, x0 // x2 = x2 + x0
	cmp x0, x1 // compare x0 to x1 (x1 = a)
	bne loop // jump back to loop if not equal
	mov x0, x2 // x0 = x2
 	ret

	.global _Z5sumSqii
// in: x0, x1
_Z5sumSqii:
	mov x3, 0 // x3 = 0
 	mov x2, 0 // x2 = 0
loop2:
	cmp x0, x1 // compare x0 to x1
	bne .L3
	mul x2, x0, x0 // x2 = x0 * x0
	add x3, x3, x2 // x3 = x3 + x2
  	mov x0, x3 // x0 = x3 
	ret
.L3: 
	mul x2, x0, x0 // x2 = x0 * x0
	add x3, x3, x2 // x3 = x3 + x2
	add x0, x0, 1 // x0 = x0 + 1
	b loop2 
	
	
	
	   
	
