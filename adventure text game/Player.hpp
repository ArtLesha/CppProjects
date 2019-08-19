#ifndef PLAYER_HPP_INCLUDED
#define PLAYER_HPP_INCLUDED

#include "Creature.hpp"

class Player : public Creature // Player class definition
{                              // Child of Creature
private:
    uint m_level{1}; // Player's level is always 1 at start

public:
    // Default constructor
    Player(std::string name)
        : Creature(name, '@', 10, 1, 0) // Default Player's attributes
    {
    }

    // Standard getter
    const uint& getLevel() const { return m_level; }

    void levelUp();
    void addGold(const uint&);
    bool hasWon() const;
};

#endif // PLAYER_HPP_INCLUDED
