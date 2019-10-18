#include <gtest/gtest.h>
#include "BigMultiplication.hpp"

TEST(BigMultiplication, trivialCases) {

	BigMultiplier a("1"), b("1"), c("1");
	ASSERT_EQ( a*b,  c);

	a = BigMultiplier("3");
	b = BigMultiplier("3");
	c = BigMultiplier("9");
	ASSERT_EQ(a * b, c);

	a = BigMultiplier("3");
	b = BigMultiplier("0");
	c = BigMultiplier("0");
	ASSERT_EQ(a * b, c);
}

TEST(BigMultiplication, below100) {

	BigMultiplier a("4"), b("5"), c("20");
	ASSERT_EQ(a * b, c);

	a = BigMultiplier("11");
	b = BigMultiplier("5");
	c = BigMultiplier("55");
	ASSERT_EQ(a * b, c);

	a = BigMultiplier("9");
	b = BigMultiplier("11");
	c = BigMultiplier("99");
	ASSERT_EQ(a * b, c);
}

TEST(BigMultiplication, below_1000) {

	BigMultiplier a("12"), b("12"), c("144");
	ASSERT_EQ(a * b, c);

	a = BigMultiplier("20");
	b = BigMultiplier("20");
	c = BigMultiplier("400");
	ASSERT_EQ(a * b, c);

	a = BigMultiplier("919");
	b = BigMultiplier("1");
	c = BigMultiplier("919");
	ASSERT_EQ(a * b, c);
}

TEST(BigMultiplication, over_10000) {

	BigMultiplier a("9999"), b("12345"), c("123437655");
	ASSERT_EQ(a * b, c);

	a = BigMultiplier("324");
	b = BigMultiplier("342");
	c = BigMultiplier("110808");
	ASSERT_EQ(a * b, c);
}

TEST(BigMultiplication, enormous) {

	BigMultiplier a("12345678900987654321");
	BigMultiplier b("99999999999999999999");
	BigMultiplier c("1234567890098765432087654321099012345679");
	ASSERT_EQ(a * b, c);

}

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}