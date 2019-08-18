#include <vector>
#include <map>
#include <iostream>
#include <string>

class RomanNumber {
private:
	const std::map<std::string, int> dictionary = {
		{std::string("I") , 1},
		{std::string("IV"), 4},
		{std::string("V"), 5},
		{std::string("IX"), 9},
		{std::string("X"), 10},
		{std::string("XL"), 40},
		{std::string("L"), 50},
		{std::string("XC"), 90},
		{std::string("C"), 100},
		{std::string("CD"), 400},
		{std::string("D"), 500},
		{std::string("CM"), 900},
		{std::string("M"), 1000}
	};
	
	int m_decimalForm;
	std::string m_romanNumber;
	
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