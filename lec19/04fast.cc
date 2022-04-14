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
  const int n = 1024*1024*100;
  const int BUFSIZE=1024;
  int buf[BUFSIZE];
  // 2**12 = 4096
  // 2**20 = 1M
  // 2**8 = 256
  for (int x = 0; x < n; x+= BUFSIZE) {
      for (int i = 0; i < BUFSIZE; i++)
        buf [ i ] = x + i;
    int bytesWriten = write(fh, buf, sizeof(buf));
  }
  close(fh);
}