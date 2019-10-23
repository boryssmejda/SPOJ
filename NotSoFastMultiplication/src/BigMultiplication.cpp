#include "BigMultiplication.hpp"
#include <algorithm>
#include <iterator>

const BigMultiplier operator * (const BigMultiplier& t_numA, const BigMultiplier& t_numB)
{
	std::string finalResult{ "0" };
	int shiftBy = -1;
	for (auto it = t_numB.m_number.rbegin(); it != t_numB.m_number.rend(); it++) {

		std::string tmp = BigMultiplier::multiplyBySingleDigit(t_numA.m_number, *it);
		BigMultiplier::shiftLeftBy(tmp, ++shiftBy);
		finalResult = BigMultiplier::add(finalResult, tmp);
	}

	return BigMultiplier(finalResult);
}

bool operator==(const BigMultiplier& t_numA, const BigMultiplier& t_numB)
{
	return (t_numA.m_number == t_numB.m_number ? true : false);
}

std::ostream& operator<<(std::ostream& os, const BigMultiplier& bm)
{
	os << bm.m_number << "\n";
	return os;
}

std::string BigMultiplier::multiplyBySingleDigit(const std::string& number, const char multiplyBy)
{
	if (multiplyBy == '0') {
		return { "0" };
	}
	else if (multiplyBy == '1') {
		return number;
	}

	std::string result{ "" };
	int carryNext{0};
	for (auto rit = number.rbegin(); rit != number.rend(); ++rit) {
		int currentDigit = (*rit - '0') * (multiplyBy - '0') + carryNext;
		carryNext = currentDigit / 10;

		result += ( currentDigit%10 + '0');
	}

	if (carryNext) {
		result += (carryNext + '0');
	}
	
	std::reverse(result.begin(), result.end());
	return result;
}

void BigMultiplier::shiftLeftBy(std::string& number, int shiftBy)
{
	if(shiftBy > 0)
		number.append(shiftBy, '0');
}

std::string BigMultiplier::add(const std::string& a, const std::string& b)
{
	int a_index = static_cast<int>(a.length() - 1);
	int b_index = static_cast<int>(b.length() - 1);
	int carry = 0;
	std::string result{""};
	while (a_index >= 0  || b_index >= 0 || carry ) {

		int currentDigit = 0;
		if (a_index >= 0)
			currentDigit += (a[a_index] - '0');

		if (b_index >= 0)
			currentDigit += (b[b_index] - '0');

		if (carry)
			currentDigit += carry;

		carry = currentDigit / 10;
		result += (currentDigit % 10 + '0');

		--a_index;
		--b_index;
	}

	std::reverse(result.begin(), result.end());
	return result;
}

