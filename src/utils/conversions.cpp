#include "conversions.h"
#include "../my-types.h"
#include "io.h"
#include <iostream>

void performConversion()
{
	const NumberInput num{ getNumberInputWithBase("Enter positive decimal, hex (prefix 0x), or binary (prefix 0b) to convert: ") };
	char conversionLetter{ getConversionChoice(num) };

	std::cout << "Conversion Char: " << conversionLetter << '\n';	// REMOVE: for debugging

	// // Print Hex result
	// if ((num.base == NumberBase::DECIMAL && menuOption == 1) || (num.base == NumberBase::BINARY && menuOption == 1) )
	// {
	// 	std::cout << "Hex: "; printFormattedNumber(num.value, NumberBase::HEX); std::cout << '\n';
	// }

	// // Print Binary
	// else if ((num.base == NumberBase::DECIMAL && menuOption == 2) || (num.base == NumberBase::HEX && menuOption == 1) )
	// {
	// 	std::cout << "Binary: "; printFormattedNumber(num.value, NumberBase::BINARY); std::cout << '\n';
	// }

	// // Print Decimal
	// else
	// {
	// 	std::cout << "Decimal: "; printFormattedNumber(num.value, NumberBase::DECIMAL); std::cout << '\n';
	// }

}