#include "conversions.h"
#include "../my-types.h"
#include "io.h"
#include <iostream>

void performConversion()
{
	const NumberInput num{ getNumberInputWithBase("Enter positive decimal, hex (prefix 0x), or binary (prefix 0b) to convert: ") };
	char conversionLetter{ getConversionChoice(num) };
	printConversionResult(num, conversionLetter);
}