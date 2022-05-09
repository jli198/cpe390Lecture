#include <iostream>

double polynomial(double coef[], int len, double x) {
	double result = coef[0]; // initialize result
	for(int i = 1; i < len; i++) {
		result *= x + coef[i];
	}
	return result;
}

int main() {
	double coef[] = {3.0, 1.5, 2.0, 1.0};
	double x = 2;
	double result = polynomial(coef, 4, x); // should compute ((3.0 * x + 1.5) * x + 2.0) * x + 1.0
  std::cout << result << std::endl;
	double coef2[] = {4.0, 1.5, 3.0, -1.5, 6.0};
	result = polynomial(coef2, 5, x); // should compute (((4.0 * x + 1.5) + 3.0) * x + -1.5) * x +6.0
  std::cout << result << std::endl;
}
