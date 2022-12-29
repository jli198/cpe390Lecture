/*
	Lab 7 - Part 2
  AUTHOR: JLi, Xavion
	CITE: B123 TA Armand for cracking ldrsw (makes negative #s valid with function instructions below)
	PLEDGE: "I pledge my honor that I have abided by the Stevens Honor System" ~JLi, Xavion
*/

#include <iostream>
#include <cmath>
using namespace std;


extern uint64_t dot(uint64_t a[], uint64_t b[], int len);
extern int64_t dot1(int32_t a1[], int32_t b1[], int len);
extern double hypot(double a, double b); // return sqrt of a**2+b**2
extern double quadratic(double a, double b, double c, double x);


int main() {
	uint64_t a[] = {2, 3, 2, 5};
	uint64_t b[] = {3, 2, 3, 2};
	cout << dot(a, b, 4) << '\n'; // 2*3 + 3*2 + 2*3 + 5*2

	int32_t a1[] = {2, 3, -3, 5};
	int32_t b1[] = {-3, 2, 3, 2};
	cout << dot1(a1, b1, 4) << '\n'; // 2*-3 + 3*2 + -3*3 + 5*2
	cout << hypot(3, 4) << '\n'; // should be 5
	cout << hypot(2, 3) << '\n';
	cout << quadratic(1, 2, 1, 3.0) << '\n';
	return 0;
}
