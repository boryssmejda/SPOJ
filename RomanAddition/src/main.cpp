#include "number_converter.hpp"
#include <iostream>
#include <vector>

int main() {

	int nrNumbers;
	std::cin >> nrNumbers;
	std::vector<NumberConverter> numbersToBeConverted;
	for (int i = 0; i < nrNumbers; i++) {
		std::string num;
		int baseFrom, baseTo;
		std::cin >> num >> baseFrom >> baseTo;
		NumberConverter n(baseFrom, baseTo, num);
		numbersToBeConverted.push_back(n);
	}

	for (NumberConverter n : numbersToBeConverted) {
		std::cout << n.convertNumber() << std::endl;
	}
}