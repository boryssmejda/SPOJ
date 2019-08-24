#include <BigInteger.hpp>
#include <iostream>
#include <vector>

int main() {

	int nrSetsOfNumbers;
	std::cin >> nrSetsOfNumbers;
	std::vector<BigInteger> sets;

	for (int i = 0; i < nrSetsOfNumbers; i++) {
		std::string first, second;
		std::cin >> first, second;
		BigInteger a(first), b(second);
		BigInteger result = a + b;
		sets.push_back(result);
	}

	for (BigInteger b : sets)
		std::cout << b;

	
}