# C++ Roman Numerals

## Overview
A C++ function is written that converts an integer between 1 to 2000 to its roman numeral equivalent. If the user enters an input integer say `1676`, the function will return a roman numeral `MDCLXXVI`.

Furthermore, unit test cases is implemented using GoogleTest considering all the edge cases in Visual Studio 2019.

## Integer to Roman Representation

Below set of roman numeral representation is considered as member variables.

Value|Symbol
-----|-----
1000|M
900|CM
500|D
400|CD
100|C
90|XC
50|L
40|XL
10|X
9|IX
5|V
4|IV
1|I

## Class Method Declaration

```cpp
class RomanNumeral
{
public:
	std::string int_to_roman(std::string num);
private:
	std::pair<bool,int> validate(std::string num);
};
```

The C++ header file includes a class `RomanNumeral` consisting of two class methods. The `validate` function is been encapsulated using private access modifiers and returns two datatypes using a class template `std::pair<>`.

## Function declaration

1. Validate Function

```cpp
    std::pair<bool, int> RomanNumeral::validate(std::string inum) {

	int num = std::stoi(inum);
	std::regex float_regex("^([1-9]|[1-9][0-9]|[1-9][0-9][0-9]|[1][0-9][0-9][0-9]|2000)$", std::regex_constants::ECMAScript | std::regex_constants::icase);
	if (std::regex_search(inum, float_regex))
	{
		return { true, num };
	}

	return { false, -1 };
}
```

The `validate` function accepts input as a string *e.g* `'12'` and performs checks for validating the user input. A regular expression library function is used for numeric range checks ranging from `1-2000` and will cause an exception to be thrown for invalid inputs that include decimal points, negative integers, special characters and other non digit characters. 

2. Integer to Roman Conversion

```cpp
std::string RomanNumeral::int_to_roman(std::string strnum)
{
	auto result{ validate(strnum) };
	if (result.first)
	{
		int num = result.second;
		std::string result = "";
		for (std::size_t i{ 0 }; i < arr_values.size(); ++i)
		{
			while (num - arr_values[i] >= 0)
			{
				result += arr_roman[i];
				num -= arr_values[i];
			}
		}

		return result;
	}
	else
	{
		throw std::runtime_error("The entered value is invalid. Please enter a valid integer between 1 and 2000");
	}
	return "";
}
```
The `int_to_roman` function accepts input as string that performs the integer to roman conversion. Before the conversion, `validate` function is called within the function for input check validation and exception handling is implemented  that will cause an exception to be thrown for invalid inputs.

## Unit Test using Google Test

Unit test cases is written using google test considering all edge cases that include negative integers, decimal points,special characters and non digit characters. Fixtures was used for object and input variable declaration. Below are the few false and true test cases that were implemented successfully.

```cpp
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
```
