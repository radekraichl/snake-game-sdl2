#include "Random.h"

// Returns a reference to the singleton instance
Random& Random::instance()
{
    static Random randomInstance;
    return randomInstance;
}

// Initializes the random number generator with a hardware-based seed
void Random::init()
{
    instance().randomEngine.seed(std::random_device {}());
}

// Returns a random integer in the range [min, max]
int Random::getInt(int min, int max)
{
    std::uniform_int_distribution<int> dist(min, max);
    return dist(instance().randomEngine);
}

// Returns a random floating-point number in the range [min, max]
float Random::getFloat(float min, float max)
{
    std::uniform_real_distribution<float> dist(min, max);
    return dist(instance().randomEngine);
}

// Private constructor: Seeds the random engine upon first use
Random::Random()
{
    randomEngine.seed(std::random_device {}());
}
