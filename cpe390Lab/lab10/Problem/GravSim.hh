#pragma once

#include <iostream>
#define _USE_MATH_DEFINES 
#include <cmath>
#include <cstring>
#include <vector>

constexpr double G = 6.67408e-11;

// below is from vec3d.hh w/ vec3d.cc inserted
class Vec3d {
 public:
  double x, y, z;
  Vec3d(double x = 0, double y = 0, double z = 0) : x(x), y(y), z(z) {}

  friend Vec3d operator+(const Vec3d& a, const Vec3d& b) {
    return Vec3d(a.x + b.x, a.y + b.y, a.z + b.z);
  }

  friend Vec3d operator-(const Vec3d& a, const Vec3d& b) {
    return Vec3d(a.x + b.x, a.y + b.y, a.z + b.z);
  }

  friend Vec3d operator-(const Vec3d& a) { return Vec3d(-a.x, -a.y, -a.z); }

  friend void operator+=(Vec3d& a, const Vec3d& b) {
    a.x += b.x;
    a.y += b.y;
    a.z += b.z;
  }

  // compute scalar * vector and return the vector
  friend Vec3d operator*(double s, const Vec3d& v) {
    return Vec3d(s * v.x, s * v.y, s * v.z);
  }

  // compute scalar * vector and return the vector
  friend Vec3d operator*(const Vec3d& v, double s) {
    return Vec3d(s * v.x, s * v.y, s * v.z);
  }

  friend double dot(const Vec3d& a, const Vec3d& b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
  }

  // formula pasted in
  double mag() const { return sqrt(x * x + y * y + z * z); }

  friend std::ostream& operator<<(std::ostream& s, const Vec3d& v);
};

class Body {
private:
	char name[16];
	double m; // mass of the body
	double Gm; // precomputed G*m for speed
	Vec3d pos;
	Vec3d v;
	Vec3d a;
	friend class GravSim;
public:
	Body(const char name[16],
			 const char orbits[16],
			 double m,
			 double x, double y, double z,
			 double vx, double vy, double vz);
	friend std::ostream& operator <<(std::ostream& s, const Body& b);
	Vec3d gravAccel(const Body& b) const;
};

class GravSim {
public:
private:
	double t;
	std::vector<Body> bodies;
public:
	GravSim(const char filename[]);
	void timestep(double dt);
	void forward(uint32_t n, double dt);
	friend std::ostream& operator <<(std::ostream& s, const GravSim& sim);
};

