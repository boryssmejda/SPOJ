#include "BigMultiplication.hpp"
#include <vector>
#include <iostream>
#include <utility>
#include <string>
#include <sstream>
#include <limits>

using namespace std;

int main() {

	int numPairs{ 0 };
	std::cin >> numPairs;
	std::cin.clear();
	std::cin.ignore(numeric_limits<streamsize>::max(), '\n');

	std::vector<std::pair<BigMultiplier, BigMultiplier>> results;
	results.reserve(numPairs);

	for (int i = 0; i < numPairs; i++) {
		
		std::string line;
		getline(std::cin, line);
		std::stringstream ss(line);

		std::string a, b;
		getline(ss, a, ' ');
		getline(ss, b);

		results.emplace_back(std::make_pair(BigMultiplier(a), BigMultiplier(b)));
	}

	std::vector<BigMultiplier> finalResults;
	finalResults.reserve(numPairs);
	for (int i = 0; i < numPairs; i++) {
		finalResults.emplace_back(results[i].first * results[i].second);
	}

	for (BigMultiplier b : finalResults) {
		std::cout << b;
	}

}