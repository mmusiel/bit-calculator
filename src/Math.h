#ifndef MATH_H
#define MATH_H

#include "my-types.h"

namespace Math
{
    // Recursive function to calculate power
    BitType power(BitType base, BitType exp)
    {
        // Base case: any number to the power of 0 is 1
        if (exp == 0)
            return 1;

        // Recursive step for positive exponents
        else if (exp > 0)
            return base * power(base, exp - 1);

        // Handling for negative exponents
        else
            return 1 / power(base, -exp);
    }
}

#endif