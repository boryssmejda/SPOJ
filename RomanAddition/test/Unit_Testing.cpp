#include <gtest/gtest.h>
#include "RomanAddition.hpp"


class RomanAddition_TEST : private RomanNumber{

public:

	using RomanNumber::toDecimal;
	using RomanNumber::toRoman;
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

TEST(ToRoman, below_10) {

	RomanAddition_TEST t1(1);
	EXPECT_EQ(t1.toRoman(), std::string("I"));

	RomanAddition_TEST t2(2);
	EXPECT_EQ(t2.toRoman(), std::string("II"));

	RomanAddition_TEST t3(3);
	EXPECT_EQ(t3.toRoman(), std::string("III"));

	RomanAddition_TEST t4(4);
	EXPECT_EQ(t4.toRoman(), std::string("IV"));

	RomanAddition_TEST t5(5);
	EXPECT_EQ(t5.toRoman(), std::string("V"));

	RomanAddition_TEST t6(8);
	EXPECT_EQ(t6.toRoman(), std::string("VIII"));

	RomanAddition_TEST t7(9);
	EXPECT_EQ(t7.toRoman(), std::string("IX"));
}

TEST(ToRoman, below_100) {

	RomanAddition_TEST t1(18);
	EXPECT_EQ(t1.toRoman(), std::string("XVIII"));

	RomanAddition_TEST t2(48);
	EXPECT_EQ(t2.toRoman(), std::string("XLVIII"));

	RomanAddition_TEST t3(51);
	EXPECT_EQ(t3.toRoman(), std::string("LI"));

	RomanAddition_TEST t4(91);
	EXPECT_EQ(t4.toRoman(), std::string("XCI"));

	RomanAddition_TEST t5(99);
	EXPECT_EQ(t5.toRoman(), std::string("XCIX"));
}

TEST(ToRoman, below_1000) {

	RomanAddition_TEST t1(180);
	EXPECT_EQ(t1.toRoman(), std::string("CLXXX"));

	RomanAddition_TEST t2(207);
	EXPECT_EQ(t2.toRoman(), std::string("CCVII"));

	RomanAddition_TEST t3(251);
	EXPECT_EQ(t3.toRoman(), std::string("CCLI"));

	RomanAddition_TEST t4(291);
	EXPECT_EQ(t4.toRoman(), std::string("CCXCI"));

	RomanAddition_TEST t5(299);
	EXPECT_EQ(t5.toRoman(), std::string("CCXCIX"));

	RomanAddition_TEST t6(499);
	EXPECT_EQ(t6.toRoman(), std::string("CDXCIX"));

	RomanAddition_TEST t7(998);
	EXPECT_EQ(t7.toRoman(), std::string("CMXCVIII"));

}

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}