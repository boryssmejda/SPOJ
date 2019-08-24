#include "BigInteger.hpp"

bool BigInteger::isNumber(std::string s)
{
	for (int i = 0; i < s.length(); i++) {
		if (!isdigit(s[i]))
			throw std::invalid_argument("This is not a valid number");
	}

	return true;
}

BigInteger::BigInteger(std::string t_num) : m_number{ t_num } {

	isNumber(m_number);
}

BigInteger& BigInteger::operator=(const BigInteger& b)
{
	this->m_number = b.m_number;
	return *this;
}

BigInteger operator + (const BigInteger& a, const BigInteger& b) {
	return addBigIntegers(a, b);
}

std::ostream& operator << (std::ostream& os, const BigInteger& a) {
	os << a.m_number << std::endl;
	return os;
}

std::string addBigIntegers(const BigInteger& a, const BigInteger& b)
{
	int length_a = a.m_number.length(), length_b = b.m_number.length();

	std::string finalResult("");
	int carry = 0;
	int counter_A = length_a - 1, counter_B = length_b - 1;

	while (counter_A >= 0 || counter_B >= 0) {

		int digit_A = 0;
		int digit_B = 0;

		if(counter_A >= 0)
			digit_A = a.m_number[counter_A--] - '0';

		if (counter_B >= 0)
			digit_B = b.m_number[counter_B--] - '0';

		int currentDigit = digit_A + digit_B + carry;
		
		carry = currentDigit / 10;
		currentDigit %= 10;

		finalResult += std::to_string(currentDigit);
	}

	std::reverse(finalResult.begin(), finalResult.end());
	return finalResult;
}
