#pragma once

#include <random>

class Random
{
public:
    // Initializes the random number generator (only needed once)
    static void init();

    // Returns a random integer in the range [min, max]
    static int getInt(int min, int max);

    // Returns a random floating-point number in the range [min, max]
    static float getFloat(float min, float max);

private:
    // Provides access to the singleton instance of Random
    static Random& instance();

    std::mt19937 randomEngine; // Mersenne Twister random number generator

    // Private constructor to prevent instantiation
    Random();
};
