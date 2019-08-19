
/*
 This is a calculator operating on two integer numbers inputted
by user with 4 basic arithmetic operations using function pointers.
*/

#include "input.hpp"
#include "arithmetic.hpp"
#include <iostream>

int main()
{
    while (true)
    {
        // Variables that will store user input
        int x{},
            y{};
        char arith_operator{};

        getInput(x, y, arith_operator);

        // Get arithmetic function based on user choice
        arithmeticFcn arithmetic { getArithmeticFunction(arith_operator) };

        std::cout << "\n" << x << " " << arith_operator << " " << y << " = "
                  << arithmetic(x,y) << "\n\n";

        //std::cout << Arithmetic::add(2, 4);

        if (!(tryAgain()))
            break;

        std::cout << '\n';
    }

    return 0;
}
