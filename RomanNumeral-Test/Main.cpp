#include "RomanNumeral.h"
#include "gtest/gtest.h"
#include<iostream>
using namespace std;

int main(int argc, char** argv)
{
	::testing::InitGoogleTest(&argc, argv);
	RomanNumeral romanNumeral; //create an object of Class RomanNumeral
	cout << "Please enter an integer : ";
	cin >> romanNumeral.num;
	if ((romanNumeral.num > 2000) || (romanNumeral.num < 1)) {
		cout << endl << "Invalid Integer" << endl;

	}
	else {

		cout << "Roman Numeral of " << romanNumeral.num << " is : " << romanNumeral.IntToRoman(romanNumeral.num) << endl;

	}

	return RUN_ALL_TESTS();

}