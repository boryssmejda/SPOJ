#include <gtest/gtest.h>
#include "RomanAddition.hpp"


class RomanAddition_TEST : private RomanNumber{

public:

	using RomanNumber::toDecimal;
	RomanAddition_TEST(std::string romanNum) : RomanNumber(romanNum){}
	RomanAddition_TEST(int decimalNum): RomanNumber(decimalNum){}


};


TEST(RomanToDecimalConversion, correctCases_smallerThan10) {
	RomanAddition_TEST test(std::string("I"));
	EXPECT_EQ(test.toDecimal(), 1);

	RomanAddition_TEST t2("II");
	EXPECT_EQ(t2.toDecimal(), 2);

	RomanAddition_TEST test3 = RomanAddition_TEST("III");
	EXPECT_EQ(test3.toDecimal(), 3);

	RomanAddition_TEST test4 = RomanAddition_TEST("IV");
	EXPECT_EQ(test4.toDecimal(), 4);

	RomanAddition_TEST test5 = RomanAddition_TEST("VI");
	EXPECT_EQ(test5.toDecimal(), 6);

	RomanAddition_TEST test6 = RomanAddition_TEST("VII");
	EXPECT_EQ(test6.toDecimal(), 7);

	RomanAddition_TEST test7 = RomanAddition_TEST("VIII");
	EXPECT_EQ(test7.toDecimal(), 8);

	RomanAddition_TEST test8 = RomanAddition_TEST("IX");
	EXPECT_EQ(test8.toDecimal(), 9);
}


TEST(RomanToDecimalConversion, below100) {

	RomanAddition_TEST test1 = RomanAddition_TEST("X");
	EXPECT_EQ(test1.toDecimal(), 10);

	RomanAddition_TEST test2 = RomanAddition_TEST("XI");
	EXPECT_EQ(test2.toDecimal(), 11);

	RomanAddition_TEST test3 = RomanAddition_TEST("XII");
	EXPECT_EQ(test3.toDecimal(), 12);

	RomanAddition_TEST test4 = RomanAddition_TEST("XIII");
	EXPECT_EQ(test4.toDecimal(), 13);

	RomanAddition_TEST test5 = RomanAddition_TEST("XIV");
	EXPECT_EQ(test5.toDecimal(), 14);

	RomanAddition_TEST test6 = RomanAddition_TEST("XV");
	EXPECT_EQ(test6.toDecimal(), 15);

	RomanAddition_TEST test7 = RomanAddition_TEST("XX");
	EXPECT_EQ(test7.toDecimal(), 20);

	RomanAddition_TEST test8 = RomanAddition_TEST("XXX");
	EXPECT_EQ(test8.toDecimal(), 30);

	RomanAddition_TEST test9 = RomanAddition_TEST("XLIV");
	EXPECT_EQ(test9.toDecimal(), 44);

	RomanAddition_TEST test10 = RomanAddition_TEST("LXV");
	EXPECT_EQ(test10.toDecimal(), 65);

	RomanAddition_TEST test11 = RomanAddition_TEST("XCVIII");
	EXPECT_EQ(test11.toDecimal(), 98);

}

TEST(RomanToDecimalConversion, below1000) {

	RomanAddition_TEST test1 = RomanAddition_TEST("CXXXIII");
	EXPECT_EQ(test1.toDecimal(), 133);

	RomanAddition_TEST test2 = RomanAddition_TEST("CCXLIX");
	EXPECT_EQ(test2.toDecimal(), 249);

	RomanAddition_TEST test3 = RomanAddition_TEST("CCCXXXIII");
	EXPECT_EQ(test3.toDecimal(), 333);

	RomanAddition_TEST test4 = RomanAddition_TEST("CCCXCIX");
	EXPECT_EQ(test4.toDecimal(), 399);

	RomanAddition_TEST test5 = RomanAddition_TEST("CDXCIX");
	EXPECT_EQ(test5.toDecimal(), 499);

	RomanAddition_TEST test6 = RomanAddition_TEST("CMXCIX");
	EXPECT_EQ(test6.toDecimal(), 999);
}

TEST(RomanToDecimalConversion, over_1000) {

	RomanAddition_TEST test1 = RomanAddition_TEST("MCXXXIII");
	EXPECT_EQ(test1.toDecimal(), 1133);

	RomanAddition_TEST test2 = RomanAddition_TEST("MMCXXXIII");
	EXPECT_EQ(test2.toDecimal(), 2133);

	RomanAddition_TEST test3 = RomanAddition_TEST("MMIII");
	EXPECT_EQ(test3.toDecimal(), 2003);

	RomanAddition_TEST test4 = RomanAddition_TEST("MMMCMXCIX");
	EXPECT_EQ(test4.toDecimal(), 3999);
}

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}