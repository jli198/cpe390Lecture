#include <iostream> 
#include <fstream>

using namespace std;

int main() {
  ofstream f("test.dat");
  f << "hello" << 241 << 3.5 << '\n'; // #s print ASCII representation (letter) of number 
}