#include <iostream>
using namespace std;
// choose(n,r) = n! / (r! (n-r)!) choose(52,6) = 52! / (6! 46!) 

double fact(int n);
double choosefast(int n);

double choose(int n, int r) {
  return fact(n) / (fact(r) * fact(n-r));
}

double fact(int n) {
  double prod = 1;
  while (n > 0)
    prod *= n--;
  return prod;
}

double choose_arm(int n, int r);

int main() {
  for (int i = 1; i < 30; i++)
    cout << setprecision(15) << i << "\t" << fact(i) << '\n';
  cout << setprecision(15) << choose_arm(52, 6) << '\n';
  cout << setprecision(15) << choosefast(52, 6) << '\n';
  cout << setprecision(15) << choose_arm(52, 6) << '\n';
}