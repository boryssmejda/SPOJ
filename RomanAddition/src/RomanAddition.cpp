#include "number_converter.hpp"

std::string NumberConverter::convertToTargetBase(unsigned long long t_base10Representation) {

	if (t_base10Representation == 0) {
		return "0";
	}

	std::string result("");
	while (t_base10Representation > 0) {

	int currentDigit = t_base10Representation % m_convertToBase;

		std::string digitInTargetBase = digits[currentDigit];

		result += digitInTargetBase;
		t_base10Representation /= m_convertToBase;

	}

	std::reverse(result.begin(), result.end());
	return result;
}

NumberConverter::NumberConverter(int t_fromBase, int t_toBase, std::string t_number)
		:m_convertFromBase(t_fromBase), m_convertToBase(t_toBase),
		m_numberToBeConverted(t_number)
{
	m_convertedNumber = "";
}

std::string NumberConverter::convertNumber() {

	unsigned long long base10Representation = std::stoull(m_numberToBeConverted, nullptr, m_convertFromBase);

	m_convertedNumber = convertToTargetBase(base10Representation);

	return m_convertedNumber;
}


