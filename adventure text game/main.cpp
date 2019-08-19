
/*
 This is an ordinary adventure RPG-like text game. There is a Player who starts
the game at level 1 with default set of attributes. Player will meet Monsters
that can be either a slime, an orc, or a dragon. He can choose to run away or
fight with them. Fight is turn-based. If Player wins the fight, he will level
up, increase his attributes and get Monster's gold. The goal of the game is to
reach level 10 with the most amount of gold.

 The program implements the concept of inheritance. There are 3 classes: 1 parent
(Creature) and 2 derived (Monster, Player). Parent is comprised of the set of
default parameters such as name, health, damage, etc. Player additionally has level
field and some methods. Every type of Monster has consistent attributes. Because of
this, implementation of each individual Monster is performed using lookup table.
Creation of a random Monster is performed using generateMonster() function, which
relies on a random number generator based on the Mersenne Twister algorithm.
*/

#include "game_logic.hpp"
#include <iostream>

int main()
{
    playGame();

    return 0;
}
