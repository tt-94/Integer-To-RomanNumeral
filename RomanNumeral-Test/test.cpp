#include "RomanNumeral.h"
#include "gtest/gtest.h"

class RomanNumeralTests : public ::testing::Test {
protected:
	RomanNumeral romanNumeral;
	std::string result;
};


TEST_F(RomanNumeralTests, FalseTest_zero) {
	EXPECT_THROW(romanNumeral.int_to_roman("0"), std::exception);
}

TEST_F(RomanNumeralTests, FalseTest_decimal) {
	EXPECT_THROW(romanNumeral.int_to_roman("1.2"), std::exception);
}

TEST_F(RomanNumeralTests, FalseTest_specialcase) {
	EXPECT_THROW(romanNumeral.int_to_roman("@"), std::exception);
}

TEST_F(RomanNumeralTests, FalseTest_negative) {
	EXPECT_THROW(romanNumeral.int_to_roman("-24"), std::exception);
}

TEST_F(RomanNumeralTests, FalseTest_alphabet) {
	EXPECT_THROW(romanNumeral.int_to_roman("a"), std::exception);
}

TEST_F(RomanNumeralTests, FalseTest_2001) {
	EXPECT_THROW(romanNumeral.int_to_roman("2001"), std::exception);
}


TEST_F(RomanNumeralTests, TrueTest_firstindex_min_1) {
	EXPECT_NO_THROW(result = romanNumeral.int_to_roman("1"));
	EXPECT_EQ("I", result);
}

TEST_F(RomanNumeralTests, TrueTest_firstindex_max_9) {
	EXPECT_NO_THROW(result = romanNumeral.int_to_roman("9"));
	EXPECT_EQ("IX", result);
}
TEST_F(RomanNumeralTests, TrueTest_secondindex_min_10) {
	EXPECT_NO_THROW(result = romanNumeral.int_to_roman("10"));
	EXPECT_EQ("X", result);
}
TEST_F(RomanNumeralTests, TrueTest_secondindex_67) {
	EXPECT_NO_THROW(result = romanNumeral.int_to_roman("67"));
	EXPECT_EQ("LXVII", result);
}
TEST_F(RomanNumeralTests, TrueTest_secondindex_max_99) {
	EXPECT_NO_THROW(result = romanNumeral.int_to_roman("99"));
	EXPECT_EQ("XCIX", result);
}
TEST_F(RomanNumeralTests, TrueTest_thirdindex_min_100) {
	EXPECT_NO_THROW(result = romanNumeral.int_to_roman("100"));
	EXPECT_EQ("C", result);
}
TEST_F(RomanNumeralTests, TrueTest_thirdindex_525) {
	EXPECT_NO_THROW(result = romanNumeral.int_to_roman("525"));
	EXPECT_EQ("DXXV", result);
}
TEST_F(RomanNumeralTests, TrueTest_thirdindex_max_999) {
	EXPECT_NO_THROW(result = romanNumeral.int_to_roman("999"));
	EXPECT_EQ("CMXCIX", result);
}
TEST_F(RomanNumeralTests, TrueTest_fourthindex_min_1000) {
	EXPECT_NO_THROW(result = romanNumeral.int_to_roman("1000"));
	EXPECT_EQ("M", result);
}
TEST_F(RomanNumeralTests, TrueTest_fourthindex_1500) {
	EXPECT_NO_THROW(result = romanNumeral.int_to_roman("1500"));
	EXPECT_EQ("MD", result);
}
TEST_F(RomanNumeralTests, TrueTest_fourthindex_max_1999) {
	EXPECT_NO_THROW(result = romanNumeral.int_to_roman("1999"));
	EXPECT_EQ("MCMXCIX", result);
}
TEST_F(RomanNumeralTests, TrueTest_maxedge_2000) {
	EXPECT_NO_THROW(result = romanNumeral.int_to_roman("2000"));
	EXPECT_EQ("MM", result);
}