#include <iostream>
using namespace std;

extern int add(int a, int b);
extern int mul(int a, int b);
int main() {
  cout << add(2,3) << '\n';
  cout << mul(2,3) << '\n';
  return 0;
}
