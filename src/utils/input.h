#ifndef INPUT_H
#define INPUT_H

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

#endif