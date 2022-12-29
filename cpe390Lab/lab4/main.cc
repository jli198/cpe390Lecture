/*
  Lab 4
  Author: JLi
  cite:
  pledge "I pledge my honor that I have abided by the Stevens Honor System" ~JLi
 */

#include <cmath>
#include <cstdint>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <random>
#include <vector>

using namespace std;
// edit in this part, find your group and paste there
// just for test

// group 5:
// question 9: --------------------------------------------------------
void windchill() {
  int solution = 0;
  int t = 0;
  int v = 0;

  for (int i = 45; i >= -45; i -= 5) {
    if (i == 45) {
      cout << "Ca ";

    } else {
      cout << i << " ";
    }
  }
  cout << '\n';
  for (int k = 5; k <= 60; k += 5) {
    if (k == 5) {
      cout << k << "  ";
    } else {
      cout << k << " ";
    }
    for (int z = 40; z >= -45; z -= 5) {
      t = z;
      v = k;
      solution = 35.74 + (0.6215 * t) - (35.75 * pow(v, 0.16)) +
                 (.4275 * t * pow(v, 0.16));
      cout << solution << " ";
    }

    cout << '\n';
  }
}
void add_to_list(vector<double>& mylist, int n) {
  vector<double> vector{1};
  mylist = vector;
  for (int i = 1; i <= n; i++) {
    vector.push_back(i);
  }

  for (int j = 1; j <= n; j++) {
    cout << vector.at(j) << " ";
  }
  cout << '\n';
}

  int main() {
    // question 9: --------------------------------------------------------
    windchill();
    // question 10 & 11 & 12:
    // --------------------------------------------------------
    vector<double> v;
    add_to_list(v, 9);
    print(v);

    return 0;
  }
