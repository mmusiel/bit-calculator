#ifndef OUTPUT_H
#define OUTPUT_H

#include "../my-types.h"

void printBit(BitType number, BitType power);
void printBinaryMulitpleLines(BitType number);
void printBinaryOneLine(BitType number);
void printFormattedNumber(BitType num, NumberBase base);
void printBitwiseResult(NumberInput num1, char op, NumberInput num2, BitType result);
void printConversionResult(NumberInput num, char conversionLetter);

#endif