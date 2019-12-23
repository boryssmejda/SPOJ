CXX = g++
CXXFLAGS = -g -Wall -Wextra -Wshadow -Wnon-virtual-dtor -pedantic -std=c++17
objects = main.o MaxDistance.o

all: gymnast

gymnast: $(objects)
	$(CXX) $(CXXFLAGS) -o gymnast $(objects)

main.o: main.cpp MaxDistance.hpp
	$(CXX) $(CXXFLAGS) $< -c

MaxDistance.o: MaxDistance.cpp MaxDistance.hpp
	$(CXX) $(CXXFLAGS) $^ -c

clean:
	rm -f $(objects) gymnast

