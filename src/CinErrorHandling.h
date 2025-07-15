#ifndef CIN_ERROR_HANDLING_H
#define CIN_ERROR_HANDLING_H

#include <iostream>
#include <limits> // for std::numeric_limits

namespace CinError
{
	/**
	 * @brief Remove extraneous input from buffer
	 */
	void clearLine()
	{
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //ignore all characters up to the next ‘\n’
	}

	/**
	 * @brief Check if std::cin has unextracted input on the current line,
	 * 			then remove extraneous input
	 * @return True if unexpected input detected, False otherwise
	 */
	bool clearUnextractedInput()
	{
		if(!std::cin.eof() && std::cin.peek() != '\n')
		{
			std::cin.clear();   // Put us back in 'normal' operation mode
			clearLine();       // And remove the bad input
			return true;
		}
		return false;
	}

	/**
	 * @brief Test for and fix failed extractions or overflow, then remove extraneous input
	 * @return True if extraction failed, False otherwise
	 */
	bool clearFailedExtraction()
	{
		// Check for failed extraction
		if (!std::cin)				// If the previous extraction failed
		{
			if (std::cin.eof())		// If the stream was closed
			{
				std::cout << '\n';
				std::exit(0);		// Shut down the program now
			}

			// Handle the failure
			std::cin.clear();		// Put us back in 'normal' operation mode
			clearLine();			// And remove the bad input

			return true;
		}
		return false;
	}
}

#endif