#include "RomanNumeral.h"
#include<array>
#include<regex>
#include<iostream>
#include<utility>

namespace {
	const int ARR_SIZE = 13;
	const std::array<std::string, ARR_SIZE> arr_roman = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
	const std::array<int, ARR_SIZE> arr_values = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };

}


std::pair<bool, int> RomanNumeral::validate(std::string inum) {

	int num = std::stoi(inum);
	std::regex float_regex("^([1-9]|[1-9][0-9]|[1-9][0-9][0-9]|[1][0-9][0-9][0-9]|2000)$", std::regex_constants::ECMAScript | std::regex_constants::icase);
	if (std::regex_search(inum, float_regex))
	{
		return { true, num };
	}

	return { false, -1 };
}


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