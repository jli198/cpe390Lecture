/*
  Lab 8 - Part 1: 8 assembler functions to write
  Author: JLi, Xavion
  cite: https://thinkingeek.com/2013/01/20/arm-assembler-raspberry-pi-chapter-6/ 3n+1 &&1 is way to determine even or odd; ASR logic
  pledge "I pledge my honor that I have abided by the Stevens Honor System" ~JLi, Xavion
*/

#include <iostream>
#include <cmath>

using namespace std;
extern int64_t dot(int a[], int b[], int len);
extern uint64_t f(uint64_t a, uint64_t b, uint64_t c);
extern uint64_t order_of_ops(uint64_t a, uint64_t b, uint64_t c);
extern uint64_t count3nplus1(uint64_t n);
extern void double_each(const uint32_t a[], int n);

extern uint64_t clearlow4(uint64_t a); // clear the low 4 bits of a

 // return a with set bits from 5 to 9 (0 is rightmost)
extern uint64_t setbits5_12(uint64_t a);

//return a with all bits marked x set to 1: 10101010xxxxxxxx01010
extern uint64_t togglebits4_9(uint64_t a);

int main() {
	
	
	{
		int a[] = {-1, 1, 2};
		int b[] = {1, -2, 1}; // - 1 -2 + 2 = -1
		int64_t c = dot(a, b, 3);
		cout << c << '\n';
	}
	{
		cout << f(1, 2, 3) << '\n';
		cout << f(2, 5, 1) << '\n';

		cout << order_of_ops(3, 4, 5) <<'\n';
		
		cout << count3nplus1(5) << '\n'; // 5 
		cout << count3nplus1(17) << '\n'; // 11
		/*
		{
			uint32_t a3[] = {2, 4, 5, 9};
			double_each(a3, 4);
			for (int i = 0; i < 4; i++)
				cout << a3[i] << ' ';
			cout << '\n';
		}

		{
			cout << hex << clearlow4(0x9ACEULL) << '\n';
			uint64_t a4 = setbits5_12(0xFACEB001);
			cout << hex << a4 << '\n';
			cout << hex << togglebits4_9(0x0123456789ABCDEFULL) << '\n';
		} */
	}

}
