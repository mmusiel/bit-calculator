#include "io.h"
#include "../CinErrorHandling.h"
#include "../my-types.h"
#include <string>
#include <string_view>
#include <iostream>

// Display prompt, get number from user, check if number is valid, return number
int getMenuChoice(int min, int max, std::string_view prompt)
{
	while(true)
	{
		std::cout << prompt;
		int number{};
		std::cin >> number;

		bool outOfBounds{ number < min || number > max };

		if(CinError::clearUnextractedInput() || CinError::clearFailedExtraction() || outOfBounds)
		{
			std::cout << "Invalid input. ";
			continue;
		}

		return number;
	}
}

BitType validateHex(std::string_view input) {
    // Validate hex digits after 0x
    // Check range for 32-bit
    // Return uint32_t

	std::cout << "Hex: " << input << '\n';
    return 0;
}

BitType validateBinary(std::string_view input) {
    // Validate binary digits after 0b
    // Check range for 32-bit (max 32 digits)
    // Return uint32_t

	std::cout << "Binary: " << input << '\n';
    return 0;
}

BitType validateDecimal(std::string_view input) {
    // Validate decimal digits only
    // Check range for 32-bit
    // Return uint32_t

	std::cout << "Decimal: " << input << '\n';
    return 0;
}

// Get string input, determine number type, call appropriate function to validate input
BitType getNumberInput()
{
	while(true)
	{
		std::cout << "Enter decimal, prefix 0x for hex or 0b for binary: ";
		std::string input;
		std::getline(std::cin >> std::ws, input);

		// Hexadecimal
		if (input.substr(0,2) == "0x" || input.substr(0,2) == "0X")
			return validateHex(input);

		// Binary
		else if (input.substr(0,2) == "0b" || input.substr(0,2) == "0B")
			return validateBinary(input);

		// Decimal
		else
			return validateDecimal(input);
	}
}