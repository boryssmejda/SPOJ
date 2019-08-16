#include <gtest/gtest.h>
#include "floatRepresentation.hpp"

namespace {

	class FloatRepresentationTest: public ::testing::Test {
	protected:

		FloatRepresentationTest(){}
		~FloatRepresentationTest() override {}

		void SetUp() override {
			f1 = FloatRepresentation(1.0f);
			f2 = FloatRepresentation(-1.0f);
			f3 = FloatRepresentation(0.0f);
			f4 = FloatRepresentation(123.125f);
			f5 = FloatRepresentation(-345.0f);
		}

		 void TearDown() override {}

		 FloatRepresentation f1, f2 , f3, f4, f5;

	};

	TEST_F(FloatRepresentationTest, trivialCases) {
		EXPECT_EQ(f1.getFloatHexRepresentation(), "3f 80 0 0");
		EXPECT_EQ(f2.getFloatHexRepresentation(), "bf 80 0 0");
		EXPECT_EQ(f3.getFloatHexRepresentation(), "0 0 0 0");
	}

	TEST_F(FloatRepresentationTest, positiveFloat) {
		EXPECT_EQ(f4.getFloatHexRepresentation(), "42 f6 40 0");
	}

	TEST_F(FloatRepresentationTest, negativeFloat) {
		EXPECT_EQ(f5.getFloatHexRepresentation() , "c3 ac 80 0");
	}

}

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}