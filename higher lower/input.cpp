#include "input.hpp"
#include <iostream>

void exit()
{
    char ch{};

    std::cout << "Thank you for playing";
    while (true)
    {
        std::cout << "\nType (e) to exit: ";
        std::cin >> ch;
        std::cin.ignore(32767, '\n');

        if (ch == 'e')
            return;
    }
}

// Get a guessed number from player with
// invalid input handling
int getUserInput(const int &counter)
{
    while (true)
    {
        std::cout << "\nGuess #" << counter << ": ";
        int userNumber;
        std::cin >> userNumber;

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            std::cout << "Incorrect input. Try again, please.\n";
        }
        else
        {
            std::cin.ignore(32767, '\n');
            return userNumber;
        }
    }
}

// "Play again" question
bool playAgain()
{
    char answer{};
    std::cout << '\n';
    while (true)
    {
        std::cout << "Would you like to play again (y/n)? ";
        std::cin >> answer;
        std::cin.ignore(32767, '\n');

        if (answer == 'y' || answer == 'n')
        {
            std::cout << '\n';
            return (answer == 'y');
        }
    }
}
