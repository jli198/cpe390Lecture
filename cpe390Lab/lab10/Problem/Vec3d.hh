#pragma once

#include <iostream>

class Vec3d {
public:
	double x, y, z;
	Vec3d(double x = 0, double y = 0, double z = 0) :
		x(x), y(y), z(z) {}
	friend Vec3d operator +(const Vec3d& a, const Vec3d& b);
	friend Vec3d operator -(const Vec3d& a, const Vec3d& b);
	
	friend Vec3d operator -(const Vec3d& a) {
		return Vec3d(-a.x, -a.y, -a.z);
	}

	friend void operator +=(Vec3d& a, const Vec3d& b) {
		a.x += b.x; a.y += b.y; a.z += b.z;
	}
	
	// compute scalar * vector and return the vector
	friend Vec3d operator *(double s, const Vec3d& v) {
		return Vec3d(s * v.x, s * v.y, s * v.z);
	}

	// compute scalar * vector and return the vector
	friend Vec3d operator *(const Vec3d& v, double s) {
		return Vec3d(s * v.x, s * v.y, s * v.z);
	}

	friend double dot(const Vec3d& a, const Vec3d& b) {
		return a.x*b.x + a.y*b.y + a.z*b.z;
	}
	
	double mag() const;
	
	friend std::ostream& operator <<(std::ostream& s, const Vec3d& v);
};
