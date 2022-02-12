#include <iostream>
#include <cmath>
using namespace std;

void rect2polar() {

}

int main() {
    double x, y, r, theta;

    cin >> x >> y;
    rect2polar(x, y, r, theta);

    cout << "r= " << r << "theta=" << theta << '\n';
}