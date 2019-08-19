#include "Card.hpp"
#include <iostream>

// Handles enumeration based printing of Card's rank and suit
void Card::printCard() const
{
    switch (m_rank)
    {
        case RANK_2:		std::cout << '2'; break;
        case RANK_3:		std::cout << '3'; break;
        case RANK_4:		std::cout << '4'; break;
        case RANK_5:		std::cout << '5'; break;
        case RANK_6:		std::cout << '6'; break;
        case RANK_7:		std::cout << '7'; break;
        case RANK_8:		std::cout << '8'; break;
        case RANK_9:		std::cout << '9'; break;
        case RANK_10:		std::cout << 'T'; break;
        case RANK_JACK:		std::cout << 'J'; break;
        case RANK_QUEEN:	std::cout << 'Q'; break;
        case RANK_KING:		std::cout << 'K'; break;
        case RANK_ACE:		std::cout << 'A'; break;
        case MAX_RANKS:     std::cout << '0'; break;
    }

    switch (m_suit)
    {
        case SUIT_CLUB:		std::cout << 'C'; break;
        case SUIT_DIAMOND:	std::cout << 'D'; break;
        case SUIT_HEART:	std::cout << 'H'; break;
        case SUIT_SPADE:	std::cout << 'S'; break;
        case MAX_SUITS:     std::cout << '0'; break;
    }
}

// Enumeration based getter
// Cards with rank 10, Jack, Queen and King worth 10 points
int Card::getCardValue() const
{
    switch (m_rank)
    {
    case RANK_2:		return 2;
    case RANK_3:		return 3;
    case RANK_4:		return 4;
    case RANK_5:		return 5;
    case RANK_6:		return 6;
    case RANK_7:		return 7;
    case RANK_8:		return 8;
    case RANK_9:		return 9;
    case RANK_10:		return 10;
    case RANK_JACK:		return 10;
    case RANK_QUEEN:	return 10;
    case RANK_KING:		return 10;
    case RANK_ACE:		return 11;
    case MAX_RANKS:     return 0;
    }

    return 0;
}
