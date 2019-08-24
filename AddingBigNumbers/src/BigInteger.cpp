#include "BigInteger.hpp"

BigInteger& BigInteger::operator=(const BigInteger& b)
{
	// TODO: insert return statement here
	this->m_number = b.m_number;
	return *this;
}

BigInteger operator + (const BigInteger& a, const BigInteger& b) {

	return BigInteger("");
}

std::ostream& operator << (std::ostream& os, const BigInteger& a) {
	os << a.m_number << std::endl;
}
