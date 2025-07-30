#include "io.h"
#include "../CinErrorHandling.h"
#include "../Math.h"
#include <iostream>
#include <type_traits> 

// Display prompt, get number from user, check if number is valid, return number
int getMenuChoice(int min, int max, std::string_view prompt)
{
	while(true)
	{
		std::cout << prompt;
		int number{};
		std::cin >> number;

		bool outOfRange{ number < min || number > max };

		if(CinError::clearUnextractedInput() || CinError::clearFailedExtraction() || outOfRange)
		{
			std::cout << "Invalid input. ";
			continue;
		}

		return number;
	}
}

// Present menu of operations, get choice, return operation
char getOperator()
{
	std::cout << "Choose bitwise operation:\n";
    std::cout << "1) AND\n";
    std::cout << "2) OR\n";
    std::cout << "3) XOR\n";
    std::cout << "4) NOT\n";
    std::cout << "5) Left shift\n";
    std::cout << "6) Right shift\n";

    constexpr int min_MenuOption{ 1 };
	constexpr int max_MenuOption{ 6 };

    const int choice{ getMenuChoice(min_MenuOption, max_MenuOption, "Enter operation choice: ") };

    switch(choice)
    {
    case 1: return '&';
    case 2: return '|';
    case 3: return '^';
    case 4: return '~';
 	case 5: return '<';		// '<' to represent left shift
    case 6: return '>';		// '>' to represent right shift
    default: return '\0';	// Should never reach here
    }
}

char getConversionChoice(NumberInput num)
{
	std::cout << "Choose conversion: \n";

	constexpr int min_MenuOption{ 1 };
	constexpr int max_MenuOption{ 2 };

	// Original number is Hex
	if (num.base == NumberBase::HEX)
	{
		std::cout << "1) Binary\n";
		std::cout << "2) Decimal\n";

		const int choice{ getMenuChoice(min_MenuOption, max_MenuOption, "Enter conversion choice: ") };

		switch(choice)
		{
		case 1: return 'b';
		case 2: return 'd';
		default: return '\0';	// Should never reach here
		}
	}

	// Original number is Binary
	else if (num.base == NumberBase::BINARY)
	{
		std::cout << "1) Hex\n";
		std::cout << "2) Decimal\n";

		const int choice{ getMenuChoice(min_MenuOption, max_MenuOption, "Enter conversion choice: ") };

		switch(choice)
		{
		case 1: return 'h';
		case 2: return 'd';
		default: return '\0';	// Should never reach here
		}
	}

	// Original number is Decimal
	else if (num.base == NumberBase::DECIMAL)
	{
		std::cout << "1) Hex\n";
		std::cout << "2) Binary\n";

		const int choice{ getMenuChoice(min_MenuOption, max_MenuOption, "Enter conversion choice: ") };

		switch(choice)
		{
		case 1: return 'h';
		case 2: return 'b';
		default: return '\0';	// Should never reach here
		}
	}

	else return '\0';	// Should never reach here	
}

// Check if within BitType range
BitType checkBitTypeRange(std::string_view input, int numBase)
{
	try
	{
		// Check if in BitType range
		const unsigned long temp{ std::stoul(std::string(input), nullptr, numBase) };	// wrapping 'input' to convert to string
		if (temp > std::numeric_limits<BitType>::max())
			throw std::out_of_range("");
			
		return static_cast<BitType>(temp);
	}	
	catch(const std::out_of_range&)			// this catches the 'stoul' error
	{
		throw std::out_of_range("Number too large for bit-type limit");
	}
}

// Validate only Hex values are entered
BitType validateHex(std::string_view input) {
	if (input.length() <= 2)
		throw std::invalid_argument("Incomplete hex number");

	// Validate hex digits after 0x
	for (size_t i = 2; i < input.length(); ++i)
	{
		if(!std::isxdigit(input[i]))
			throw std::invalid_argument("Invalid hex digit");
	}

	return checkBitTypeRange(input.substr(2), 16);
}

// Validate only binary values are entered
BitType validateBinary(std::string_view input) {
	if (input.length() <= 2)
		throw std::invalid_argument("Incomplete binary number");

	// Validate binary digits after 0b
	for (size_t i{ 2 }; i < input.length(); ++i)
	{
		if (input[i] != '0' && input[i] != '1')
			throw std::invalid_argument("Invalid binary digit");
	}

	return checkBitTypeRange(input.substr(2), 2);
}

// Validate only decimal numbers are entered, and is in BitType range
BitType validateDecimal(std::string_view input) {
	// Check for invalid decimal characters
	for (char c : input)
	{
		if (!std::isdigit(c))
			throw std::invalid_argument("Invalid decimal digit");
	}

	return checkBitTypeRange(input, 10);
}

// Get string input, determine number base, call appropriate function to validate input
NumberInput getNumberInputWithBase(const std::string& prompt)
{
	while(true)
	{
		try
		{
			std::cout << prompt;
			std::string input;
			std::getline(std::cin >> std::ws, input);

			// Check for empty string
			if (CinError::clearFailedExtraction() || input.empty()) {
				throw std::invalid_argument("Empty input");
			}
			
			// Check if negative
			const char firstChar{ input[0] };
			const char secondChar{ input[1] };
			if (firstChar == '-' && std::isdigit(secondChar))
				throw std::out_of_range("Negative number is out of range");

			NumberInput result{};

			// Hexadecimal validation and return
			if (input.substr(0, 2) == "0x" || input.substr(0, 2) == "0X")
			{
				result.value = validateHex(input);
				result.base = NumberBase::HEX;
				return result;
			}

			// Binary validation and return
			else if (input.substr(0, 2) == "0b" || input.substr(0, 2) == "0B")
			{
				result.value = validateBinary(input);
				result.base = NumberBase::BINARY;
				return result;
			}

			// Decimal validation and return
			else
			{
				result.value = validateDecimal(input);
				result.base = NumberBase::DECIMAL;
				return result;
			}
		}
		catch (const std::out_of_range& error)
		{
			std::cout << "Error: " << error.what() << ". Try again.\n";;
		}
		catch (const std::invalid_argument& error)
		{
			std::cout << "Error: " << error.what() << ". Try again.\n";
		}
	}
}

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