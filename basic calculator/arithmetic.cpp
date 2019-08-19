#include "arithmetic.hpp"
#include <iostream>

// Namespace with functions for arithmetic operations
namespace Arithmetic
{
    int add(const int &integer1, const int &integer2)
    {
        return integer1 + integer2;
    }

    int subtract(const int &integer1, const int &integer2)
    {
        return integer1 - integer2;
    }

    int multiply(const int &integer1, const int &integer2)
    {
        return integer1 * integer2;
    }

    int divide(const int &integer1, const int &integer2)
    {
        return integer1 / integer2;
    }
}

// Initialization of associative table
static const arithmeticStruct arith_array[] {
    { '+', Arithmetic::add },
    { '-', Arithmetic::subtract },
    { '*', Arithmetic::multiply },
    { '/', Arithmetic::divide }
};

// The function makes association between user-inputted sign
// and arithmetic function using associative table
// int (*getArithmeticFunction(const char &op))(const int &, const int &)
arithmeticFcn getArithmeticFunction (const char &op)
{
    for (const auto &arithmetic : arith_array)
        if (arithmetic.op == op)
            return arithmetic.fcn;

    return Arithmetic::add;
}
