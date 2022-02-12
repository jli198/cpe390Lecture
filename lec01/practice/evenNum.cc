#include <iostream>
using namespace std;

int main() {
    for(int64_t i = 2; i <= 20; i++) {
        if(i % 2 == 0) {
            cout << i << '\n';
        }
    }
    return 0;    
}