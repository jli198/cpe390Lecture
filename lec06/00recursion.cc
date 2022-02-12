#include <iostream>
using namespace std;

int fact(int N) {
  // I: Answer to simplest instance of problem
  // "Base case" or "anchor value"
  if (N == 1) {
    return 1;
  }
  // II: Reducing original instance towards base case
  // exploiting pattern that is inherent in problem
  else {
    return N * fact(N - 1);
  }
}

double factorial(int n) { // n! = n * (n-1) * (n-2) * ... 1
  double prod = 1; //121285 * 5
  for (int i = n; i > i; i--) {
    prod = prod * i; // 1*5 5*4 20*3 60*2
  }
  return prod;
}

double fact390(int n) {
  // fact (5) = 5*fact(4) fact(4) =4*fact(3)
  // fact (3) = 3*fact(2) fact(2) =2*fact(1)
  // fact (1) = 1*fact(0) fact(0) = 0*fact(=1) ...

  if (n <= 1)
   return 1;

  return n * fact390(n - 1); 
}

//count (n) = n
int count(int n) {
  int sum = 0;
  for (int i = 1; i <= n; i++)
    sum++;
  return sum;
}

int main() { 
  int ans = fact(5);
  cout << ans << '\n';
  }
/*
int count2(int n) {
  if (n == 0) 
    return 0;
}
*/