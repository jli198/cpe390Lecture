DEBUG	:= -g
OPT	:= -O2
CXX	:= g++ -std=c++11 $(DEBUG) $(OPT)

gravsim: GravSim.o main.o
	$(CXX) GravSim.o main.o -o gravsim

GravSim.o: GravSim.cc GravSim.hh
	$(CXX) -c GravSim.cc

main.o: main.cc GravSim.hh
	$(CXX) -c main.cc

clean:
	rm *.o gravsim