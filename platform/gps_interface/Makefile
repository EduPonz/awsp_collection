# define constants
CXXFLAGS = -Wall -O
CXX=g++

gps: gps.o gps_interface.o
	$(CXX) $(CXXFLAGS) -o gps gps.o gps_interface.o -lwiringPi

gps.o: gps.cpp
	$(CXX) $(CXXFLAGS) -c gps.cpp

gps_interface.o: gps_interface.hpp gps_interface.cpp
	$(CXX) $(CXXFLAGS) -c gps_interface.cpp

clean: 
	rm -f *.o
