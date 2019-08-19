#include "input.hpp"
#include <iostream>

bool playAgain()
{
    char answer{};
    while (true)
    {
        std::cout << "Do you want to play again (y/n)? ";
        std::cin >> answer;
        std::cin.ignore(32767, '\n');

        if (answer == 'y' || answer == 'n')
            return (answer == 'y');
    }
}

// Ask Player if he wants to get one more Card
// or leave his hand as it is.
// 1 - for hit, 0 - for stand
char getPlayerChoice()
{
    std::cout << '\n';

	char choice;
	while (true)
	{
	    std::cout << "Do you want to hit or stand (h/s)? ";
        std::cin >> choice;
        std::cin.ignore(32767, '\n');

        if (choice == 'h' || choice == 's')
            return choice;
	}
}
