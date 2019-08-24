#include <BigInteger.hpp>
#include <iostream>
#include <vector>
#include <sstream>

int main() {

	int nrSetsOfNumbers;
	std::cin >> nrSetsOfNumbers;
	std::cin.ignore();

	std::vector<BigInteger> sets;

	for (int i = 0; i < nrSetsOfNumbers; i++) {
		std::string input, first, second;
		std::getline(std::cin, input);

		std::stringstream ss(input);
		ss >> first >> second;

		BigInteger a(first), b(second);
		BigInteger result = a + b;
		sets.push_back(result);
	}

	for (BigInteger b : sets)
		std::cout << b;

	
}