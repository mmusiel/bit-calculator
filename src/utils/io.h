#ifndef IO_H
#define IO_H

#include "../my-types.h"
#include <string_view>
#include <string>

int getMenuChoice(int min, int max, std::string_view prompt);
char getOperator();
BitType checkBitTypeRange(std::string_view input);
BitType validateDecimal(std::string_view input);
BitType validateHex(std::string_view input);
BitType validateBinary(std::string_view input);
NumberInput getNumberInputWithBase(const std::string& prompt = "Enter positive decimal, hex (prefix 0x), or binary (prefix 0b): ");
void printBit(BitType number, BitType power);
void printBinary(BitType number);
void printBitwiseResult(NumberInput num1, char op, NumberInput num2, BitType result);

#endif