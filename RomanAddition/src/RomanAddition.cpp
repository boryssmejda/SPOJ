#include "RomanAddition.hpp"

RomanNumber::RomanNumber(std::string roman) : decimalForm{ 0 }, romanNumber{roman} {}

RomanNumber& RomanNumber::operator=(const RomanNumber& r)
{
	return *this;
}

std::istream& operator>>(std::istream& in, RomanNumber& r)
{
	in >> r.romanNumber;
	return in;
}

std::ostream& operator<<(std::ostream& out, RomanNumber& r)
{
	out << r.romanNumber << std::endl;
	return out;
}

RomanNumber operator+(RomanNumber l, RomanNumber r)
{
	return RomanNumber("X");
}
