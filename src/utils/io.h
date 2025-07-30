#ifndef IO_H
#define IO_H

#include "../my-types.h"
#include <string_view>
#include <string>

int getMenuChoice(int min, int max, std::string_view prompt);
char getOperator();
char getConversionChoice(NumberInput num);
BitType checkBitTypeRange(std::string_view input, int numBase);
BitType validateHex(std::string_view input);
BitType validateBinary(std::string_view input);
BitType validateDecimal(std::string_view input);
NumberInput getNumberInputWithBase(const std::string& prompt = "Enter positive decimal, hex (prefix 0x), or binary (prefix 0b): ");

void printBit(BitType number, BitType power);
void printBinaryMulitpleLines(BitType number);
void printBinaryOneLine(BitType number);
void printFormattedNumber(BitType num, NumberBase base);
void printBitwiseResult(NumberInput num1, char op, NumberInput num2, BitType result);
void printConversionResult(NumberInput num, char conversionLetter);

#endif