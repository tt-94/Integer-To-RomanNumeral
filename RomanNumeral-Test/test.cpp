#include "RomanNumeral.h"
#include "gtest/gtest.h"

class RomanNumeralTests : public ::testing::Test {
protected:
	RomanNumeral romanNumeral;
	std::string result;
};


TEST_F(RomanNumeralTests, FalseTest_1) {
	EXPECT_THROW(romanNumeral.int_to_roman("0"), std::exception);
}

TEST_F(RomanNumeralTests, FalseTest_2) {
	EXPECT_THROW(romanNumeral.int_to_roman("1.2"), std::exception);
}

TEST_F(RomanNumeralTests, FalseTest_3) {
	EXPECT_THROW(romanNumeral.int_to_roman("-24"), std::exception);
}

TEST_F(RomanNumeralTests, FalseTest_4) {
	EXPECT_THROW(romanNumeral.int_to_roman("a"), std::exception);
}

TEST_F(RomanNumeralTests, FalseTest_5) {
	EXPECT_THROW(romanNumeral.int_to_roman("2001"), std::exception);
}


TEST_F(RomanNumeralTests, TrueTest_1) {
	EXPECT_NO_THROW(result = romanNumeral.int_to_roman("1"));
	EXPECT_EQ("I", result);
}

TEST_F(RomanNumeralTests, TrueTest_2) {
	EXPECT_NO_THROW(result = romanNumeral.int_to_roman("67"));
	EXPECT_EQ("LXVII", result);
}

TEST_F(RomanNumeralTests, TrueTest_3) {
	EXPECT_NO_THROW(result = romanNumeral.int_to_roman("525"));
	EXPECT_EQ("DXXV", result);
}

TEST_F(RomanNumeralTests, TrueTest_4) {
	EXPECT_NO_THROW(result = romanNumeral.int_to_roman("2000"));
	EXPECT_EQ("MM", result);
}