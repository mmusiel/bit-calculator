#include "output.h"
#include "../Math.h"
#include <iostream>
#include <type_traits> 

void printBit(BitType number, BitType power)
{
    std::cout << ((number / power) % 2);
}

// Print binary seperated by spaces at every 4-bits and 16-bits add new line
// Ex:	0000 1111 1010 1111
//		1111 0011 0000 1010
void printBinaryMulitpleLines(BitType number)
{
    constexpr BitType base{ 2 };
    BitType exponent{ BitTypeBits };

    while (exponent != 0)
    {
        --exponent;

        BitType power{Math::power(base, exponent)};

        printBit(number, power);

        if (exponent % 16 == 0)		// Every 16-bits print a new line
        {
            std::cout << '\n';
            continue;
        }
        if (exponent % 4 == 0)		// Every 4-bits print a space
            std::cout << ' ';
    }
}

// Print binary with no leading 0's on one line seperated by apostrophes
// Ex:	0b0101'0000'1011
void printBinaryOneLine(BitType number)
{
    constexpr BitType base{ 2 };
    BitType exponent{ 0 };

    // Removes leading 0's by incrementing 4-bits at a time and checking if number is less than it's max value 
    for (BitType i{ exponent }; i <= BitTypeBits; i += 4)
    {
    	const BitType maxValue{ static_cast<BitType>(Math::power(base, i) - 1) };	// Minus 1 so it doesn't cause overflow

    	if (number <= maxValue)
    	{
    		exponent = i;
    		break;
    	}
    }

    while (exponent != 0)
    {
        --exponent;

        BitType power{Math::power(base, exponent)};

        printBit(number, power);

        if (exponent % 4 == 0 && exponent != 0)		// Every 4-bits print a apostrophe
            std::cout << '\'';
    }
}

void printFormattedNumber(BitType num, NumberBase base)
{
	// Print Hex
	if (base == NumberBase::HEX)
	{
		std::cout << "0x" << std::hex;
		if constexpr (std::is_same_v<BitType, uint8_t>)
			std::cout << static_cast<int>(num);		// Cast as int so not treated as Char
		else
			std::cout << num;

		std::cout << std::dec;		// set cout back to decimal output
	}

	// Print Binary
	else if (base == NumberBase::BINARY)
	{
		std::cout << "0b";
		printBinaryOneLine(num);
	}

	// Print Decimal
	else
	{
		std::cout << std::dec;
		if constexpr (std::is_same_v<BitType, uint8_t>)
			std::cout << static_cast<int>(num);		// Cast as int so not treated as Char
		else
			std::cout << num;
	}
}

void printBitwiseResult(NumberInput num1, char op, NumberInput num2, BitType result)
{
	std::cout << "The " << BitTypeBits <<"-bit result of ";

	switch(op)
	{
	case '&': printFormattedNumber(num1.value, num1.base); std::cout << " AND "; printFormattedNumber(num2.value, num2.base); break;
	case '|': printFormattedNumber(num1.value, num1.base); std::cout <<  " OR "; printFormattedNumber(num2.value, num2.base); break;
	case '^': printFormattedNumber(num1.value, num1.base); std::cout << " XOR "; printFormattedNumber(num2.value, num2.base); break;
	case '~': std::cout << "NOT "; printFormattedNumber(num1.value, num1.base); break;
	case '<': printFormattedNumber(num1.value, num1.base); std::cout << " Left Shift "; printFormattedNumber(num2.value, num2.base); break;
	case '>': printFormattedNumber(num1.value, num1.base); std::cout << " Right Shift "; printFormattedNumber(num2.value, num2.base); break;
	}

	std::cout << '\n';

	std::cout << "Decimal: ";	printFormattedNumber(result, NumberBase::DECIMAL);	std::cout << '\n';
	std::cout << "Hex: "; 		printFormattedNumber(result, NumberBase::HEX);		std::cout << '\n';	
	std::cout << "Binary:\n";	printBinaryMulitpleLines(result); 					std::cout << '\n';	
}

void printConversionResult(NumberInput num, char conversionLetter)
{
	printFormattedNumber(num.value, num.base);
	std::cout << " is ";

	switch(conversionLetter)
	{
	case 'h': printFormattedNumber(num.value, NumberBase::HEX); std::cout << " in hex\n"; break;
	case 'b': printFormattedNumber(num.value, NumberBase::BINARY); std::cout << " in binary\n"; break;
	case 'd': printFormattedNumber(num.value, NumberBase::DECIMAL); std::cout << " in decimal\n"; break;
	}
}