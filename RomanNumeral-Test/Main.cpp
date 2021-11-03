#include "RomanNumeral.h"
#include<regex>
#include<string>
#include "gtest/gtest.h"

int main(int argc, char** argv)
{

	::testing::InitGoogleTest(&argc, argv);

	std::string num;
	std::cout << "Enter a number between 1 to 2000 to convert into roman numeral : ";
	std::cin >> num;
	RomanNumeral romannumeral; //create an object of Class RomanNumeral
	try
	{
		std::string result = romannumeral.int_to_roman(num);
		std::cout << "Roman Numeral of " << num << " is : " << result << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Unexpected Error: Entered input is invalid. PLease enter number between 1 to 2000 " << e.what() << std::endl;
	}
	return RUN_ALL_TESTS();
}
