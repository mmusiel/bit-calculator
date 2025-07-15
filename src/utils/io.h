#ifndef IO_H
#define IO_H

#include "../my-types.h"
#include <string_view>

int getMenuChoice(int min, int max, std::string_view prompt);
BitType getNumberInput();

#endif