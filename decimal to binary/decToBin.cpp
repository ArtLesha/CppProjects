#include "decToBin.hpp"
#include <iostream>

void decToBin(unsigned int number)
{
    // s_numDigits represents the total amount of digits in binary number,
    // starting from 1, and is used to supplement the number of displayed
    // bits to an octet, if the number of bits is not a multiple of 8
    static int s_numDigits{0},
               s_counter{0}; // Represents the amount of actual printed bits
                             // and used to split the number into nibbles
    ++s_numDigits;

    // Recursion will continue until the dividend becomes 1, then it
    // will be the most significant bit of the binary number
    if (number > 1)
        decToBin(number >> 1); // Bitwise right shift by 1 place is equal to
                               // division by 2 and performs faster
    // Supplement to an octet
    while (s_numDigits % 8)
    {
        std::cout << "0";
        ++s_numDigits;
        ++s_counter;

        if (!(s_counter % 4)) // Split into nibbles
            std::cout << " ";
    }

    // The remainder of dividing by 2 will be the value of the bit.
    // The value of MSB is the result of the last recursion iteration
    std::cout << number % 2; //
    ++s_counter;

    if (!(s_counter % 4)) // Split into nibbles
        std::cout << " ";
}
