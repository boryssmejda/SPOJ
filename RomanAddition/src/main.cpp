#include "RomanAddition.hpp"
#include <iostream>
#include <vector>

int main() {

	int nrNumbers;
	std::cin >> nrNumbers;
	std::vector<RomanNumber> resultsOfAddition(nrNumbers);

	for (int i = 0; i < nrNumbers; i++) {
		RomanNumber first, second;
		std::cin >> first >> second;
		resultsOfAddition[i] = first + second;
	}

	for (RomanNumber r : resultsOfAddition)
		std::cout << r;

	
}