#include <iostream>
#include <iomanip>
using namespace std;

/*
	In this lab, you learn to manipulate bits.
	Most of this is in C++ because it's easier to keep track of

	A couple of the functions you will write in assembler to practice
*/

//given 8 bit colors r, g, b, combine into a single integer with bits
// rrrrrrrrggggggggbbbbbbbb
uint32_t color(uint8_t r, uint8_t g, uint8_t b) {
  uint32_t red = r << 16;
  uint32_t green = g << 8;
  uint32_t blue = b;
  uint32_t choosecolor = red | green | blue;
  return choosecolor;
}

//given a 24-bit color value, pull apart into r,g,b
// rrrrrrrrggggggggbbbbbbbb
//void color(uint32_t c, uint8_t& r, uint8_t& g, uint8_t& b);

//given a 24-bit color value, pull apart into r,g,b
// rrrrrrrrggggggggbbbbbbbb
void extractrgb(uint32_t color, uint8_t& r, uint8_t& g, uint8_t& b) {
  r = (color & 0x00FF0000) >> 16;
  g = (color & 0x0000FF00) >> 8;
  b = (color & 0x000000FF);
}
// extractrgb function is wrong

/*
	Given an array of numbers from 0 to 3, pack each number into 2 bits.
	For example, given array:

	int x[] = {0, 1, 2, 3, 0, 1, 1, 2, 3, 3, 1, 2};
	uint32_t y = pack2(x, 12); // y should be 0b000110110001011011110110
*/
uint32_t pack2(const uint32_t x[], uint32_t len) {
  uint32_t bitpack = 0;
  uint32_t x2 = 0;
  int n = 0;
  for (int i = 0; i < len; i++) {
    x2 = x2 | (x[i]) << 30 - n;
    n+= 2;
    bitpack = bitpack | x2;
  }
  return bitpack;

}

/*
	pack 3 bits at a time:
	uint32_t x[] = {0, 7, 4, 6, 1, 5, 4, 4, 6, 1, 7, 5, 3};
	uint64_t y = pack3(x, 13); 
  y = 0b000111100110001101100100110001111101011

 */
uint64_t pack3(const uint32_t x[], uint32_t len) {
  uint64_t bitpack = 0;
  uint64_t x1 = 0;
  uint64_t x2 = 0;
  int n = 0;
  for (int i = 0; i < len; i++) {
    x2 = x[i];
    x1 = x1 | (x2 << 61 - n);
    n += 3;
    bitpack = bitpack | x1;
  }
  return bitpack;
}

/*
	Given an array in[] of small values each 0..3
	with length len
	write packed values into the array out
	example:

	in[] = {1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3, 0 ...}
	total length = 1024 numbers

	the first 64 bits in the first element are the first 32 numbers
	out[] = {0110110001101100...  , 
	the second element is the next 32 numbers, ...

	return the number of 64 bit values written into the array
 */

uint64_t pack(const uint32_t in[], uint32_t len,	uint64_t out[]) {
  for(int i = 0; i < (len+31)/32; i++) {
    out[i] = 0;
  }
  for( int i = 0; i < len; i++) {
    uint64_t temp = in[i] << 62-(i % 31)*2;
    out[(i+31)/32] =out[(i+31)/32] |  temp;
    // cout << hex << (0 | temp) << " " ;
  }
  return (len+31)/32;
}

/*
	arithmetic encoding

	for numbers that don't fit well into k bits, arithmetic encoding 
	provides better compression

	example: compress numbers 0..22 into 64 bit words
	0..22 is 23 different numbers (base 23). This will fit into 5 bits
	but since values 24..31 are not used, we are wasting space

	Instead:

	int in[] = {22, 5, 19, 12, 6, 18, 2, 14, 10, 0, 9, 15, 17, 20};

	y = arithmetic_encode(x, 14, 23);
	b = 23
	(((22 * b + 5)*b + 19)* b + 12) * b + ...

*/
uint64_t arithmetic_encode(const uint32_t in[], uint32_t len, uint32_t base);


/*
	extra credit + 100. Write a function to compress an array
	using arithmetic encoding that writes multiple values 
	into an output array

	then write the reverse that unpacks and demonstrate it working
*/

int main() {
	uint32_t c = color(0xFF, 0x80, 0x00); // should be 0xFF8000
	cout << hex << c << '\n';

	uint8_t r, g, b;
	extractrgb(c, r, g, b);
	cout << hex << "r=" << r << " g=" << g << "b=" << b << '\n';

	const uint32_t a1[] = {1, 2, 3, 0, 1, 1, 3, 1, 1, 2, 3, 2};
	uint32_t packed1 =  pack2(a1, 12);
	cout << "packed array a1=" << packed1 << '\n';

	const uint32_t a2[] = {0, 7, 4, 6, 1, 5, 4, 4, 6, 1, 7, 5, 3};
	uint64_t packed2 = pack3(a2, 13);
	cout << "packed array a2=" << packed2 << '\n';

	const uint32_t input_size = 1036;
	uint32_t* p = new uint32_t[input_size];
	for (uint32_t i = 0; i < input_size; i++)
		p[i] = i & 3; // write numbers from 0..3 into each array element

	// allocate enough 64-bit numbers to hold the output
	uint64_t*out = new uint64_t[(input_size+31) / 32];
															
	uint64_t out_len = pack(p, input_size, out);
	for (uint32_t i = 0; i < out_len; i++) {
		cout << out[i] << '\n';
	}
	
}