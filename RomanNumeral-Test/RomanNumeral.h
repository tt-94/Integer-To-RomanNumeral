#pragma once
#include<string>
#include "gtest/gtest.h"

class RomanNumeral
{
public:
	std::string int_to_roman(std::string num);
private:
	bool validate(std::string num);
};
