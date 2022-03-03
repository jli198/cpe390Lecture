#include "vec3d.hh"

int main() {
  vec3d a(1,2,3); // note 1 --> 1.0, 2--> 2.0, 3--> 3.0 "type promotion"
  vec3d b(1.2, 2.1, -1.3);
  vec3d c = a + b;
  double mag = c.mag(); // length of vector
}