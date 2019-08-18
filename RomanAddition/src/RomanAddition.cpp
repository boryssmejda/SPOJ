#include "RomanAddition.hpp"

int RomanNumber::toDecimal()
{
	int numberLength = static_cast<int>(m_romanNumber.length());

	if (numberLength <= 0) {
		throw std::invalid_argument("Length of number too short!");
	}

	if (!isCorrectRomanNumber())
		throw std::invalid_argument("It is not a roman number");

	auto findFirst = [&](number n) {return std::string(1,m_romanNumber[0]) == n.roman; };
	int previous = std::find_if(m_dictionary.begin(), m_dictionary.end(), findFirst)->decimal;

	int result = previous;
	for (int i = 1; i < numberLength; ++i) {
		
		auto it = std::find_if(m_dictionary.begin(), m_dictionary.end(), [&](number n) {return std::string(1, m_romanNumber[i]) == n.roman; } );
		result += it->decimal;

		if (it->decimal > previous) {
			result -= 2 * previous;
		}
		
		previous = it->decimal;
	}

	m_decimalForm = result;
	return m_decimalForm;
}

bool RomanNumber::isCorrectRomanNumber()
{
	//TODO: ADD CHECKING IF GIVEN STRING IS REALLY A ROMAN NUMBER
	return true;
}

std::string RomanNumber::toRoman()
{
	int dec = m_decimalForm;
	std::string romanNum("");

	int divisor = 10;
	while (dec > 0) {
		int currentNumber = dec % divisor;
		
		//convert current digit to roman
		std::string romanDigit = convertCurrentDigitToRoman(currentNumber);
		
		//push current roman digit to front of the string
		romanNum.insert(0, romanDigit);

		dec -= currentNumber;
		divisor *= 10;
	}

	m_romanNumber = romanNum;
	return romanNum;
}

std::string RomanNumber::convertCurrentDigitToRoman(int num) {

	std::string finalDigit("");

	while (num > 0) {
		std::pair<std::string, int> notBigger = findRomanNumberNotBiggerThanCurrent(num);
		finalDigit += notBigger.first;

		num -= notBigger.second;
	}

	return finalDigit;
}

std::pair<std::string, int> RomanNumber::findRomanNumberNotBiggerThanCurrent(int number) {

	std::pair<std::string, int> maxElement;
	for (auto it = m_dictionary.begin(); it != m_dictionary.end(); it++) {
		if (it->decimal > number) {
			break;
		}
		
		maxElement = std::make_pair(it->roman, it->decimal);
	}

	return maxElement;
}

RomanNumber::RomanNumber(std::string roman) :m_romanNumber{ roman }, m_decimalForm{0} {toDecimal();}

RomanNumber::RomanNumber(int decimal)
{
	this->m_decimalForm = decimal;
	toRoman();
}

RomanNumber& RomanNumber::operator=(const RomanNumber& r)
{
	return *this;
}

std::istream& operator>>(std::istream& in, RomanNumber& r)
{
	in >> r.m_romanNumber;
	return in;
}

std::ostream& operator<<(std::ostream& out, RomanNumber& r)
{
	out << r.m_romanNumber << std::endl;
	return out;
}

RomanNumber operator+(RomanNumber l, RomanNumber r)
{
	RomanNumber result;
	result.m_decimalForm = l.m_decimalForm + r.m_decimalForm;
	result.toRoman();
	return result;
}
