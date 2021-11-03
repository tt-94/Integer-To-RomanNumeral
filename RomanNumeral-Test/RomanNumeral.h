#pragma once
#include<string>
#include<utility>

class RomanNumeral
{
public:
	std::string int_to_roman(std::string num);
private:
	std::pair<bool,int> validate(std::string num);
};
