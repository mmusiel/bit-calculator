#ifndef INPUT_H
#define INPUT_H

#include "../my-types.h"
#include <string_view>
#include <string>

int getMenuChoice(int min, int max, std::string_view prompt);
char getOperator();
BitType checkBitTypeRange(std::string_view input);
BitType validateDecimal(std::string_view input);
BitType validateHex(std::string_view input);
BitType validateBinary(std::string_view input);
BitType getNumberInput(const std::string& prompt = "Enter positive decimal, hex (prefix 0x), or binary (prefix 0b): ");

#endif