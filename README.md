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
	bool validate(std::string num);
};
```

The C++ header file includes a class `RomanNumeral` consisting of two class methods. The `validate` function is been encapsulated using private access modifiers.

## Function declaration

1. Validate Function

```cpp
    bool RomanNumeral::validate(std::string inum) {

	std::regex float_regex("\\.|-|[a-zA-Z]", std::regex_constants::ECMAScript | std::regex_constants::icase);
	if (std::regex_search(inum, float_regex))
	{
		return false;
	}

	int num = std::stoi(inum);
	if (((num > 2000) || (num < 1)))
	{
		std::cout << "Enter an integer between 1 and 2000 " << std::endl;
		return false;
	}

	return true;
}

```

The `validate` function accepts input as a string *e.g* `'12'` and performs two checks. A regular expression library function is used for checks that include decimal points, negative integers and other non digit characters and will cause an exception to be thrown for invalid input. Secondly, to limit the range from 1 to 2000, a conditional statement check is used that throws a console output for numbers exceeding the given range. 

2. Integer to Roman Conversion

```cpp

std::string RomanNumeral::int_to_roman(std::string strnum)
{
	if (validate(strnum))
	{
		try
		{
			int num = std::stoi(strnum);
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
		catch (std::exception& e)
		{
			
		}
	}
	else
	{
		throw std::runtime_error("The entered value is invalid. Please enter a valid integer between 1 and 2000");
	}
	return "";
}
```
The `int_to_roman` function accepts input as string that performs the integer to roman conversion. Before the conversion, `validate` function is called within the function for input check validation and exception handling is implemented  that will cause an exception to be thrown for invalid input.

## Unit Test using Google Test

Unit test cases is written using google test considering all edge cases that include negative integers, decimal points and non digit characters. Fixtures was used for object and input variable declaration. Below are the few false and true test cases that were implemented successfully.

```cpp
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

```
