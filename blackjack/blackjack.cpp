#include "blackjack.hpp"
#include "Deck.hpp"
#include "input.hpp"
#include <iostream>

// Handles the game's logic. Returns 1 for Player's win and 0 for loss.
bool playBlackjack()
{
    // Create and shuffle the Deck
    Deck deck;
    deck.shuffleDeck();
    //deck.printDeck();

	int playerTotal{}; // Player's total score
	int dealerTotal{}; // Dealer's total score

	// Deal one Card to the Dealer
	dealerTotal += deck.dealCard().getCardValue();
	std::cout << "\nThe dealer gets one card and has "
              << dealerTotal << " points." <<"\n\n";

	// Deal two Cards to the Player
	playerTotal += deck.dealCard().getCardValue();
	playerTotal += deck.dealCard().getCardValue();
    std::cout << "You got 2 cards.\n";

	// Player goes first
	while (true)
	{
		std::cout << "Now you have " << playerTotal << " points.\n";
		if (getPlayerChoice() == 'h') // Deal one Card to the Player if he hits
            playerTotal += deck.dealCard().getCardValue();
        else
            break; // Stops if Player wants to stand

		// If Player has more than 21 points then he loses
		if (playerTotal > 21)
        {
            std::cout << "You are busted with " << playerTotal << " points.\n";
			return false;
        }
	}

	std::cout << '\n';
	// After Player's phase Dealer draws Cards until he has at least 17 points
	while (dealerTotal < 17)
	{
		dealerTotal += deck.dealCard().getCardValue();
		std::cout << "The dealer gets one card and now has "
                  << dealerTotal << " points.\n";
	}

	// If Dealer is busted, Player wins
	if (dealerTotal > 21)
    {
        std::cout << "Dealer is now busted.\n";
		return true;
    }

    // Otherwise compare Player's and Dealer's hands
    // Wins the one who has more valuable Cards (total points)
    // If Player and Dealer have the same score - Player loses
	return (playerTotal > dealerTotal);
}
