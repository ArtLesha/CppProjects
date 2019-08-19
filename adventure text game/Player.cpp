#include "Player.hpp"
#include <iostream>

// Increasing Player's attributes after level up
void Player::levelUp()
{
    ++m_level; ++m_damage; // Increase the damage done and level
    // Static so we keep amount of maximum health through the game
    static uint max_health{10};
    max_health += 2;       // Increase the amount of maximum health
    m_health = max_health; // Restore health to full
}

// If Monster dies his gold goes to the Player
void Player::addGold(const uint& amount)
{
    m_gold += amount;
    std::cout << "You have found " << amount << " gold and now have "
              << getGold() << " gold in your pocket.";
}

// If Player's level is 10 or more, he wins the game
bool Player::hasWon() const { return m_level >= 10; }
