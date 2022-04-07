extern "C" {
    void f(); //_f
  int f(int a, int b);
}

void f(int x[]); //_Z1fPi

void f(const int x[]); // _Z1fPki

void f(const int x[], const int y[], const int z[]) //_Z1fPki2S