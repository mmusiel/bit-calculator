#include "operation.h"
#include "../my-types.h"
#include "input.h"
#include "output.h"

void performBitwiseOperation()
{
	const NumberInput num1{ getNumberInputWithBase() };
	const char op{ getOperator() };
	NumberInput num2{};

	if (op != '~' )
	{
		if (op == '<' || op == '>')
			num2 = getNumberInputWithBase("Enter shift amount: ");
		else 
			num2 = getNumberInputWithBase();
	}

	// Perform operation
	BitType result{};
	switch(op)
	{
	case '&': result = num1.value & num2.value; break;
	case '|': result = num1.value | num2.value; break;
	case '^': result = num1.value ^ num2.value; break;
	case '~': result = ~num1.value; break;
	case '<': result = num1.value << num2.value; break;
	case '>': result = num1.value >> num2.value; break;
	}

	printBitwiseResult(num1, op, num2, result);
}