#include "io.h"
#include "../CinErrorHandling.h"
#include <iostream>

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
			std::cout << "Invalid menu choice. Try again.\n";
			continue;
		}

		return number;
	}
}