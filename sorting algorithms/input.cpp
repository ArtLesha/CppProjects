#include "input.hpp"
#include <iostream>

void exit()
{
    char ch{};

    while (true)
    {
        std::cout << "\nType (e) to exit: ";
        std::cin >> ch;
        std::cin.ignore(32767, '\n');

        if (ch == 'e')
            return;
    }
}

char getOrder()
{
    char order{};

    while(true)
    {
        std::cout << "Do you want ascending or descending order (a/d)? ";
        std::cin >> order;
        std::cin.ignore(32767, '\n');

        if (order == 'a' || order == 'd')
           return order;
    }
}
