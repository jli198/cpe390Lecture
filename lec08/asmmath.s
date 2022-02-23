	.global main
main:
	mov x0, 2 // x0 = 2;
	mov x1, 3 // x1 = 3;
	add x2, x1, x0 // x2 = x1 + x0 = 2 + 3 = 5 | x0 = 5

	mov x3, 4 // x3 = 4;
	mov x4, 5 //x4 = 5;
	mul x5, x3, x4 // x5 = x3 * x4 = 4 * 5 = 20 | x5 = 20
	mov x0, 19 // x0 = 19;
	mov x1, 7 // x1 = 7;
	bl f // f()
	ret // return x0 from f();
	
f: //in f()
	add x0, x0, x1 // x0 = x0 + x1 = 19 + 7 = 26 | x0 = 26
	ret //return x0 back into main:
