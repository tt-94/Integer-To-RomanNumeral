#pragma once
#include "gtest/gtest.h"
#include <string>
using namespace std;

class RomanNumeral
{
public:
	string int_to_roman(std::string strnum);
	bool validate(std::string inum);
};

