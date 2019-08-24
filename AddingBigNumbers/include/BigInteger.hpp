#ifndef BIG_INTEGER_HPP
#define BIG_INTEGER_HPP

#include <iostream>
#include <string>
#include <ctype.h>

class BigInteger {
private:
	std::string m_number;
	bool isNumber(std::string s);

public:
	BigInteger(std::string t_num);
	BigInteger& operator = (const BigInteger& b);
	friend BigInteger operator + (const BigInteger& a, const BigInteger& b);
	friend std::ostream& operator << (std::ostream& os ,const BigInteger& a);
	friend std::string addBigIntegers(const BigInteger& a, const BigInteger& b);
};

#endif // !BIG_INTEGER_HPP


