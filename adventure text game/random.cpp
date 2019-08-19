#include "random.hpp"
#include <random>
#include <ctime>

// Namespace for random number generator
namespace MyRandom
{
    // Initialize our Mersenne twister with a random seed based on the clock
    std::mt19937 mersenne(static_cast<std::mt19937::result_type>(std::time(nullptr)));
}

// Random number generator using Mersenne Twister algorithm
int getRandom(int min, int max)
{
    std::uniform_int_distribution<> random(min, max);
    return random(MyRandom::mersenne);
}
