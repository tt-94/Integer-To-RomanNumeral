#include "RomanNumeral.h"
#include "gtest/gtest.h"
#include<regex>
#include<string>


int main(int argc, char** argv)
{
	::testing::InitGoogleTest(&argc, argv);

	std::string num;
	std::cout << "Enter a number between 1 to 2000 to convert into roman numeral : ";
	std::cin >> num;
	RomanNumeral romanNumeral; //create an object of Class RomanNumeral
	if (romanNumeral.validate(num)) {
		auto result = romanNumeral.int_to_roman(num);
		std::cout << "Roman Numeral of " << num << " is : " << result << std::endl;

	}
	else {

		std::cout << "Invalid Number! ";

	}

	return RUN_ALL_TESTS();

}