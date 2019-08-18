#include "RomanAddition.hpp"

int RomanNumber::toDecimal()
{
	int numberLength = static_cast<int>(m_romanNumber.length());

	if (numberLength <= 0) {
		throw std::invalid_argument("Length of number too short!");
	}

	if (!isCorrectRomanNumber())
		throw std::invalid_argument("It is not a roman number");

	int previous = dictionary.find(std::string(1, m_romanNumber[0]))->second;
	int result = previous;
	for (int i = 1; i < numberLength; ++i) {
		
		auto it = dictionary.find(std::string(1, m_romanNumber[i]));
		result += it->second;

		if (it->second > previous) {
			result -= 2 * previous;
		}
		
		previous = it->second;
	}

	m_decimalForm = result;
	return m_decimalForm;
}

bool RomanNumber::isCorrectRomanNumber()
{
	return true;
}

std::string RomanNumber::toRoman()
{
	return std::string("j");
}

RomanNumber::RomanNumber(std::string roman) :m_romanNumber{ roman }, m_decimalForm{0} {
	toDecimal();
}

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
	return result;
}
