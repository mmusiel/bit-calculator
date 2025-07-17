#include "my-types.h"
#include "utils/operation.h"
#include "utils/conversions.h"
#include "utils/io.h"
#include <iostream>
#include <bitset>

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
			
			// REMOVE: for testing
			std::cout << "Binary: " << std::bitset<BitTypeBits>{ num1 } << '\n';
			std::cout << "Hexadecimal: " << std::hex << num1 << '\n';
			std::cout << "Decimal: " << std::dec << num1 << '\n';
			break;
		}

		// Number conversion
		case 2:
		{
			printConversions();		// REMOVE: placeholder
			break;
		}
		}
		std::cout << '\n';	// Padding for next loop
	}
	while(menuChoice != max_ExitOption);

	std::cout << "Exiting calculator.\n";

	return 0;
}