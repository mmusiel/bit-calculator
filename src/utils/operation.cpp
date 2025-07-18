#include "operation.h"
#include "io.h"
#include <iostream>
#include <bitset>

void performBitwiseOperation()
{
	const NumberInput num1{ getNumberInputWithBase() };
	const char op{ getOperator() };
	NumberInput num2{};

	const bool needsSeconNum{ op != '~' };
	if (needsSeconNum)
		num2 = getNumberInputWithBase();

	// Perform operation
	BitType result{};
	switch(op)
	{
	case '&': result = num1.value & num2.value; break;
	case '|': result = num1.value | num2.value; break;
	case '^': result = num1.value ^ num2.value; break;
	case '~': result = ~num1.value; break;
	case '<':
		result = num1.value << num2.value;
		break;
	case '>':
		result = num1.value >> num2.value;
		break;
	}

	// printBitwiseResult(num1, op, num2, result, needsSecondNumber);

		// REMOVE: for testing
		if (num1.base == NumberBase::HEX)
		{
			std::cout << "Binary: " << std::bitset<BitTypeBits>{ num1.value } << '\n';
			std::cout << "Decimal: " << std::dec << num1.value << '\n';
		}
		if (num1.base == NumberBase::BINARY)
		{
			std::cout << "Hex: " << std::hex << num1.value << '\n';
			std::cout << "Decimal: " << std::dec << num1.value << '\n';
		}
		if (num1.base == NumberBase::DECIMAL)
		{
			std::cout << "Binary: " << std::bitset<BitTypeBits>{ num1.value } << '\n';
			std::cout << "Hex: " << std::hex << num1.value << '\n';
		}
		std::cout << "Operator: " << op << '\n';

		std::cout << "Result: " << std::dec << result << '\n';
}