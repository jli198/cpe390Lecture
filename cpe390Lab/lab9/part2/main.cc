#include<iostream>
using namespace std;

extern int factorial(int n);
extern int evenProd(int a, int b);

int main() {
	int res1 = factorial(5); // 5 * 4 * 3 * 2 * 1 = 120
	cout << "factorial(5): " << res1 << endl;
	int res2 = evenProd(3, 8); // = 4 * 6 * 8 = 192
	cout << "evenProd(3, 8): " << res2 << endl;
	return 0;
}
