#include "Fraction.hh"
#include <iostream>

int main() {
  Fraction a(1,2); // num = 1 den = 2
  Fraction b(1,3); // num = 1 den = 3
  Fraction c = a + b;
  std::cout << "c=" << c << '\n';
  Fraction d = a.add(b); // call method
  Fraction e = add(a,b);

  int n = e.getNum();
}