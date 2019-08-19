#include "higherLower.hpp"
#include "input.hpp"
#include <iostream>

// Game's logic: player should guess randomly generated number.
// He has 7 attempts to guess the number. If the guessed number
// is higher or lower than randomly generated, then the
// corresponding message will be displayed on the screen.
// If the player guesses the number right, he will win.
bool playGame(const int &numGuesses, const int& randomNumber)
{
    for (int counter{1}; counter <= numGuesses; ++counter)
    {
        int userGuess = getUserInput(counter);

        if (userGuess > randomNumber)
            std::cout << "Your guess is too high.\n";
        else if (userGuess < randomNumber)
            std::cout << "Your guess is too low.\n";
        else
            return true;
    }

    return false;
}
