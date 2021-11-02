#include "gtest/gtest.h"
#include "RomanNumeral.h"

TEST(TestCaseName, FalseTest_1) {
	RomanNumeral romanNumeral;
	EXPECT_FALSE(romanNumeral.validate("0"));
}

TEST(TestCaseName, FalseTest_3) {
	RomanNumeral romanNumeral;
	EXPECT_FALSE(romanNumeral.validate("-1.9"));
}
TEST(TestCaseName, FalseTest_4) {
	RomanNumeral romanNumeral;
	EXPECT_FALSE(romanNumeral.validate("a"));
}

TEST(TestCaseName, FalseTest_5) {
	RomanNumeral romanNumeral;
	EXPECT_FALSE(romanNumeral.validate("2.6"));
}

TEST(TestCaseName, FalseTest_6) {
	RomanNumeral romanNumeral;
	EXPECT_FALSE(romanNumeral.validate("2001"));
}

TEST(TestCaseName, TrueTest_1) {
	RomanNumeral romanNumeral;
	EXPECT_TRUE(romanNumeral.validate("+10"));
	EXPECT_EQ("X", romanNumeral.int_to_roman("+10"));
}


	TEST(TestCaseName, TrueTest_2) {
		RomanNumeral romanNumeral;
		EXPECT_TRUE(romanNumeral.validate("50"));
		EXPECT_EQ("L", romanNumeral.int_to_roman("50"));
	}

	TEST(TestCaseName, TrueTest_3) {
		RomanNumeral romanNumeral;
		EXPECT_TRUE(romanNumeral.validate("1999"));
		EXPECT_EQ("MCMXCIX", romanNumeral.int_to_roman("1999"));
	}