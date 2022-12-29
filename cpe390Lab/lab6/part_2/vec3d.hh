#pragma once
#include <cmath>

/*
Lab 6 - Part 2
AUTHOR: JLi, Xavion
CITE: Jacob - made me understand distance formula with OOP (a.x+b.x), etc. 
PLEDGE: "I pledge my honor that I have abided by the Stevens Honor System" ~JLi, Xavion
*/

class vec3d {
private:
  double x1, y1, z1;
public:
	double x,y,z; // every 3d vector has x y z
	// TODO: 
  vec3d(int x1, int y1, int z1) : x1(x), y1(y), z1(z) {}

  // this is method (member function)
  // this is called with a.add(b) and returns vector
  vec3d add(vec3d b) const { // <= const here means read only
    // (this method does not change object it is called on)
    return vec3d(this->x+b.x, this->y+b.y, this->z+b.z);
    // calling construtor creates unamed temp
    // it goes away by ; but if it is returned, that's the answer
  }

  // same code as above but as operator
  // called with c = a + b

  friend vec3d operator + (const vec3d& a, const vec3d& b) {
    return vec3d(a.x+b.x,a.y+b.y,a.z+b.z);
  }

  // this is friend function
  // add(a,b)
  friend vec3d add(const vec3d& a, const vec3d& b) {
    return vec3d(a.x+b.x,a.y+b.y,a.z+b.z);
  }

  // compute length of vector
  friend double dist(const vec3d &a, const vec3d &b) {
    return(sqrt((a.x-b.x) * (a.x-b.x)) + (a.y-b.y) * (a.y-b.y) + (a.z-b.z) * (a.z-b.z));
  }

  // compute distance between a and b
  double mag() {
    return(sqrt((this->x) * (this->x)) + (this->y) * (this->y) + (this->z) * (this->z));
  }
};
