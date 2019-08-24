#ifndef BIG_INTEGER_HPP
#define BIG_INTEGER_HPP

#include <iostream>
#include <string>

class BigInteger {
private:
	std::string m_number;
public:
	BigInteger(std::string t_num): m_number{t_num}{}
	BigInteger& operator = (const BigInteger& b);
	friend BigInteger operator + (const BigInteger& a, const BigInteger& b);
	friend std::ostream& operator << (std::ostream& os ,const BigInteger& a);
};

#endif // !BIG_INTEGER_HPP


