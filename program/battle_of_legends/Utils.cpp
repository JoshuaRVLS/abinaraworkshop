#include "Utils.hpp"

double utils::generateNumber(int lowerBound, int higherBound) {
    std::default_random_engine randomEngine(std::chrono::system_clock::now().time_since_epoch().count());
    std::uniform_real_distribution<double> generateNumber(lowerBound, higherBound);
    return generateNumber(randomEngine);
}