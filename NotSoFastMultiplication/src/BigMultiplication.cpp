#include "BigMultiplication.hpp"

const BigMultiplier operator * (const BigMultiplier& t_numA, const BigMultiplier& t_numB)
{
	BigMultiplier result("0");
	return result;
}

std::ostream& operator<<(std::ostream& os, const BigMultiplier& bm)
{
	os << bm.m_number << "\n";
	return os;
}
