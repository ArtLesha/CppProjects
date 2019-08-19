#include "Deck.hpp"
#include <iostream>
#include <cstdlib> // for std::rand
#include <cassert> // for assert()

// Random number generator
int Deck::getRandomNumber(int min, int max)
{
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
    return static_cast<int> (std::rand() * fraction * (max - min + 1) + min);
}

// Function that swaps two Cards (used for Deck shuffling)
void Deck::swapCard(Card &a, Card &b)
{
    Card temp = a;
    a = b;
    b = temp;
}

// Default constructor that fills the Deck with 52 Cards one by one
Deck::Deck()
{
    index_t currentIndex{}; // Index for last created Card in the Deck

    // Outer loop is for the suits
    for (int suit{}; suit < Card::MAX_SUITS; ++suit)
        for (int rank{}; rank < Card::MAX_RANKS; ++rank) // Inner loop is for the ranks
        {
            m_deck[currentIndex] = Card(static_cast<Card::Rank>(rank),
                                        static_cast<Card::Suit>(suit));
            ++currentIndex;
        }
}

void Deck::printDeck() const // Prints out full Deck
{
    std::cout << '\n';
    int counter {};
    for (const auto &card : m_deck)
    {
        card.printCard();
        ++counter;
        std::cout << ' ';

        if (!(counter % 13))
            std::cout << '\n';
    }
}

// Handles the shuffling of the Deck
void Deck::shuffleDeck()
{
    // Step through each Card in the Deck
    for (index_t index{}; index < 52; ++index)
    {
        // Pick a random Card from the Deck
        index_t swapIndex = static_cast<unsigned int>(getRandomNumber(0, 51));
        // Swap it with the current Card
        swapCard(m_deck[index], m_deck[swapIndex]);
    }

    m_cardIndex = 0; // Makes the Card that lies on top of the Deck the first playable
}

// Draws a Card from the top of the Deck
const Card& Deck::dealCard()
{
    assert(m_cardIndex < 52);
    return m_deck[m_cardIndex++]; // Draws first then makes the top Card next playable
}
