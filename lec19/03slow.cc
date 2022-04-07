#include <iostream>
#include <unistd.h>
#include <fcntl.h>

using namespace std;

int main() {
  int fh = open("test.dat", O_CREAT, O_WRONLY, O_RDONLY);
  // under hood, call is made with svc #0
  if (fh < 0) {
    cerr << "error, can't open test.dat";
    return -1;
  }
  const int BUFSIZE=1024;
  int buf[BUFSIZE];
  for (int x = 0; x < 1000000; x++) {
      for (int i = 0; i < BUFSIZE; i++)
        buf [ i ] = x+i;
    int bytesWriten = write(fh, &x, 4);
  }
  close(fh);
}