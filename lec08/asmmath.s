	.global main
main:
	mov x0, 2
	mov x1, 3
	add x2, x1, x0

	mov x3, 4
	mov x4, 5
	mul x5, x3, x4
	mov x0, 19
	mov x1, 7
	bl f
	ret
	
f:
	add x0, x0, x1
	ret
