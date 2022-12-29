/*
Lab 1 - Setting up the environment - Part 4 Coding Part
Author: JLi
Cite: https://www.youtube.com/watch?v=3AfBBa_-5AQ modified with int64_t and enter any number to compute table
https://www.cplusplus.com/reference/cstdio/printf/ to understand specific printf format string (explained in comments)
Pledge: "I pledge my honor that I have abided by the Stevens Honor System" ~JLi
*/

#include <iostream>
using namespace std;

int main(void) {

    int64_t i, j;
    int64_t num;

    cout << "Enter a number and the program will give you its multiplication table!" << '\n';
    cin >> num;

    //Prints first row; %4c| represents a specific printf format string: % is format specificer, c for character, | is the character, 4 is the amount of spaces
    printf("%4c|", ' ');
    for(i = 0; i <= num; i++) {
        printf("%4d", i);
    }
    printf("\n");

    //Prints the actual multiplication table; %4d represents specific printf format string: d is for signed decimal integer; i or ' ' goes before |
    for(i = 0; i <= num; i++) {
        printf("%4d|", i);
        for(j = 0; j <= num; j++) {

            printf("%4d", i*j);
        }
        printf("\n");
    }
}