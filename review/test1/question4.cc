// (20 points) Implement function polynomial to evaluate Horner's form using loop for each element, multiply by x and add coefficient

#include <iostream>

double polynomial(double coef[], int len, double x) {
	double r = coef[0]; // initialize result
	for(int i = 1; i < len; i++) {
		r *= x + coef[i];
	}
	return r;
}

int main() {
	double coef[] = {3.0, 1.5, 2.0, 1.0};
	double x = 2;
	double r = polynomial(coef, 4, x); // should compute ((3.0 * x + 1.5) * x + 2.0) * x + 1.0
  std::cout << r << std::endl;
	double coef2[] = {4.0, 1.5, 3.0, -1.5, 6.0};
	r = polynomial(coef2, 5, x); // should compute (((4.0 * x + 1.5) + 3.0) * x + -1.5) * x + 6.0
  std::cout << r << std::endl;
}
