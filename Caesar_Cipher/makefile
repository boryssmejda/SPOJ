CXX = g++
CXXFLAGS = -g -Wall -Wextra -Wshadow -Wnon-virtual-dtor -pedantic -std=c++17
objects = main.o CaesarCipher.o
target = caesar

all: $(target)

${target}: $(objects)
	$(CXX) $(CXXFLAGS) -o ${target} $(objects) -lpthread

main.o: main.cpp CaesarCipher.hpp
	$(CXX) $(CXXFLAGS) $< -c -lpthread

CaesarCipher.o: CaesarCipher.cpp CaesarCipher.hpp
	$(CXX) $(CXXFLAGS) $^ -c -lpthread

clean:
	rm -f $(objects) $(target)

