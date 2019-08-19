#ifndef MONSTER_HPP_INCLUDED
#define MONSTER_HPP_INCLUDED

#include "Creature.hpp"

class Monster : public Creature // Monster class definition
{                               // Child of Creature
public:
    enum Type // Enumeration of all possible types of Monsters
    {
        DRAGON,
        ORC,
        SLIME,
        MAX_TYPES
    };

private:
    Type m_type; // Type of the Monster

public:
    struct Attributes // Structure for holding Monsters attributes
    {
        const char* name;
        char symbol;
        uint health, damage, gold;
    };

    // Declaration of a lookup table
    static const Attributes s_monsterArr[MAX_TYPES];

     // Default constructor using delegating constructor and lookup table
    Monster(Type type)
        : Creature(s_monsterArr[type].name, s_monsterArr[type].symbol,
            s_monsterArr[type].health, s_monsterArr[type].damage,
            s_monsterArr[type].gold), m_type{type}
    {
    }

    static Monster generateMonster();
};

#endif // MONSTER_HPP_INCLUDED
