#ifndef GAME_LOGIC_HPP_INCLUDED
#define GAME_LOGIC_HPP_INCLUDED

#include "Monster.hpp"
#include "Player.hpp"
#include <string>

std::string getName();
Player startGame();
bool fleeCheck();
bool attackMonster(Monster&, Player&);
void attackPlayer(Monster&, Player&);
void fightMonster(Monster&, Player&);
bool playAgain();
void playGame();

#endif // GAME_LOGIC_HPP_INCLUDED
