# Grade: 100%
# CPE 390 - Microprocessor System <br>
# Lab 1: <br>
**Submission Requirements** <br>
**For lab 1, only need to submit codes in part(4)** <br>
**Can find assignment 'lab 1 submission' on Canvas** <br>
**Can submit three C++ files (.cc/.cpp) or can merge three functions together** <br>

**(1) Set up environment on laptop** <br>
**For Windows users:** <br>
Set up MSYS2 environment: <br>
a. Install msys2 https://www.msys2.org/ <br>
choose "64--bit" version <br>

b. install packages <br>
&nbsp;&nbsp;&nbsp;&nbsp; Install gcc: `pacman -S mingw-w64-x86_64-gcc` <br>
&nbsp;&nbsp;&nbsp;&nbsp; Install make: `pacman -S make` <br>
&nbsp;&nbsp;&nbsp;&nbsp; Install gdb: `pacman -S mingw-w64-x86_64-gdb` <br>
&nbsp;&nbsp;&nbsp;&nbsp; Install emacs: `pacman -S mingw-w64-x86_64-emacs` <br>
&nbsp;&nbsp;&nbsp;&nbsp; Install git: `pacman -S git` <br>

c. Add environment path: <br>
&nbsp;&nbsp;&nbsp;&nbsp; `C:\msys64\mingw64\bin` <br>
&nbsp;&nbsp;&nbsp;&nbsp; `C:\msys64\usr\bin` <br>

d. Simple Test <br>
Run "Hello world!" by emacs <br>
open Terminal and type: `emacs test.cc` <br>

```
#include <iostream> <br>
using namespace std;
int main() { 
cout << "hello world"; 
}
```

type: `g++ -g test.cc` <br>
type: `./a.exe` <br>
Learn to get version of programming environment <br>
`gcc --version` <br>
`gdb --version` <br>
=====================================================
**(2) Some basic instructions for using git in Linux System.** <br>
Reference in case need it <br>
https://drive.google.com/open?id=1kSknsnRPqe1-DSIx-r9alMr1drEHzgzzXxqCkdlnHGk <br>
a. Create github id if do not already have one <br>
&nbsp;&nbsp;&nbsp;&nbsp; Check Page 8 in PowerPoint <br>
b. Set up SSH password <br>
&nbsp;&nbsp;&nbsp;&nbsp; Check Page 11 in PowerPoint <br>
c. Set username and email <br>
&nbsp;&nbsp;&nbsp;&nbsp; git config --global username <br>
&nbsp;&nbsp;&nbsp;&nbsp; git config --global user.email 'your email address' <br>
d. Clone repo into terminal <br>
&nbsp;&nbsp;&nbsp;&nbsp; git clone git@github.com:fyang14/EE390-2022S-Lab-Section-A.git <br>

Note that: <br>
Please leave information (Name, Github id, email address) in link below. <br>
[REDACTED] <br>

**(3) Install VSCode** <br>
Starting from step 2 to step 8 (will do rest part in next Lab) <br>
https://github.com/StevensDeptECE/CPE390/blob/master/Course%20Documentation/Instructions%20for%20Installing%20VSCode.md <br>

**(4) Coding part (need submission on Canvas)** <br>
a. Write program that prints name, compile and run it on command line. Note that g++ command line examples are in appendix at end of course notes <br>
b. Write program that reads in 2 numbers from standard input and go in loop printing all those numbers on single line. For example, given input: 2 5 <br>
output should be: <br>
2 3 4 5 <br>
Can use cin to read in from keyboard: <br>
```
  int start, end;
  cin >> start >> end;
```
c. Write program to read in integer size of multiplication table and print out table. <br>
For example, given input 5: <br>
output should be:
1 2 3 4 5 <br>
2 4 6 8 10 <br>
3 6 9 12 15 <br>
4 8 12 16 20 <br>
5 10 15 20 25 <br>