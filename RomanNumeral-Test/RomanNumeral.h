#pragma once
#include "gtest/gtest.h"
#include <string>
using namespace std;

class RomanNumeral
{
public:
	int num;
	string int_to_roman(int num);
	bool validate(int num);
};

