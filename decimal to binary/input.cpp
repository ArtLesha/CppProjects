#include "input.hpp"
#include <iostream>

bool tryAgain()
{
    char answer{};

    while (true)
    {
        std::cout << "Do you want to try again? (y/n)? ";
        std::cin >> answer;
        std::cin.ignore(32767, '\n');

        if (answer == 'y' || answer == 'n')
            return (answer == 'y');
    }
}

int getInput()
{
    int number{};

    while (true)
    {
        std::cout << "Enter an integer to convert it to binary: ";
        std::cin >> number;

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
        }
        else
        {
            std::cin.ignore(32767, '\n');
            return number;
        }
    }
}
