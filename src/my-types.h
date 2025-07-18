#ifndef MYTYPES_H
#define MYTYPES_H

#include <cstdint>

using BitType = uint32_t;	                        // Type alias, can change Bit size later
constexpr int BitTypeBits = sizeof(BitType) * 8;    // Automatically calculates bit width

enum class NumberBase
{
	DECIMAL,
	HEX,
	BINARY
};

struct NumberInput
{
	BitType value;
	NumberBase base;
};

#endif