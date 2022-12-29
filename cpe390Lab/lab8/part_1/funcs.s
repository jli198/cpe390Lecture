// write your asm here

	.global _Z3dotPiS_i
// x0 = address of array a
// x1 = address of array b
// x2 = len
_Z3dotPiS_i:
	mov x3, 0 // sum = 0
.L1:
	ldrsw x4, [x0]
	ldrsw x5, [x1]

	mul x6, x4, x5
	add x3, x3, x6
	add x0, x0, 4
	add x1, x1, 4
	sub x2, x2, 1 // count down until 0
	cmp x2, 0
	bgt .L1
	mov x0, x3
	ret	

	.global _Z1fmmm
// x0 = a
// x1 = b
// x2 = c
_Z1fmmm:
	mov x3, 3 // x3 = 3
	mov x4, 2 // x4 = 2

	mul x5, x3, x0 // x5 = x3 * x0 = 3 * a
	mul x6, x4, x1 // x6 = x4 * x1 = 2 * b
	add x7, x5, x6 // x7 = x5 + x6 = (3 * a) + (2 * b) 
	mul x8, x7, x2 // x8 = x7 * x2 = (3 * a) + (2 * b) * c
	mov x0, x8 // x0 = x6
	ret

	.global _Z12order_of_opsmmm
// x0 = a
// x1 = b
// x2 = c
_Z12order_of_opsmmm:
	mul x3, x1, x2 // x3 = x1 * x2 = b * c
	add x4, x0, x3 // x4 = x0 + x3 = a + (b * c)
	mov x0, x4 // x0 = x4
	ret

	.global _Z12count3nplus1m
// x0 = n
_Z12count3nplus1m:
	mov x1, 0 // counter
loop:
	cmp x0, 1
	ble exit
	and x2, x0, 1 // x2 = x0 && 1
	cmp x2, 1
	beq odd
	bne even
even:
	mov x0, x0, ASR 1 // x1/2
	add x1, x1, 1
	b loop
odd:
	mov x3, 3
	mul x0, x3, x0 // x3 = x3 * x0 = 3 * x0
	add x0, x0, 1 // x0 = x0 + 1
	add x1, x1, 1
	b loop
exit:
	mov x0, x1
	ret 	

	.global _Z11double_eachPii

_Z11double_eachPii:
//x0= address of the array
//x1 size of the array
loop:
ldrsw x2, [x0]//loads array
mul x3, x2, 2//doubles x2 and stores in x3
str x3, [x0] //x3 stored into x0
add x0, 4 //increment to next address in array
sub x1,1 //decrement to next number in the array
cmp x1, 0// compare x1 and 0 in order for the loop to keep running until it reaches -
bgt loop// if the value of x1 is greater than 0 than the loop will run again
ret

.global _z9clear_lowm

_z9clear_lowm:

BIC r0, r0, 0xFFFFFFFFFFFFFFF0
ret 

.global _z10setbits5_9m

_z10setbits5_9m:

OR r0, r0 0x00000000000003E0
ret



.global _z13togglebits4_9m

_z13togglebits4_9m:

XOR r0, r0 0x000000000000000003F0

ret

