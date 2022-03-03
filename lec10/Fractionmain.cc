#include <iostream>
#include "Fraction.hh"
using namespace std;

int main() {
  Fraction a(1,2);
  cout << a << '\n'; // calls operator <<
  Fraction b(1,3);
  Fraction c = a + b; // calls operator +

  cout << c << '\n'; // calls operator <<

  Fraction d = a.add(b); // call method add (same as operator +)
  cout << d << '\n';

  Fraction e = add(a,b); // call friend function

  int n = a.getNum(); // n = 1
}