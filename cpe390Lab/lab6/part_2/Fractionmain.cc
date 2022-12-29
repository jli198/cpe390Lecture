#include "Fraction.hh"
#include <iostream>

int main() {
	Fraction a(1,2);
	std::cout << a << '\n'; // calls operator <<
	Fraction b(1,3);
	Fraction c = a + b; // call the operator +

	std::cout << c << '\n'; // calls operator <<

	Fraction d = a.add(b); // call the method add (same as operator +)
	std::cout << d << '\n'; // calls operator <<

	int n = a.getNum(); // n = 1
}
