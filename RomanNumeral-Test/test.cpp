#include "gtest/gtest.h"
#include "RomanNumeral.h"

TEST(TestIntToRoman, TrueTest_1) {
	RomanNumeral roman;
	EXPECT_TRUE(roman.validate(1));
	EXPECT_EQ("I", roman.int_to_roman(1));

}

TEST(TestIntToRoman, FalseTest_2) {
	RomanNumeral roman;
	EXPECT_TRUE(roman.validate(5));
	EXPECT_NE("I", roman.int_to_roman(5));

}