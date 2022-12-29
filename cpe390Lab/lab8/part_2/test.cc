#include <iostream>
#include <cmath>
using namespace std;

// 1.
int main() {
  cout << sizeof(24) << '\n';
  cout << sizeof(-52) << '\n';
  cout << sizeof(1234567890) << '\n';
  cout << sizeof(3U) << '\n';
  // cout << sizeof(4h) << '\n';
  cout << sizeof(5ULL) << '\n';
  cout << sizeof(2.5) << '\n';
  cout << sizeof(2.2f) << '\n';


// 2.
/*
  123 (in hex) =  7   B
                  --  -
                  16  1   123
                  x7    - 112
                  ==      ===    
                  112      11

  510 (in octal) = 7   7 6
                   --  - -
                   64  8 1  510  62
                   x7 x7   -448 -56
                   == ==    ===  ==
                  448 56     62   6

  105 (in binary) =  1   1   0  1 0 0 1
                    --  --  --  - - - -   
                    64  32  16  8 4 2 1
                   
                   105  41      9     1
                   -64 -32     -8    -1
                   === ===      =     =
                    41   9      1     0
*/

// 3.
  //a.
  int8_t d = 127;
  d++;

  //b.
  int8_t e = -125;
  e -= 5;

  //c.
  uint8_t f = 255;
  f += 2;

  //d.
  uint16_t g = 65533;
  g += 3;

  //e.
  uint64_t h = 2;
  h -= 4;

  //f.
  uint32_t i = -1;

	{
		uint32_t a = 2000000000 + 2000000000;
		uint32_t b = 4000000000U;
		cout << "a=" << a << '\n';
		cout << "b=" << b << '\n';
	}

	{
		uint32_t a = 3 * 1.5;
		uint32_t b = 3 * 1.6;
		int32_t c = -3 * 1.6;
		cout << "a=" << a << '\n';
		cout << "b=" << b << '\n';
		cout << "c=" << c << '\n';
	}

	{
		uint64_t a = 3 / 5 + 4 / 5;
		uint64_t b = 5 % 3 + 6 % 3 + 7 % 3;
		cout << "a=" << a << '\n';
		cout << "b=" << b << '\n';
	}

	{
		double a = 7 / 2;
		double b = 7 / 2.0;
		cout << "a=" << a << '\n';
		cout << "b=" << b << '\n';
	}

	{
		bool b1 = true;
		bool b2 = false;
		bool b3 = 3 == 4;
		bool b4 = 3 != 4;
		double sum = 0;
		for (int i = 0; i < 10; i++)
			sum += 0.1;
		bool b5 = sum == 1;
		bool b6 = sum != 1;
		cout << "b1=" << b1 << '\n';
		cout << "b2=" << b2 << '\n';
		cout << "b3=" << b3 << '\n';
		cout << "b4=" << b4 << '\n';
		cout << "b5=" << b5 << '\n';
		cout << "b6=" << b6 << '\n';
	}

	{
		double a = 1.0 / 0.0;
		double b = 0.0 / 0.0;
		double c = sqrt(a);
		double d = sin(a);
		double e = sin(0);
		double f = sqrt(-1);
	}


}