#include "Monster.hpp"
#include "random.hpp"
#include <iostream>

// Monster generator using random number generator
Monster Monster::generateMonster()
{
    Monster monster{static_cast<Type>(getRandom(0, MAX_TYPES - 1))};
    std::cout << "\n\nYou have encountered a " << monster.m_name
              << " (" << monster.m_symbol << ") with " << monster.m_health
              << " hit points and " << monster.m_damage << " attack damage.\n";
    return monster;
}

// Lookup table for predefined attributes of Monsters
const Monster::Attributes Monster::s_monsterArr[Monster::MAX_TYPES]
{
    {"dragon", 'D', 20, 4, 100},
    {"orc",    'o', 4,  2, 25},
    {"slime",  's', 1,  1, 10}
};
