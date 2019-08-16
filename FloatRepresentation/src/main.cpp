#include <iostream>
#include "floatRepresentation.hpp"
#include <vector>

int main() {

	int nrTests;
	std::cin >> nrTests;

	std::vector<FloatRepresentation> ff(nrTests);
	for (int i = 0; i < nrTests; i++) {
		float f;
		std::cin >> f;
		FloatRepresentation f_repr(f);
		ff[i] = f_repr;
	}

	for (FloatRepresentation f : ff) {
		std::cout << f.getFloatHexRepresentation() << std::endl;
	}
}