#include "pesel.cpp"
#include <gtest/gtest.h>

TEST(PeselTestCorrectness , CorrectPesel){

	ASSERT_EQ(true , isPESELcorrect("98121203534"));
	ASSERT_EQ(true , isPESELcorrect("98092242217"));
	ASSERT_EQ(true , isPESELcorrect("84030656662"));
	ASSERT_EQ(true , isPESELcorrect("57011183596"));
}

TEST(PeselTestCorrectness , IncorrectPesel){


	ASSERT_EQ(false , isPESELcorrect("12345678900"));
	ASSERT_EQ(false , isPESELcorrect("98765432109"));
	ASSERT_EQ(false , isPESELcorrect("99221234567"));
	ASSERT_EQ(false , isPESELcorrect("57991234566"));
}

int main(int argc, char **argv) 
    {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
    }
