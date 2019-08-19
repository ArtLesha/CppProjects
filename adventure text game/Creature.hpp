#ifndef CREATURE_HPP_INCLUDED
#define CREATURE_HPP_INCLUDED

#include <string>

using uint = unsigned int;

class Creature // Creature class definition
{              // Parent of Player and Monster
protected:
    std::string  m_name;   // Name of the Creature
    char         m_symbol; // Abbreviation for the Creature's name
    uint         m_health, // Amount of health Creature has
                 m_damage, // Amount of damage Creature does per attack
                 m_gold;   // Amount of gold Creature is carrying

    // Default constructor
    Creature(std::string name, char symbol, uint health, uint damage, uint gold)
        : m_name{name}, m_symbol{symbol}, m_health{health},
          m_damage{damage}, m_gold{gold}
    {
    }

public:
    // List of standard getters
    const std::string& getName()   const { return m_name; }
    const char&        getSymbol() const { return m_symbol; }
    const uint&        getHealth() const { return m_health; }
    const uint&        getDamage() const { return m_damage; }
    const uint&        getGold()   const { return m_gold; }

    void reduceHealth(uint);
    bool isDead();
};

#endif // CREATURE_HPP_INCLUDED
