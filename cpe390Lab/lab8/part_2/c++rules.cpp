/*
Lab 8 - Part 2: C++ for homework
Author: JLi
Cite:
pledge "I pledge my honor that I have abided by Stevens Honor System." ~JLi
*/

#include <iostream>
#include <cmath>
using namespace std;

/*
This is an individual assignment
Determine the result for each statement and state the rule in C++
Explain EXACTLY what happens.
You must get every question here correct in order to qualify to retake the first question of test #1
1. Write down the type of each constant shown.
  Write code in C++ to print the number of bytes of each one using
	sizeof( ) to verify.
  a. 24 4 bytes | int
  b. -52 4 bytes | int
  c. 1234567890 4 bytes | int
  d. 3U 4 bytes | unsigned int
  e. 4h 4 bytes | hexadecimal int
  f. 5ULL 8 bytes | unsigned long long int
  g. 2.5 8 bytes | double
  h. 2.2f 4 bytes | float


2. Initialize each variable using the base shown:

a. int a = 0x7B         123 (in hex)
b. uint16_t b = 0o776     510 (in octal)
c. uint8_t c = 0b1101001  105 (in binary)  

3. For each value, show the result and explain how it is computed
Be sure to explain steps in sequence, including type promotion.
a. int8_t d = 127;
   d++;                      //d= -128 The integer rounds down to the lowest possible value which is -128

b. int8_t e = -125;
   e -= 5;                   //e= 126 The integer rounds back up to the highest possible value which is 126

c. uint8_t f = 255;
   f += 2;                   //f= 1. Integer rounds back to 0 then adds 1 to become +1. It's unsigned so it can't go to negative

d. uint16_t g = 65533;
   g += 3;                   //g= 0. Integer rounds back to lowest possible value 0 as it's unsigned so it can't go to negative

e. uint16_t h = 2;
   h -= 4;                   //h= 65534. Integer rounds back up to highest possible value minus 1. highest value is 65535 minus 1 is answer

f. uint32_t i = -1;          // show the bits in i
negative # will try to convert to positive number. if converted, 4294967295

*/

int main() {
	{ // uint32_t a = 2000000000 + 2000000000; prints 4000000000
    // because it's less than 4294967295 which is max that uint32_t can hold
		uint32_t a = 2000000000 + 2000000000;
    // b is also less than 4294967295 so it can print
		uint32_t b = 4000000000U;
		cout << "a=" << a << '\n';
		cout << "b=" << b << '\n';
	}

	{ // a is an int so it has to get rid of decimal to obtain 4
		uint32_t a = 3 * 1.5; // a = 4; 3 * 1.5: 3 is promoted to double and gives 4.5
		uint32_t b = 3 * 1.6; // b = 4; 3 * 1.6: 3 is promoted to double and gives 4.8
    // b is an int so it has to get rid of the decimal to obtain 4
		int32_t c = -3 * 1.6; // c = -4; -3 * 1.6: 3 is promoted to double and gives -4.8
    // c is negative int but still gets rid of decimal to obtain 4
		cout << "a=" << a << '\n';
		cout << "b=" << b << '\n';
		cout << "c=" << c << '\n';
	}

	{
		uint64_t a = 3 / 5 + 4 / 5; // a = 0; / are ints and does not include decimals
    // the fraction operations are equal to 0 then 0 + 0 = 0
		uint64_t b = 5 % 3 + 6 % 3 + 7 % 3; // b = 3 = 2 + 0 + 1 = 3
    // % (mod) stores remainders of calculations
		cout << "a=" << a << '\n';
		cout << "b=" << b << '\n';
	}

	{
		double a = 7 / 2; // a = 3; right side #s are ints and will return int
		double b = 7 / 2.0; // b = 3.5; 7 is type promoted to double and thus has 3.5
		cout << "a=" << a << '\n';
		cout << "b=" << b << '\n';
	}

	{
		bool b1 = true; // b1 is set to true, so it always returns 1
		bool b2 = false; // b2 is set to false, so it always returns 0
		bool b3 = 3 == 4; // checks if 3 is equal to 4, it isn't true so it returns 0
		bool b4 = 3 != 4; // checks if 3 is not equal to 4, it is true so it returns 1

		double sum = 0;
		for (int i = 0; i < 10; i++)
			sum += 0.1;
		bool b5 = sum == 1; // loop runs 10 times but double's approx 1 so it doesn't "=" 1
		// system returns 0 for b5. lesson learned: dont use floating point in loops
    bool b6 = sum != 1; // if it's false for equal, it is true for not equal
		cout << "b1=" << b1 << '\n';
		cout << "b2=" << b2 << '\n';
		cout << "b3=" << b3 << '\n';
		cout << "b4=" << b4 << '\n';
		cout << "b5=" << b5 << '\n';
		cout << "b6=" << b6 << '\n';
	}

	{
		double a = 1.0 / 0.0; // inf
		double b = 0.0 / 0.0; // NaN
		double c = sqrt(a); // square root of infinity is infinity
		double d = sin(a); // sin of infinity is not determinable so NaN
		double e = sin(0); // sin(0) = 0
		double f = sqrt(-1); // imaginary numbers always return NaN
	}
}