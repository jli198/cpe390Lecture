// (10 points) For each line, determine what is computed
int main() {
  int a = 1.5 * 3;  // a = 4
  uint32_t b = 7/2; // b = 3
  uint8_t c = 255;
  c++;  // c = 0
  double d = 7 / 2; // d = 3
  
  double sum = 0;
  for (int i = 0; i < 10; i++)
    sum += 0.1;
  bool e = sum == 1.0;  // e = 0

  sum = 0;
  for (int i = 3; i < 15; i += 4)
    sum += i; // sum = 21

  a = 9;
  for (int i = 10; i < 0; i--)
    a += i; // a = 9
  
  uint32_t f = 3 + 4 * 5; // f = 23

  double g = 0.0 / 0.0; // g = NaN

  uint32_t h = 4 % 3 + 5 % 3; // h = 3
}