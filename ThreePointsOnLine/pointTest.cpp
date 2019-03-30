#include "threePoints.cpp"
#include <gtest/gtest.h>
 
TEST(SquareRootTest, PositiveNos) 
    { 
	int input[6] = {1,2,3,4,5,2};
    	ASSERT_EQ(true , isOnLine(input));
    }
 
int main(int argc, char **argv) 
    {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
    }
