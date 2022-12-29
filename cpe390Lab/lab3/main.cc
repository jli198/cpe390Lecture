/*
  Lab 3
  Author: JLi, Xavion
  cite:
  pledge "I pledge my honor that I have abided by the Stevens Honor System" ~JLi, Xavion
 */

#include <cmath>
#include <cstdint>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

// question 1:
// part 1
float sum_forward(int n) {
  float sum = 0;
  float diff = 0;
  for (float i = 1; i <= 100; i++) {
    sum = (1 / i) + sum;
  }

  return sum;
}

// part 2
float sum_backward(int n) {
  float sum = 0;
  float diff = 0;
  for (float i = n; i >= 1; i--) {
    sum = (1 / i) + sum;
  }

  return sum;
}
/* 
They are not equal, Sum forward is more accurate than sum backward as it has
an extra decimal of precision
 */

// part 3


// question 2:
// part 1:

float mystery_sum1(int n) {
  float pi = 0;
  float s = 0;
  for (int i = 1; i <= n; i++) {
    s = s + (1.0 / (i * i));
  }
  pi = sqrt(6 * s);
  cout << "For n= " << n << ", the sum is " << s << " " << endl;

  cout << "For n= " << n << ", the sqrt(6*s) is " << pi << " ";

  return pi;
}
float mystery_sum1corrected(int n) {
  float pi = 0;
  float s = 0;
  for (uint64_t i = 1; i <= n; i++) {
    s = s + (1.0 / (i * i));
  }
  pi = sqrt(6 * s);
  cout << "For n= " << n << ", the sum is " << s << " " << endl;

  cout << "For n= " << n << ", the sqrt(6*s) is " << pi << " ";

  return s;
}

// part 2:
float mystery_sum2corrected(int n) {
  float pi = 0;
  float s = 0;
  for (uint64_t i = n; i >= 1; i--) {
    s = s + (1.0 / (i * i));
  }
  pi = sqrt(6 * s);
  cout << "For n= " << n << ", the sum is " << s << " " << endl;

  cout << "For n= " << n << ", the sqrt(6*s) is " << pi << " ";

  return s;
}

// question 3:
double combineNumber(int a, int b) {
  // have to convert int to string using to_string
  string before = to_string(a);
  string after = to_string(b);

  // can concatenate (combine into single string) by just adding two strings
  string combine = before + "." + after;

  // converts string back into double
  double answer = stod(combine);
  return answer;  // return new double w/ appropiate decimal
}

// question 4:
double add(double c[3][3], double a[3][3], double b[3][3]) {
  for (int i = 0; i <= 2; i++) {
    for (int j = 0; j <= 2; j++) {
      c[i][j] = a[i][j] + b[i][j];
    }
  }
  return c[3][3];
}
// only need to consider the 3*3 2D matrix
void print(double arr[3][3]) {
  for (int i = 0; i <= 2; i++) {
    for (int j = 0; j <= 2; j++) {
      if (j == 2) {
        cout << arr[i][j] << '\n';

      } else {
        cout << arr[i][j] << " ";
      }
    }
  };
}

// question 5:
void quadratic(double a, double b, double c) {
  double term1 = a, term2 = b, term3 = c; // pow can be replaced with b ** 2
  double r1 = ((-b + sqrt((pow(b, 2) - 4 * a * c))) / 2 * a); // + quadratic formula
  double r2 = ((-b - sqrt((pow(b, 2) - 4 * a * c))) / 2 * a); // - quadratic formula
  cout << r1 << '\n';
  cout << r2 << '\n';
}

int main() {
  cout << setprecision(8) << setw(10);
  // test cases for question 1:
  cout << "answers for question 1:-------------------------" << endl;
  float q1_ans_1 = sum_forward(100);
  float q1_ans_2 = sum_backward(100);

  // test cases for question 2:
  cout << "answers for question 2:-------------------------" << endl;
  // input variable n = 100 for both functions,
  for (int n = 100; n <= 10000000; n *= 2) {
    float s1 = mystery_sum1(n);
    float s2 = mystery_sum1corrected(n);
    float s3 = mystery_sum2corrected(n);
    printf("%9d     %9.7lf %9.7lf %9.7lf %9.7lf %9.7lf %9.7lf\n", n, s1,
           sqrt(6 * s1), s2, sqrt(6 * s2), s3, sqrt(6 * s3));
#if 0
                cout << n << '\t' <<
                    s1 << '\t' << sqrt(6*s1) << '\t' <<
                    s2 << '\t' << sqrt(6*s2) << '\t' <<
                    s3 << '\t' << sqrt(6*s3) <<
                    '\n';
#endif
  }
  cout << "\n\n";

  // test cases for question 3:
  cout << "answers for question 3:-------------------------" << endl;
  cout << "combineNumber(34, 25) " << combineNumber(34, 25) << endl;
  cout << "combineNumber(1234, 56789123) " << combineNumber(1234, 56789123)
       << endl;

  // test cases for question 4:
  cout << "answers for question 4:-------------------------" << endl;
  
  // matrix example 1
  double a1[3][3] = {{1, 2, 3}, {4, 1, -2}, {-3, 1, 4}};
  double b1[3][3] = {{5, -1, 3}, {3, 2, 4}, {-2, 4, -2}};
  double c1[3][3];
  add(c1, a1, b1);  // c = a + b
  print(c1);
  /* should print
      6  1  6
      7  3  2
      -5 5  2
  */

  // matrix example 2
  double a2[3][3] = {{1.0, 2.5, -2.0}, {2.0, 1.3, 1.2}, {-1.2, 1.4, 3.1}};
  double b2[3][3] = {{2.0, 1.5, 1.0}, {-1.0, 2.3, 1.2}, {-1.2, 1.4, 3.1}};
  double c2[3][3];
  add(c2, a2, b2);  // c = a + b
  print(c2);
  
  // test cases for question 5:
  cout << "answers for question 5:-------------------------" << endl;
  quadratic(1.0, 2.0, 1.0);  // you need to print out the two roots inside of your function
  quadratic(1.0, -4, 4.000001);
}