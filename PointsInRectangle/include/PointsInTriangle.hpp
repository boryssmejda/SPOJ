#include <array>
#include <iostream>
#include <string>

struct Point {
	int xCoordinate, yCoordinate;
};

struct Triangle {
	Point a, b, c;
	Triangle(Point a, Point b, Point c) : a{ a }, b{ b }, c{ c }{};
};

std::string determinePosition() {

}