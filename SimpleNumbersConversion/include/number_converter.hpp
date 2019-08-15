#ifndef  NUMBER_CONVERTER
#define  NUMBER_CONVERTER

#include <vector>
#include <iostream>
#include <string>
#include <array>
#include <algorithm>

class NumberConverter {
private:
	std::array<std::string, 36> digits
	{ "0", "1" , "2" , "3" , "4" , "5" , "6" , "7" , "8", "9" , "A" , "B" , "C" , "D", "E", "F" , "G" , "H" , "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z" };
	std::string m_numberToBeConverted;
	std::string m_convertedNumber;
	int m_convertFromBase, m_convertToBase;


	std::string convertToTargetBase(unsigned long long t_base10Representation);

public:
	NumberConverter(int t_fromBase, int t_toBase, std::string t_number);
	std::string convertNumber();
	NumberConverter(){}
};

#endif // ! NUMBER_CONVERTER
