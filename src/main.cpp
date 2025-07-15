#include "my-types.h"
#include "utils/operation.h"
#include "utils/conversions.h"
#include "utils/io.h"
#include <iostream>

// Presents calculator menu, gets user choice, and calls calculator functions
int main()
{
	constexpr int min_MenuOption{ 1 };
	constexpr int max_ExitOption{ 3 };

	int menuChoice{};

	do
	{
		std::cout << "1) Bitwise operation (AND, OR, XOR, NOT, or Left/Right Shifts)\n";
		std::cout << "2) Number conversion (Decimal, Binary, Hexadecimal)\n";
		std::cout << "3) Exit\n";

		menuChoice = getMenuChoice(min_MenuOption, max_ExitOption, "Enter menu choice: ");

		switch(menuChoice)
		{
		// Bitwise Operation
		case 1:
		{
			const BitType num1{ getNumberInput() };
			const BitType num2{ getNumberInput() };
			
			std::cout << "num1: " << num1 << '\n';
			std::cout << "num2: " << num2 << '\n';
			break;
		}

		// Number conversion
		case 2:
		{
			printConversions();
			break;
		}
		}
		std::cout << '\n';	// Padding for next loop
	}
	while(menuChoice != max_ExitOption);

	std::cout << "Exiting calculator.\n";

	return 0;
}