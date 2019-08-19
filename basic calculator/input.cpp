#include "input.hpp"
#include <iostream>

// Get user input for 2 numbers and character representing arithmetic operation
void getInput(int &integer1_out, int &integer2_out, char &op_out)
{
    while (true)
    {
        std::cout << "Input first integer: ";
        std::cin >> integer1_out;

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
        }
        else
        {
            std::cin.ignore(32767, '\n');
            break;
        }
    }

    while (true)
    {
        std::cout << "Enter mathematical operator (+, -, *, or /): ";
        std::cin >> op_out;
        std::cin.ignore(32767, '\n');

        if (op_out == '+' || op_out == '-' || op_out == '*' || op_out == '/')
            break;
    }

    while (true)
    {
        std::cout << "Input second integer: ";
        std::cin >> integer2_out;

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
        }
        else
        {
            std::cin.ignore(32767, '\n');
            break;
        }
    }
}

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
