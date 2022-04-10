#include <iostream>
using namespace std;
/*
	Test 2:
	ARM assembler instructions
  some C++ where assembler would be too hard
	loops
  if statements
  array lookup in assembler  know all modes [x0] [x0, #4] [x0, #4]! [x0], #4

	bitwise operations in C++ and ARM

	equivalence
  a = b & c       and  x0, x1, x2
  a = b | c       orr  x0, x1, x2
  a = b ^ c       eor  x0, x1, x2
  a = ~b          mvn x0, x1

  unsigned shift
  a >> b          lsr x0, x1      10100000 --> 00101000
  a << b          lsl x0, x1      10110001 --> 11000100
  
*/


// convert the following C++ code into the equivalent ARM assembler
int f(int a, int b, int c, int d) { // a AND b OR (NOT c) XOR d
	return a & b | (~c ^ d);
}
// and x0, x1, x2
// orr x0, x1, x2
// eor x0, x1, x2
// mvn w0, w1 // x0 = NOT x1    given w1 = 
                                //w0 = 

uint64_t optimized1(uint64_t a, uint64_t b) {
	return (a >> b) | (a << (64-b)); // what arm instruction does this turn into? ror 2
}

uint64_t optimized2(uint64_t a) {
	return a * 16; // what arm instruction does this turn into? lsl 4
}

uint64_t optimized3(uint64_t a) {
	return a / 32; // what arm instruction does this turn into? lsr 5
}

uint64_t optimized4(uint64_t a) {
	return a % 64; // what arm instruction does this turn into? AND (63)
}



/*
  5*a*4 --> (5*4)*a
  5*a/6.0 -> (5/6.0) *a
*/
// ^^^ COMMENTED BLOCK OF CODE ABOVE IS NOT ON TEST

// a % 4 --> 0 to 3  00 01 10 11

/*
	Identify the value in the registers

  mov x0, #19
  mov x1, #24
  and x2, x0, x1 // x2=
  eor x3, x0, x1 // x3=
  orr x4, x0, x1 // x4=

 */