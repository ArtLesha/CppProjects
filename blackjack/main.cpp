
/*
 This is an ordinary blackjack game. Goal of the game is to score more
total points than Dealer but no more than 21. If Dealer and Player have
the same amount of Points, Dealer wins. At the start of the game Dealer
gets one Card and Player - 2 Cards. Each turn Player can choose to hit
(take Card) or stand. Player can take Cards until he chooses to stand or
scores more than 21 points and looses. After Player stands Dealer gets
Cards until he has at least 17 points. He also can be busted if his total
amount of points will be more than 21. At the end of the game amount of
the points Dealer and Player have gets compared.

 Program consists of 2 classes: Card and Deck. Card class is a common Card
with it's own Rank and Suit. Deck represents array of 52 Cards each with
different set of Suit and Rank. Deck gets filled with the Cards at the start
of the game and shuffled by swapping each Card with another random Card in
the Deck. We also know Card that lies on the top of the Deck. Player and
Dealer are represented only by the number of Points that they have.
*/

#include "blackjack.hpp"
#include "input.hpp"
#include <iostream>
#include <cstdlib>  // std::srand()
#include <ctime>    // std::time()

int main()
{
    // Seed random number generator
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    std::cout << "\nHello, this is a Blackjack game.\n";
    while (true)
    {
        // Play one game
        if (playBlackjack())
            std::cout << "\nCongratulations, you won.\n\n";
        else
            std::cout << "\nSorry, you lost.\n\n";

        // Ask Player if he wants to play again
        if (!(playAgain()))
            break;
    }

    return 0;
}
