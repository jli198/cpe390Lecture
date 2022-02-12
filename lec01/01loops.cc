#include <iostream>

int main() {
    uint32_t x = 99; 
    uint64_t a = 100000000LL;
    int64_t b = -12345566767675LL;
    int y = 99; // non-portable

    for(int i =1; i <= 10; i++) {
        std::cout << i; //prints what? 12345678910
    }
    std::cout << '\n';
}

//HW: write
//1. code to print even numbers from 2 to 20
//2. print out powers of 2 from 1 to 1024 1 2 4 8 16 32 64 128 256 512 1024