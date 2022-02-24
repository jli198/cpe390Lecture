#include "vec3d.hh"

int main() {
  vec3d a(1,2,3);
  vec3d b(1,2,2.1, -1.3);
  vec3d c = a + b;
  vec3d d = a.add(b);
  ved3d e = add(a,b);
  double mag = c.mag();
}