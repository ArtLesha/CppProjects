#include "input.hpp"
#include <iostream>

void exit()
{
    char ch{};

    while (true)
    {
        std::cout << "Type (e) to exit: ";
        std::cin >> ch;
        std::cin.ignore(32767, '\n');

        if (ch == 'e')
            return;
    }
}
