#include "Ratio.hpp"

#include <random>

template <class T>
class RatioGenerator
{
private:
    static const uint DEFAULT_MAX_VALUE = 20;
    const std::mt19937 generator(0);
    std::uniform_int_distribution<unsigned int> uniformPositiveIntDistribution;
    std::uniform_int_distribution<T> uniformIntDistribution;

public:
    RatioGenerator(const int maxValue = DEFAULT_MAX_VALUE);
    ~RatioGenerator();

    Ratio<T> get();
};

template <typename T>
RatioGenerator<T>::RatioGenerator(const int maxValue)
{
    uniformPositiveIntDistribution(1, maxValue);
    uniformIntDistribution(-maxValue, maxValue);
}

template <typename T>
Ratio<T> RatioGenerator<T>::get()
{
    return Ratio<T>(uniformIntDistribution(generator), uniformPositiveIntDistribution(generator));
}
