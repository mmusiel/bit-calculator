#include "conversions.h"
#include "../my-types.h"
#include "io.h"
#include <iostream>

// REMOVE: placeholder function
void performConversion()
{
	const NumberInput num{ getNumberInputWithBase("Enter positive decimal, hex (prefix 0x), or binary (prefix 0b) to convert: ") };

	std::cout << "Choose conversion: \n";

	int menuOption{ 0 };

	if (num.base != NumberBase::HEX)
	{	
		menuOption += 1;
		std::cout << menuOption << ") Hexadecimal\n";
	}
	if (num.base != NumberBase::BINARY)
	{
		menuOption += 1;
		std::cout << menuOption << ") Binary\n";
	}

	if (num.base != NumberBase::DECIMAL)
	{	
		menuOption += 1;
		std::cout << menuOption << ") Decimal\n";
	}

	constexpr int min_MenuOption{ 1 };
	constexpr int max_MenuOption{ 2 };

	const int menuChoice{ getMenuChoice(min_MenuOption, max_MenuOption, "Enter conversion choice: ") };

	std::cout << "MENU CHOICE: " << menuChoice << '\n';		// REMOVE: for testing

}