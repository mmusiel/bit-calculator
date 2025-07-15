#include "my-types.h"
#include "operations.h"
#include "conversions.h"
#include "io.h"
#include <iostream>

int main()
{
	do
	{
		std::cout << "1) Bitwise operation (AND, OR, XOR, NOT, or Left/Right Shifts)\n";
		std::cout << "2) Number conversion (Decimal, Binary, Hexadecimal)\n";
		std::cout << "3) Exit\n";

		constexpr int minMenuOption{ 1 };
		constexpr int maxMenuOption{ 3 };

		const int menuChoice{ getInt(minMenuOption, maxMenuOption, "Enter menu choice: ") };

		std::cout << menuChoice << '\n';
		
	}
	while(false);

	std::cout << "Exiting calculator.\n";

	return 0;
}