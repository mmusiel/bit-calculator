#ifndef IO_H
#define IO_H

#include "../my-types.h"
#include <string_view>

int getMenuChoice(int min, int max, std::string_view prompt);
BitType validateDecimal(std::string_view input);
BitType validateHex(std::string_view input);
BitType validateBinary(std::string_view input);
BitType getNumberInput();

#endif