#include <BigMultiplication.hpp>
#include <vector>
#include <iostream>
#include <utility>

int main() {

	int numPairs{ 0 };
	std::cin >> numPairs;

	std::vector<std::pair<BigMultiplier, BigMultiplier>> results;
	results.reserve(numPairs);

	for (int i = 0; i < numPairs; i++) {
		
		std::string a, b;
		std::cin >> a >> b;

		results[i] = std::make_pair(BigMultiplier(a), BigMultiplier(b));
	}

	std::vector<BigMultiplier> finalResults;
	finalResults.reserve(numPairs);
	for (int i = 0; i < numPairs; i++) {
		finalResults[i] = results[i].first * results[i].second;
	}

	for (BigMultiplier b : finalResults) {
		std::cout << b;
	}

}