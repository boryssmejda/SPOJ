#include "PointsInTriangle.hpp"
#include <iostream>
#include <vector>
#include <exception>

int main() {

	std::vector<std::string> results;
	while (true) {
		geometry::Point a, b, c, p;
		std::cin >> a >> b >> c >> p;

		if (geometry::shouldFinish(a, b, c, p)) {
			break;
		}

		geometry::Triangle t(a, b, c, 0);
		results.push_back(t.determine_exact_position(p));
		
	}

	for (const auto& r : results)
		std::cout << r << "\n";
	
}