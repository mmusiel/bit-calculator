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

BitType getNumberInput()
{
	while(true)
	{
		std::cout << "Enter decimal, prefix 0x for hex or 0b for binary: ";
		std::string input;
		std::getline(std::cin >> std::ws, input);

		bool failedExtraction{ CinError::clearFailedExtraction() }; // testing if clearFailedExtraction() is needed

		if (failedExtraction || input.empty())
		{
			std::cout << "Invalid input. ";
			continue;
		}

		return 0;
	}
}