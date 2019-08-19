
/*
 This program converts decimal number into binary
using recursion. Also includes some manipulations
with the output stream for a better perception of
the binary number.
*/

#include "decToBin.hpp"
#include "input.hpp"
#include <iostream>

int main()
{
    while(true)
    {
        decToBin(static_cast<unsigned int>(getInput()));
        std::cout << "\n\n";

        if (!(tryAgain()))
            break;

        std::cout << '\n';
    }

    return 0;
}
