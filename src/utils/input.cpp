#include "input.h"
#include "../CinErrorHandling.h"
#include <iostream>

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