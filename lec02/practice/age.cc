#include <iostream>
using namespace std;

int main() {
    int16_t age;
    cout << "Put down your age and I will show you your age in seconds: ";
    cin >> age;
    cout << age * 365 * 24 * 60 * 60 << '\n';    
}