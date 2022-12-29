#include <iostream>
using namespace std;
extern int sum(int a); // return the sum from 1 to 5
extern int sumSq(int a, int b); // return a^2 + (a + 1)^2 + (a + 2)^2 +... + b^2

int main(int argc, char *argv[]) {
    // for function sum:
    int r1 = sum(5); // result: 1 + 2 + 3 + 4 + 5 = 15
    cout << r1 << '\n';
    // for function sumSq:
    int r2 = sumSq(3,5); // result: 9 + 16 + 25 = 50
    cout << r2 << '\n';
    return 0;
}
