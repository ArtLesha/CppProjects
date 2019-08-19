#ifndef DECK_HPP_INCLUDED
#define DECK_HPP_INCLUDED

#include "Card.hpp"
#include <array> // for std::array<>

class Deck // Deck class definition
{
private:
    using index_t = std::array<Card, 52>::size_type; //type alias

    // Deck consists of 52 cards (13 ranks x 4 suits)
    std::array<Card, 52> m_deck{}; // Array that represents Deck of Cards
    index_t m_cardIndex {};        // Contains the index of the top card to be played next

    static int getRandomNumber(int, int);
    static void swapCard(Card&, Card&);

public:
    Deck();

    void printDeck() const;
    void shuffleDeck();
    const Card& dealCard();
};

#endif // DECK_HPP_INCLUDED
