#ifndef CARD_HPP_INCLUDED
#define CARD_HPP_INCLUDED

class Card // Card class definition
{
public:
    enum Rank // Enumeration of all possible Card ranks
    {
        RANK_2,
        RANK_3,
        RANK_4,
        RANK_5,
        RANK_6,
        RANK_7,
        RANK_8,
        RANK_9,
        RANK_10,
        RANK_JACK,
        RANK_QUEEN,
        RANK_KING,
        RANK_ACE,
        MAX_RANKS
    };

    enum Suit // Enumeration of all possible Card suits
    {
        SUIT_CLUB,
        SUIT_DIAMOND,
        SUIT_HEART,
        SUIT_SPADE,
        MAX_SUITS
    };

private:
    Rank m_rank; // Holds Card's rank
    Suit m_suit; // Holds Card's suit

public:
    // Default constructor
    Card(Rank rank = RANK_2, Suit suit = SUIT_CLUB)
        : m_rank{rank}, m_suit{suit}
    {
    }

    void printCard() const;
    int getCardValue() const;
};

#endif // CARD_HPP_INCLUDED
