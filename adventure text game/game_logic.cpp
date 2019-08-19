#include "game_logic.hpp"
#include "random.hpp"
#include <iostream>
#include <string>

using std::cin;
using std::cout;

// Beginning of the game
std::string getName()
{
    cout << "WELCOME TO THE GAME\nPlease, enter your name: ";
    std::string name{};
    std::getline(cin, name);
    return name;
}

// Intro to the game describing the initial Player's attributes
Player startGame()
{
    // Initialization of Player object
    Player player{ getName() };
    cout << "\nHey, " << player.getName() << ". Your journey begins here.\n"
         << "You have " << player.getHealth() << " health and dealing "
         << player.getDamage() << " damage per attack.";

    return player;
}

// Check if Player successfully fleeing from the encounter using random number
// generator. Player has a 50% chance to escape from the encounter with the Monster
bool fleeCheck()
{
    if (getRandom(0, 1))
    {
        cout << "\nYou successfully fled.";
        return 1;
    }
    else
    {
        cout << "\nYou failed to flee.";
        return 0;
    }
}

// Player is attacking monster (return 0 if Monster lives and 1 if dies)
bool attackMonster(Monster &m, Player &p)
{
    // Reduce Player's health by Monster's damage
    m.reduceHealth(p.getDamage());
    cout << "\nYou hit the " << m.getName() << " for "
         << p.getDamage() << " damage. Now he has "
         << m.getHealth() << " hit points.";

    if (m.isDead()) // If Monster died, Player levels up and get the gold
    {
        p.levelUp();
        cout << "\nYou killed the " << m.getName()
             << " and leveled up.\n\n"
             << "You are now level " << p.getLevel()
             << " with " << p.getHealth() << " hit points and "
             << p.getDamage() << " attack damage.\n";

        p.addGold(m.getGold());
        return 1;
    }

    return 0;
}

// Monster is attacking Player
void attackPlayer(Monster &m, Player &p)
{
    //Reduce Monster's health by Player's damage
    p.reduceHealth(m.getDamage());
    cout << '\n' << m.getName() << " hit you for " << m.getDamage()
         << " damage. Now you have " << p.getHealth() << " hit points.\n";
}

// Handles one entire encounter between Monster and Player
// Encounter ends if Player successfully runs away or Monster/Player dies
void fightMonster(Monster &m, Player &p)
{
    do
    {
        cout << '\n';
        char answer{};
        while (true)
        {
            cout << "Want to fight(f) or run(r)? ";
            cin >> answer;
            cin.ignore(32767, '\n');

            if (answer == 'f' || answer == 'r')
                break;
        }

        if (answer == 'f') // Player chose to fight with the Monster
        {
            if(attackMonster(m, p)) // Player attacks first
                return;             // If Monster dies, encounter ends
            attackPlayer(m, p);     // Monster attacks second
        }

        else // Gives Player opportunity to flee from the Monster
        {
            if (fleeCheck()) // If escape is successful Player runs away from the battle
                return;      // Encounter ends
            else
                attackPlayer(m, p); // Else Monster freely attacks Player
        }

    } while (!p.isDead()); // If Player dies, encounter with the Monster ends

    /*
    char answer{};
    do
    {
        std::cout << "Want to fight(f) or run(r)? ";
        std::cin >> answer;
        std::cin.ignore(32767, '\n');
    }
    while (answer != 'f' && answer != 'r');

    if (answer == 'f')          // Player chose to fight with the Monster
    {                           // Player attacks first, then Monster
        if(attackMonster(m, p)) // Check if Monster dies after Player's attack
            return;             // If Monster is dead, encounter ends
        if(attackPlayer(m, p))  // Check if Player dies after Monster's attack
            return;             // If Player is dead, encounter ends
        else
            fightMonster(m, p); // If Monster and Player are alive after their attacks
    }                           // encounter continues (recursion)

    if (answer == 'r') // Gives Player opportunity to flee from the Monster
    {
        if (fleeCheck()) // If escape is successful Player runs away from that encounter
            return;
        else             // If escape isn't successful Monster freely attacks Player
            if(attackPlayer(m, p))
                return;
            else
                fightMonster(m, p);
    }
    */
}

// Handles "play again" question
// Returns 1 if Player wants to play again
bool playAgain()
{
    cout << '\n';
    char answer{};
    while (true)
    {
        cout << "Do you want to play again (y/n)? ";
        cin >> answer;
        cin.ignore(32767, '\n');

        if (answer == 'y' || answer == 'n')
        {
            cout << "\n\n";
            return (answer == 'y');
        }
    }
}

// Main function that controls logic of the game
void playGame()
{
    do
    {
        // Get the name of the Player and roll out intro
        Player player{startGame()};

        // Handles all of the fights between Player and Monsters
        // until Player dies or reaches level 21
        while (true)
        {
            Monster monster{Monster::generateMonster()};
            fightMonster(monster, player);

            if (player.hasWon() || player.isDead())
                break;
        };

        // Results of the game
        if (player.hasWon())
            cout << "\n\nCongratulations, you have reached level "
                 << player.getLevel() << ".\nYou won the game with "
                 << player.getGold() << " gold in your pocket.\n";
        else
            cout << "\nYou have been defeated at level "
                 << player.getLevel() << " with "
                 << player.getGold() << " gold in your pocket.\n";

    } while (playAgain());
}
