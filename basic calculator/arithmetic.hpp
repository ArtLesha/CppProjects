#ifndef ARITHMETIC_HPP_INCLUDED
#define ARITHMETIC_HPP_INCLUDED

// Alias for a type of pointers to arithmetic functions
using arithmeticFcn = int (*)(const int&, const int&);
//typedef int (*arithmeticFcn)(const int&, const int&);

// Namespace with functions for arithmetic operations
namespace Arithmetic
{
    int add(const int &, const int &);
    int subtract(const int &, const int &);
    int multiply(const int &, const int &);
    int divide(const int &, const int &);
}

// Structure for associative table of signs and arithmetic functions
struct arithmeticStruct
{
    char op;
    arithmeticFcn fcn;
};

// The function makes association between user-inputted sign
// and arithmetic function using associative table
arithmeticFcn getArithmeticFunction (const char&);

#endif // ARITHMETIC_HPP_INCLUDED
