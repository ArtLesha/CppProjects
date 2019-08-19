#include "Creature.hpp"

// General function for attacks
void Creature::reduceHealth(uint damage)
{
    // If the amount of damage dealt is more than current health,
    // equate health to zero, so that it remains a positive number
    if (damage >= m_health)
        m_health = 0;
    else
        m_health -= damage; // else subtract dealt damage
}

// Death check
bool Creature::isDead() { return m_health == 0; }
