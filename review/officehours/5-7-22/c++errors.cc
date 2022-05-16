#include <iostream>

int f(const int x[], int n) {
  int sum = 0;
  for (int i = n; i >= 0; i--)  // int i = n should be int i = n-1
    sum += x[i];
  return sum;
}

int g(const int x[], int n) {
  int sum = 0;
  for (int i = 0; i < n; i *= 2)  // sum is 0 so multiply by 2 will be infinite loop
    sum += x[i];
  return sum;
}

int h(const int x[], int n) {
  int sum = 0;
  for (int i = 1; i <= n; i *= 2) // i <= n should be i < n
    sum += x[i];
  return sum;
}

/*
h(arr, 10); // 1, 2, 4, 8
h(arr, 14); // 1, 2, 4, 8
h(arr, 16); //1, 2, 4, 8, 16 out of bounds
*/

// 1/1 + 1/2 + 1/3 + ... 1/n
int loop1(int n) {  // change int to double
  int sum = 0;  // change int to double
  for (int i = 0; i < n; i++) // divide by 0 bad, int i = 1 BUT 1/1 + 1/2 + 1/3 + 1/4
    sum += 1/i; // type promote 1 to 1.0
  return sum;
}

// n!/ (r!(n-r)!)
double choose (int n, int r) {
  double num = 0; // num = 1
  for (int i = n; i >= n-r; i--)  // i > n-r
    num *= i;
  
  double den = 0; // den = 1
  for (int i = r; i >= 0; i--)  // i > 0
    den *= i;
  return num/den;
}

double f (double x) {
  return 1/x;
}

double g(double x) {
  double dx = sin(x), dy = cos(x);
  return dx*dx+dy*dy;
}


std::cout << f(0.0); // infinity
double y = f(0.0);
std::cout << f(y); //

std::cout << g(0.0); // 1
std::cout << g(f(0.0));  // NaN
double z = 0.0 / 0.0; // NaN
double q = 0/0; // hardware trap, integer division