#include<iostream>

using namespace std;

namespace stevens {
    int x; //stevens::

}

namespace li {
    int x; //li::
}

int main() {
    cout << "Jason Li\n";
    stevens::x = 3;
    li:: x = 5;
    return 0;
}