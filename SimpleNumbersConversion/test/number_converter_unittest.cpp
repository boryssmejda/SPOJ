#include <gtest/gtest.h>
#include "number_converter.hpp"

namespace {

	class NumberConverterTest : public ::testing::Test {
	protected:
		void SetUp() override {
			n1 = NumberConverter(10, 2, std::string("231"));
			n2 = NumberConverter(15, 10, std::string("ABC"));
			n3 = NumberConverter(36, 2, std::string("XYZ"));
		}

		// void TearDown() override {}

		NumberConverter n1;
		NumberConverter n2;
		NumberConverter n3;
	};

	TEST_F(NumberConverterTest, from10to2) {
		EXPECT_EQ(n1.convertNumber(), "11100111");
	}

	TEST_F(NumberConverterTest, fromBase15to10) {

	}

	TEST_F(NumberConverterTest, fromBase36to2) {

	}

}

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}