// write your arm code here
/*
Lab 9 - Part 2: (Group work) 2 assembler functions to work for homework
Author: Jason Li, Xavion McClary
Cite:
pledge "I pledge my honor that I have abided by Stevens Honor System." ~Jason Li, Xavion McClary
*/

	.global _Z9factoriali
// w0 = n
_Z9factoriali:
	mov w1, 1 // prod = 1
loop:
	mul w1, w1, w0 // w1 = w1 * w0
	sub w0, w0, 1 // count down n until 1
	cmp w0, 1 // if (w0 != 1)
	bne loop // branch to loop
	mov w0, w1 // w0 = w1
	ret 
	
	.global _Z8evenProdii
// w0 = a
// w1 = b
_Z8evenProdii:
	mov w2, 1 // prod = 1
loop2:
	and w3, w0, 1 // r3 <- r1 & 1 <- How to get odd
	cmp w3, 0 // if (w3 != 0)
	bne odd // branch to odd
even:
	mul w2, w2, w0 // w2 = w2 * w0
	add w0, w0, 2 // w0 = w0 + 2
	cmp w0, w1 // if (w0 <= w1)
	ble even // branch to even
	b endloop // branch to endloop
odd:
	add w0, w0, 1 // w0 = w0 + 1
	b loop2 // branch to loop2
endloop:
	mov w0, w2 // w0 = w2
	ret
		
