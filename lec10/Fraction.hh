#pragma once

class Fraction {
private:
  int num, den;
public:
  // constructor with initializer list
  Fraction(int n, int d) : num(n), den(d) { }
  // this is method (member function)
  // this is called with a.add(b) and returns fraction
  Fraction add(Fraction b) const { // <-- const here means readonly
    // (this method does not change object it is called on)
    return Fraction(this->num * b.den + this->den * b.num, this->den * b.den);
    // calling constructor creates unnamed temp
    // it goes away by ; but if return it, that's answer
  }

  // same code as above but as operator
  // called with c = a + b
  friend Fraction operator + (const Fraction& a, const Fraction& b) {
    return Fraction(a.num*b.den + a.den*b.num,a.den*b.den);
  }

  // this is friend function
  // add (a,b)
  friend Fraction add(const Fraction& a, const Fraction& b) {
    return Fraction(a.num*b.den);
  }

  // return numerator of fraction
  int getNum() const {return num;}
  int getDen() const {return den;}

  // this implements cout << f and prints out 1/2, 1/3 etc
  friend std::ostream& operator << (std::ostream& s, const Fraction& f) {
    s << f.num << "/" << f.den;
  }

};