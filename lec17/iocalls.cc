#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;

int main() {
  puts("hello puts\n"); // double quotes = hello puts\n\0
  fputs("hello fputs\n", stdout);

  cout << "hello cout\n";
  ofstream f("test.dat"); // this constructor opens file
  f << "hello ostream!\n";

  // f.close(); this is automatically done by DESTRUCTOR

  int n;
  cin >> n;
  cout << "n=" << n << '\n';
}