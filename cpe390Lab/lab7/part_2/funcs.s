	.global _Z3dotPmS_i
// x0 = address of array a
// x1 = address of array b
// x2 = len
_Z3dotPmS_i:
	mov x3, 0 // sum = 0
.L1:
	// int y = a[i++]
	ldr x4, [x0] // x4 = read memory location (x0, x0+1, x0+2, x0+3)
	// x4 = memory[x0] x0 = x0+8
	ldr x5, [x1] // x5 = read memory location (x1, x1+1, x1+2, x1+3)
	// x5 = memory[x1] x1 = x1+8
	mul x6, x4, x5 // x6 = x4 * x5
	add x3, x3, x6 // x3 = x3 + x6 | sum = sum + x6
	add x0, x0, 8 // advance to next uint64_t x0 = x0 + 8 [bytes]
	add x1, x1, 8 // advance to next uint64_t x1 = x1 + 8 [bytes]
	sub x2, x2, 1 // count down until 0
	cmp x2, 0 // if(x2 > 0)
	bgt .L1 // branch to .L1
	mov x0, x3 // x0 = x3
	ret

	.global _Z4dot1PiS_i
// x0 = address of array a1
// x1 = address of array b1
// x2 = len
_Z4dot1PiS_i:
	mov x3, 0 // sum = 0
.L2:
	// int y = a[i++] | ldrsw: does sign extension on register to convert negative #s to pos #s
	ldrsw x4, [x0] // x4 = read memory location (x0, x0+1, x0+2, x0+3)
	// x4 = memory[x0] x0 = x0 + 8
	ldrsw x5, [x1] // x5 = read memory location (x1, x1+1, x1+2, x1+3)
	// x5 = memory[x1] x1 = x1 + 8
	mul x6, x4, x5 // x6 = x4 * x5
	add x3, x3, x6 // x3 = x3 + x6 | sum = sum + x6
	add x0, x0, 4 // advance to next int32_t x0 = x0 + 4 [bytes]
	add x1, x1, 4 // advance to next int32_t x1 = x1 + 4 [bytes]
	sub x2, x2, 1 // count down until 0
	cmp x2, 0 // if(x2 > 0)
	bgt .L2 // branch to .L2
	mov x0, x3 // x0 = x3
	ret

	.global _Z5hypotdd
// d0 = low value a
// d1 = high value b
_Z5hypotdd:
	movi d2, 0 // sum = 0 | movi means move integer vector (makes double work somehow)
.L3:
	fmul d3, d0, d0 // d3 = d0 * d0 (a**2)
	fadd d2, d2, d3 // d2 = d2 + d3
	fmul d3, d1, d1 // d3 = d1 * d1 (b**2)
	fadd d2, d2, d3 // d2 = d2 + d3 
	fsqrt d2, d2 // sqrt(x2)
	fmov d0, d2 // d0 = d2
	ret

	.global _Z9quadraticdddd
_Z9quadraticdddd:
// Evaluate the polynomial ax^2+bx+c. The efficient way is using Horner's form: (ax + b)*x + c
// d0 = a
// d1 = b
// d2 = c
// d3 = x

fmul d4, d0, d3 // fmul adds d0 and d3 and stores it in d4
fadd d4, d1, d4 // d4(d0+d3) is added to b/d1
fmul d4, d3, d4//D4 multiplies by x
fadd d4, d2, d4
fmov d0,d4
ret


