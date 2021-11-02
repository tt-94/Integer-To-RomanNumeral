#include "RomanNumeral.h"
#include "gtest/gtest.h"
#include <string>
#include<array>

namespace {

	const std::array<std::string, 13> arr_roman = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
	const std::array<int, 13> arr_values = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };

}

bool RomanNumeral::validate(int num) {

	return ((num <= 2000) && (num >= 1));
}

std::string RomanNumeral::int_to_roman(int num)
{

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