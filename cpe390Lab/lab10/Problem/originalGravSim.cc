/* 
Lab 10 - Graviation Simulator Optimization
Author: JLi
Cite: Alejandro - Showed us logic of Horner's Form of Quadratic Formulas, amag/r & amag reductions
Pledge: "I pledge my honor that I have abided by Stevens Honor System." ~JLi
*/

#include "GravSim.hh"
#include <fstream>
#include <iomanip>
#include <sstream>
#include <cstring>
#include <vector>
#include <random>
#include <unordered_map>

using namespace std;
	
std::ostream& operator <<(std::ostream& s, const Vec3d& v) {
	return s << v.x << ',' << v.y << ',' << v.z;
}

Body::Body(const char name[16],
					 const char orbits[16],
					 double m,
					 double x, double y, double z,
					 double vx, double vy, double vz) :
	m(m),
	pos(x,y,z), v(vx, vy, vz), a() {
	strncpy(this->name, name, 16);
}

ostream& operator <<(ostream& s, const Body& b) {
	return s << b.name << "\t\t" << b.pos << "\t\t" << b.v << "\t\t" << b.a;
}

default_random_engine gen(0); // always select same random numbers for debugging
uniform_int_distribution<int> dist(1,6);
normal_distribution<double> angle(0,2*M_PI);
unordered_map<string,Body*> bodiesByName;

GravSim::GravSim(const char filename[]) {
	t = 0;
	ifstream f(filename);
	char buf[4096];
	f.getline(buf, sizeof(buf)); // skip the first line with the metadata
	char name[16];
	char orbits[16];
	double m, diam, perihelion, aphelion, x,y,z, vx, vy, vz;
	double orbPeriod, rotPeriod;
	cout << "Name\tPosition\t\tVelocity\t\tAcceleration\n" << setprecision(15);
	while (!f.eof()) {
		f.getline(buf, sizeof(buf));
		istringstream line(buf);
		line >> name >> m >> diam >> perihelion >> aphelion >>
			orbPeriod, rotPeriod;
		//		double theta = angle(gen); // pick a random angle to start the orbit
		const double theta = 0; // pick single value for testing, all planets lined up on x axis
		
		double r = (perihelion + aphelion) / 2;
		// compute x,y,z for the body
		double x = r * cos(theta), y = r * sin(theta), z = 0;

		// handle special case for sun: if r = 0, then v = 0
		double v = r == 0 ? 0 : sqrt(G*m * (2 / r - 1 / aphelion));

		double vx = -v * sin(theta), vy = v * cos(theta), vz = 0;
		bodies.push_back(Body(name, orbits, m,  x, y, z, vx, vy, vz)); // eliminate the pointer. Single block of linear memory
		bodiesByName[orbits] = &bodies.back();
		cout << bodies.back() << '\n';
	}
}

// Hint: making this function inline might have a small effect
Vec3d Body::gravAccel(const Body& b) const { // Hint: most of the speed problems are in this function
	Vec3d dpos = pos - b.pos;
	double r = dpos.mag();
	double amag = G * b.m / r/r; // precomputed Gm and only a single division
	return Vec3d(dpos.x*amag/r, dpos.y*amag/r, dpos.z*amag/r); // eliminated division
}

/*
	Calculate all bodies accelerations and
	step forward in time
 */
void GravSim::timestep(double dt) {
	for (int i = 0; i < bodies.size(); i++) {
		Vec3d a; // Define a scalar acceleration (will be in registers)
		for (int j = 0; j < bodies.size(); j++)
			if (i != j)
				a = a + bodies[i].gravAccel(bodies[j]); // This calls operator + in class Vec3d. inlining might be faster
		bodies[i].a = a;
	}

	for (int i = 0; i < bodies.size(); i++) {
		bodies[i].pos = bodies[i].pos +	0.5 * bodies[i].a * pow(dt,2) + bodies[i].v * dt; // Hint: Horner's form is faster
		bodies[i].v += bodies[i].a * dt;
	}
	t += dt;
}

void GravSim::forward(uint32_t n, double dt) {
	for (uint32_t i = 0; i < n; i++) {
		timestep(dt);
	}
	cout << *this;
}

std::ostream& operator <<(std::ostream& s, const GravSim& sim) {
	s << "GravSim t=" << sim.t << '\n';
	for (auto b : sim.bodies)
		s << b << '\n';
	return s;
}
