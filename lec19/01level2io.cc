#include <iostream>
#include <unistd.h>
#include <fcntl.h>

using namespace std;
//open( ) { if (are allowed to open file) openthefile();}

int main() {
  int fh = open("test.dat", O_CREAT | O_WRONLY /*| O_RDONLY*/);
  // fh is file handle, index into array of files for my process
  //under hood, call is made with svc #0
  if (fh < 0) {
    cerr << "error, can't open test.dat";
    return -1; 
  }
  char cstring[] = "letters terminated by nul char"; // \'0'
  
  char msg[] = "ELFtesting testing 123;";
  msg[0] = 0x7f;
  int bytesWritten = write(fh, msg, sizeof(msg));
  cout << "we wrote: " << bytesWritten << '\n';
  close(fh);
}