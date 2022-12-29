#include <iostream>
#include <math.h>
using namespace std;

/*
  Lab 2
  Author: JLi, Xavion
  cite:
  pledge "I pledge my honor that I have abided by the Stevens Honor System" ~JLi, Xavion
 */


/* int gcd(int a, int b);
bool isPrime(int a);
int countPrimes(int a, int b);
void collatz(int a);
double mean(double x[], int n);
int prod(int x[], int n);
void demean(double x[], int n);
void range_reverse(int x[], int n, int a, int b);
double hypot(double a, double b);
double mean(double a, double b);
bool pythagTriple(double a, double b);
double areaOfTriangle(double x1, double y1, double x2, double y2, double x3, double y3); */

int gcd(int a, int b) {
  int small;
  int large; //initialize ints for comparison
  int gcd1 = 0; //initialize variable before loop (C++ convention)
  if (a < b) { //checks which integer is larger and assigns that integer to int large
    small=a;
    large=b;
  } else {
    large=a;
    small = b;
  
  }

  for (uint64_t i = 1; i < small; i++) { //list starts at 1 an then counts up until small value
    if ((((small % i)==0) && ((large % i)==0))) { //if mod (remainder) of small and i is 0 AND is = to mod of large and i
      gcd1 = i; //will iterate up and keep placing larger CD until GCD is reached (end-ish of loop)
    }
  }
  return gcd1;
  }

bool isPrime(int a) {
  uint64_t b = a - 1; //initialize b as one less of a
  int truefalse = 0; //initialize variable before loop
  for (uint64_t i = 2; i <= b; i++) { //iterates up, if remainder of a and i isn't 0, return true as remainder means prime. otherwise false
    if ((a % i) != 0) {
      truefalse = 0;

    } 
    else {
      truefalse = 1;
      break;
    }
  }
  
  if(truefalse==1){ //correlates truefalse remainder of 1 or 0 to false and true (its opposite and weird)
    return false;
  }
  else if(truefalse==0){
    return true;
  }
}

int countPrimes(int a, int b) { 
  for(int i = a; i <= b; i++) { //takes isPrime function. iterates up and if the bool isPrime is true, it lists that prime
    if(isPrime(i) == true) {
      cout << i << '\n';
    }
  }
}

void collatz (int n) { 
    for(int i = 1; i++;){ //iterates through if and else if statements to eventually get to break case of 1
        if(n == 1){ // n==1 break case; end of program
            std::cout << n << '\n' << '\n';
            break;
        }
        if(n % 2 == 0) { //n % 2 == 0 means remainder of n/2 is 0 means it's even so divide by 2
            std::cout << n << '\n';
            n = n/2;
        }
        else if (n % 2 == 1){ //n % 2 == 0 means remainder of n/2 is 0 means it's odd so 3*n+1
            std::cout << n << '\n';
            n = 3*n+1;
        }
    }
}

double mean(double x[], int n) {
  double sum = 0; //initialize before loop
  double avg = 0; //initialize before loop
  for (uint64_t i = 0; i <= n - 1; i++) { // loop will add up all values in array except the nth value as that will mess up the multiplying
    sum += x[i];
  }

  avg = sum / n; //divide by n which in test case is the size of the array through sizeof(x)/sizeof(double)
  return avg;
}

int prod(int x[], int n) {

  int prod = 1; //initialize before loop
  for (uint64_t i = 0; i <= n - 1; i++) { //loop will multiply all values in array except the nth value as that will mess up the multiplying 
    prod *= x[i];
  }

  return prod;
}

void demean(double x[], int n) {
  int mean = 0;
  double sum = 0;
  double avg = 0;
  for (uint64_t i = 0; i <= n - 1; i++) {//gets the average of the function using for loop
    sum += x[i];
  }

  avg = sum / n;

  uint64_t min = x[0];//min=the integer that is the closest to the average
  uint64_t minDis = abs(x[0] - avg);//gets the value for how far the integer stored in variable "min" is from the mean, absolute value function used to take the magnitude only. Example, if the average is 5 and min is 3, minDis is 2, because min is 2 away from the average.
  for (int j = 0; j < n - 1; j++) {//uses for loop to compare the average of the array to each integer integer in the array, to find the integer closest to the average 
    if ((abs(x[j] - avg) < minDis)) {//comparison between inital min and x[j] to find the true closest number to the average in the array
      min = x[j];//if the condition is true, min will be set equal to the element in the array currently circuilating through the loop
      minDis = abs(x[j] - avg);//gets thew new distance between min and average
    }
  }
  for (uint64_t t = 0; t <= n - 1; t++) {//loop to subtract new min value, which is the interger closest to the average, from each element in the array
    x[t] = x[t] - min;
  }
 
}

void range_reverse(int x[],int n,int a,int b) {
uint64_t tempIndex;
uint64_t count1 = 0; //this counts backward from the largest index specified by the user
uint64_t count2 = 0; //this counts forward from the largest index specified by the user

if(b>a){//this if statement checks which integer specified is the higher of the two, for counting purposes
  count1 = b;
  count2 = a;
}else{
 count1 = a;
 count2 = b;
}

for (int i = count1; i >= count2;i--){//this begins a loop that starts from the end of the array segment specified by the user. Count1 is meant to store the element in the higher index, count2 the lower value. These values are set equal to each other, effecitvely swapping the elements place in the array
  if(count1!=count2){//this if statement ensures that if the two counts overlap(i.e, reach the middle of the array), nothing happens
    tempIndex=x[count2];//this variable, tempindex, is meant to temporarily hold one of the values before it is overwritten
    x[count2] = x[count1];//value that was stored in tempindex is overwritten
    x[count1] = tempIndex;//tempindex value used to properly adjust the second count
    count1--;//count1 goes down as count 2 goes up, moving to the next pair of elements to swap, ex.) if the elements are 1,2,3,4,5,6,7,8,9,10 then the swapping pattern is 1:10->2:9->3:8->4:7->5:6
    count2++;
  }else{

  }
 
}
 
}

double hypot(double a, double b){
    double hypot = pow(a,2) + pow(b,2); // does a^2+b^2 =h^2
    hypot = sqrt(hypot); // square roots hypothenus
    return hypot;
}

double mean(double a, double b) {
    double mean; //initialize variable
    mean = (a + b)/2; //average formula goes into mean
    return mean;
}

bool pythagTriple(double a, double b){
  int hypoth = pow(a,2) + pow(b,2); //new variable hypoth different from hypot from double hypot()
  hypoth = sqrt(hypoth); //doing same formula as double hypot
  if(hypot(a, b) == hypoth) { //double is more precise and allows for decimals, int doesn't; if a number had decimals, it would make the hypotenus not whole #
    return true;
  }
  else {
    return false; //if the conditions dont match, int hypoth resulted in a whole number (whole # test cases)
  }
}

double areaOfTriangle(double x1, double y1, double x2, double y2, double x3, double y3){
  double a, b, c, s, area; //initialize variables beforehand
  a = sqrt((pow((x2-x1),2) + pow((y2-y1),2))); // calculate distance formula for a
  b = sqrt((pow((x3-x2),2) + pow((y3-y2),2))); // calculate distance formula for b
  c = sqrt((pow((x3-x1),2) + pow((y3-y1),2))); // calculate distance formula for c
  s = .5*(a+b+c); // calculate s (1/2)(a+b+c)

  return area = sqrt(s * (s-a) * (s-b) * (s-c)); // area formula using Area = sqrt(s(s-a)(s-b)(s-c))

}

int main() {
    cout << "gcd(12, 18)=" << gcd(12, 18) << '\n';
    cout << "gcd(1025, 3025)=" << gcd(1025, 3025) << '\n';
    cout << "isPrime(5)=" << isPrime(5) << '\n';
    cout << "isPrime(9)=" << isPrime(9) << '\n';
    cout << "isPrime(1001)=" << isPrime(1001) << '\n';
    cout << "isPrime(2601)=" << isPrime(2601) << '\n';
    cout << "isPrime(1013)=" << isPrime(1013) << '\n';

    cout << "countPrimes(1,100): " << countPrimes(1, 100) << '\n';
    cout << "countPrimes(1,10000): " << countPrimes(1, 10000) << '\n';

    collatz(5); // should print out 5 16 8 4 2 1
    collatz(40); // should print out 40 20 10 5 16 8 4 2 1
    collatz(17); // should print out 17 52 26 13 40 20 10 5 16 8 4 2 1

    double x[] = {10, 20, 30, 40, 50, 60};
    constexpr int n = sizeof(x)/sizeof(double);
    cout << mean(x, n) << '\n'; // should print 35

    double y[] = {1.0, 2.0, 3.0, 4.0};
    cout << mean(y, sizeof(y)/sizeof(double)) << '\n'; // should print 2.5

    int a[] = {3, 4, 1, 2, -2};
    cout << prod(a, sizeof(a)/sizeof(int)) << '\n';

    int b[] = {2, 4, 8, -2, -4};
    cout << prod(b, sizeof(b)/sizeof(int)) << '\n';

    demean(x, n); // should subtract the mean from each element
    for (int i = 0; i < n; i++)
        cout << x[i] << ' ';
    cout << '\n';

    int c[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    range_reverse(c, 9, 2, 4);

    //you should print out the array c
    for (int i = 0; i < sizeof(c)/sizeof(int); i++)
        cout << c[i] << ' '; // should print 1 2 5 4 3 6 7 8 9
    cout << '\n';

    cout << "hypot(3,4)=" << hypot(3, 4) << '\n'; // should print 5
    cout << "hypot(4,5)=" << hypot(4, 5) << '\n'; // 
    cout << "mean(3.0,sqrt(8.0)) = " << mean(3.0,sqrt(8.0)) << '\n';

    cout << "mean(1,4)=" << mean(1, 4) << '\n';

    cout << "if sqrt(3**2 +4**2) is a whole number?: " << pythagTriple(3, 4)
       << endl;
    cout << "if sqrt(2**2 +3**2) is a whole number?: " << pythagTriple(2, 3)
       << endl;

    cout << areaOfTriangle(0,0, 10,0, 10,5) << '\n'; // should be approx 25
    cout << areaOfTriangle(0,0, 5,3, 2,6) << '\n'; //should be approx 12

    return 0;
}