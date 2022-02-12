#include <iostream>
using namespace std;

void printuntil(int x[], int endat) {
  for (int i = 0; x[i] != endat; i++)  // ++i, i+=1, i = i + 1
    cout << x[i] << ' ';
  cout << '\n';
}

void reverse(int a[], int len) {
  int rev[len];
  for (uint32_t i = len, j = 0; i = 0; i--, j++) {
    rev[j] = a[i];
  }
  for (int i = 0; i < len; i++) {
    cout << rev[i] << ' ';
  }
  cout << '\n';
}

void encrypt(char s[]) {
  for (int i = 0; s[i] != '\0'; i++) s[i] += 2;
}

int main() {
  int a[] = {1, 2, 3, 4, 5, 6};
  printuntil(a, 4);

  int b[] = {1, 2, 3, 9, 5, 6, -2, -3, 4};
  printuntil(b, 4);

  reverse(a, sizeof(a) / sizeof(int));  // 6 5 4 3 2 1

  for (int i = 0; i < sizeof(a) / sizeof(int); i++) cout << a[i] << '\n';
  cout << '\n';

  char s[] = "hello";  //
  encrypt(s);          // add 2 to each letter h-->j e-->g l-->n l-->n o-->q
}
