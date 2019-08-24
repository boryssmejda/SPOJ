#include <gtest/gtest.h>
#include "BigInteger.hpp"


TEST(BigIntegerAddition, incorrectInput) {
	
	try {
		BigInteger a("-88");
		FAIL() << "Expected std::invalid argument";
	}
	catch (std::invalid_argument const& err) {
		EXPECT_EQ(err.what(), std::string("This is not a valid number"));
	}
	catch (...) {
		FAIL() << "Expected std::invalid_argument";
	}

	try {
		BigInteger a("8a8");
		FAIL() << "Expected std::invalid argument";
	}
	catch (std::invalid_argument const& err) {
		EXPECT_EQ(err.what(), std::string("This is not a valid number"));
	}
	catch (...) {
		FAIL() << "Expected std::invalid_argument";
	}

	try {
		BigInteger a("8@z8");
		FAIL() << "Expected std::invalid argument";
	}
	catch (std::invalid_argument const& err) {
		EXPECT_EQ(err.what(), std::string("This is not a valid number"));
	}
	catch (...) {
		FAIL() << "Expected std::invalid_argument";
	}
}

TEST(BigIntegerAddition, addingNumber_below1000) {

	BigInteger a("172");
	BigInteger b("3498");

	EXPECT_EQ(addBigIntegers(a, b), std::string("3670"));


	BigInteger c("1500");
	BigInteger d("500");

	EXPECT_EQ(addBigIntegers(c, d), std::string("2000"));
}

TEST(BigIntegerAddition, addingNumber_huge) {
	
	BigInteger a("1234567890123456789");
	BigInteger b("12123343456567878909");

	EXPECT_EQ(addBigIntegers(a, b), std::string("13357911346691335698"));
}


int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}