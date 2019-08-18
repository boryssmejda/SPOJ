#include "RomanAddition.hpp"
#include <iostream>
#include <vector>

int main() {

	int nrNumbers;
	std::cin >> nrNumbers;
	std::vector<RomanNumber> resultsOfAddition;

	while(true){
		RomanNumber first, second;
		std::cin >> first >> second;
		if(std::cin.eof()) {
			break;
		}
		resultsOfAddition.push_back(first + second);
	}

	for (RomanNumber r : resultsOfAddition)
		std::cout << r;

	
}