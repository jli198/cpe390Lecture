#include <iostream>
#include <cmath>
using namespace std;

int main() {
  int prod = 1;
  while (prod < 1024) {
    prod *= 2;
    cout << prod << endl;
  }
}