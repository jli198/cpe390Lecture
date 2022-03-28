// rough code/pseudocode; not to C++ standards
// after exam review/work through with tutor
// and there are various errors
// this is jut a rough sketch of what to do and is not correct and would not compile


double polynomial(double[] &coef, int len, double x) {
	double r = coef[0];
	for(int i = 1; i < len; i++) {
		r *= x + coef[i];
	}
	return r;
}

int main() {
	double coef[] = {3.0, 1.5, 2.0, 1.0};
	double x = 2;
	double r = polynomial(coef, 4, x); // should compute ((3.0 * x + 1.5) * x + 2.0) * x + 1.0
	double coef2[] = {4.0, 1.5, 3.0, -1.5, 6.0};
	r = polynomial(coef2, 5, x); // should compute (((4.0 * x + 1.5) + 3.0) * x + -1.5) * x +6.0
}
