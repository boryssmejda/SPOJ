#include <vector>
#include <map>
#include <iostream>
#include <string>
#include <utility>
#include <array>
#include <algorithm>

class RomanNumber {
private:
	struct number {
		std::string roman;
		int decimal;
		number(std::string s, int n): roman{s}, decimal{n}{}
	};

	const std::array<number, 13> m_dictionary = {
		number(std::string("I") , 1),
		number(std::string("IV"), 4),
		number(std::string("V"), 5),
		number(std::string("IX"), 9),
		number(std::string("X"), 10),
		number(std::string("XL"), 40),
		number(std::string("L"), 50),
		number(std::string("XC"), 90),
		number(std::string("C"), 100),
		number(std::string("CD"), 400),
		number(std::string("D"), 500),
		number(std::string("CM"), 900),
		number(std::string("M"), 1000)
	};
	
	int m_decimalForm;
	std::string m_romanNumber;
	
	std::string convertCurrentDigitToRoman(int num);
	std::pair<std::string, int> findRomanNumberNotBiggerThanCurrent(int number);

protected:
	int toDecimal();
	bool isCorrectRomanNumber();

	std::string toRoman();

public:
	RomanNumber(std::string roman);
	RomanNumber(int decimal);
	RomanNumber() : m_decimalForm{ 0 }, m_romanNumber{ "" }{}
	RomanNumber& operator = (const RomanNumber& r);


	friend std::istream & operator >> (std::istream& in, RomanNumber& r);
	friend std::ostream& operator << (std::ostream& out, RomanNumber& r);
	friend RomanNumber operator + (RomanNumber l, RomanNumber r);

};