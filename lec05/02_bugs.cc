#include <iostream>
#include <iomanip>
using namespace std;

double f(double x) { //root is at x = +/- sqrt (2)
    return x*x - 2;
}

double bisection(double a, double b) {
    for (int i = 0; i < 5; i ++) {
        double x = (a+b)/2;
        double y = f(x);
        if (y > 0) 
            b = x;
        else if(y < 0)
            a = x;
        else
            return x;
    }
}

int main() {
    double a = 1.0, b = 5;
    cout << bisection(a,b);
}