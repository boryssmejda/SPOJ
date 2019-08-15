#include "number_converter.hpp"

class NumberConverter {
private:
	std::array<std::string, 36> digits
	{ "0", "1" , "2" , "3" , "4" , "5" , "6" , "7" , "8", "9" , "A" , "B" , "C" , "D", "E", "F" , "G" , "H" , "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z" };
	std::string m_numberToBeConverted;
	std::string m_convertedNumber;
	int m_convertFromBase, m_convertToBase;


	std::string convertToTargetBase(unsigned long long t_base10Representation) {

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

public:
	NumberConverter(int t_fromBase, int t_toBase, std::string t_number)
		:m_convertFromBase(t_fromBase), m_convertToBase(t_toBase),
		m_numberToBeConverted(t_number)
	{
		m_convertedNumber = "";
	}

	std::string convertNumber() {

		unsigned long long base10Representation = std::stoull(m_numberToBeConverted, nullptr, m_convertFromBase);

		m_convertedNumber = convertToTargetBase(base10Representation);

		return m_convertedNumber;
	}

};

