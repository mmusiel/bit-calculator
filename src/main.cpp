#include "calculator.h"
#include "utils.h"
#include "io.h"
#include <cstdint>
#include <iostream>

using BitType = uint32_t;	// Type alias, can change Bit size later

int main()
{
	std::cout << "Hello from Main!\n";

	printCalc();
	printIo();
	printUtils();

	return 0;
}