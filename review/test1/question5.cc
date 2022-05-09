// (30 points) Find errors and expalin what is wrong:
void f1() {
  for (uint8_t i = 0; i < 500; i++) // 0 to 499... NO! 0, 1, 2... 255, 0, 1, 2... 243
    cout << i;
}
// **Function does not count up to 500** change uint8_t to regular int

void print(int a[], int n) {
  for (int i = n; i > 0; i--)
    cout << x[i] << ' ';
  cout << '\n';
}
// array shouldn't have highest value. it has to be highest value-1 as highest value is invalid since arrays start at element 0 and end with element highest-1 not element highest. Answer would have to make i > 0 for i = n-1 or i >= 0 for i = n to account for first element

// should sum 1/1 + 1/2 + 1/3 + ... + 1/n
// example suminv(100) should be approximately 5.18
float suminv(int n) { // change int n to float n (maybe)
  float sum = 0;
  for (int i = 0; i < n; i++) // change int n to float n
    sum += 1/i;
  return sum;
}
// i will remain int and so is not type promoting sum value. Type promotion occurs on right side only. having 1/1 will produce 1. 1/2 would produce 0,1/3 would produce 0. i would have to be float in order for right hand side of sum += 1/i to type promote