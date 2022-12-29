#include "vec3d.hh"

int main() {
	vec3d a(1,2,3); // call constructor set x=1, y=2, z=3
	vec3d b(1.2, 3.1, -1.6);
	vec3d c = a + b; // implement operator +
	cout << c << '\n';

	vec3d d = a.add(b); // implement add method
	cout << d << '\n';

	double len = a.mag(); // compute the length of the vector
	cout << len << '\n';

	cout << dist(a,b) << '\n'; // compute the distance between a and b
}
