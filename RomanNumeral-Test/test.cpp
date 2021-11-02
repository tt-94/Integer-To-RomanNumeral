#include "gtest/gtest.h"
#include "RomanNumeral.h"

TEST(TestCaseName, TestName_1) {
	ASSERT_FALSE("II", IntToRoman(1));
}

TEST(TestCaseName, TestName_2) {
	ASSERT_TRUE("I", IntToRoman(1));
}