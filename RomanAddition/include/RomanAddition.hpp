#include <vector>
#include <map>
#include <iostream>
#include <string>

class RomanNumber {
private:
	const std::map<std::string, int> dictionary = {
		{"I" , 1},
		{"IV" , 4},
		{"V", 5},
		{"IX", 9},
		{"X", 10},
		{"XL", 40},
		{"L", 50},
		{"XC", 90},
		{"C", 100},
		{"CD", 400},
		{"D", 500},
		{"CM", 900},
		{"M", 1000}
	};

	int decimalForm;
	std::string romanNumber;
	
	void toDecimal();
	std::string toRoman();

public:
	RomanNumber(std::string roman);
	RomanNumber() : decimalForm{ 0 }, romanNumber{ "" }{}
	RomanNumber& operator = (const RomanNumber& r);

	friend std::istream & operator >> (std::istream& in, RomanNumber& r);
	friend std::ostream& operator << (std::ostream& out, RomanNumber& r);
	friend RomanNumber operator + (RomanNumber l, RomanNumber r);

};