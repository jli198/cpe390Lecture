#include "GravSim.hh"

int main(int argc, char* argv[]) {
	GravSim sim("solarsys.dat");
	const double secondsInYear = 365.2425 * 24 * 60 * 60;
	const double dt = 10;
	const uint32_t numTimeSteps = uint32_t(secondsInYear / dt);
	const uint32_t numStepsPerPrint = numTimeSteps;
	for (uint32_t i = 0; i < numTimeSteps; i+= numStepsPerPrint) {
		sim.forward(numStepsPerPrint, dt);
	}
}
