#include <iostream>
using namespace std;

/*
    2 errors: uninitialized variables, and going out of bounds

*/

int main() {
  uint32_t a;  // create 1 int (random garbage) 0... 4.2 billion
  int b[10];   // create 10 integers in single block of memory (random garbage)
  cout << a << '\n';
  a = 19;
  cout << a << '\n';

  for (int i = 0; i < 100; i++)
    cout << b[i] << " ";  // printing values out of bounds! Ouch
  cout << '\n';

  char s[] = "0hello";
}