
/*
 This is a basic "Higher or Lower" guessing game.
The program consists of 3 functions: one to get user
input, one for game's logic and one for "play again"
question. Also the program implements input verification
for all kinds of cases.
*/

#include "higherLower.hpp"
#include "input.hpp"
#include <iostream>
#include <random> // for Mersenne Twister algorithm
#include <ctime> // for std::time to seed Mersenne

int main()
{
    // Seed the random number generator
    std::mt19937 mersenne(static_cast<unsigned int>(std::time(nullptr)));
    // Create uniform integer numbers distribution in range [1, 100]
    std::uniform_int_distribution<> rand(1, 100);

    // The number of guesses player receives
    constexpr int numGuesses = 7;

    // Play until the player refuses to continue
    do
    {
        int randomNumber = rand(mersenne); // Get random number

        std::cout << "Let's play a game. I'm thinking of a number between 1 and 100."
                  << "\nYou have " << numGuesses << " tries to guess what it is.\n";

        // Play one game session
        if (playGame(numGuesses, randomNumber))
            std::cout << "\nCorrect, you won.\n";
        else
            std::cout << "\nSorry, you lost. The correct number was "
                      << randomNumber << ".\n";

    } while (playAgain());

    exit();

    return 0;
}
