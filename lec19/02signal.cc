#include <iostream>
#include <signal.h>
#include <unistd.h>
using namespace std;

void handle_controlc(int sig) {
  cout << "you pressed control C!'\n";
}

int main() {
  signal(SIGINT, handle_controlc);
  for (;;) { // (;;) <-- means infinite loop, loop forever, (ALWAYS), cuz ;; with no conditions means inf
    cout << "hello\n";
    usleep(200000);
  }
}