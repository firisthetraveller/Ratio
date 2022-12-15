#include <gtest/gtest.h>

#include "../../libRatio/include/Ratio.hpp"

// Disclaimer
// The following tests are by no means, as of November 17, 2022, complete.
// Passing all these tests does not guarantee a good behavior of the program.

// Conversions

TEST(Conversion, NegativeConversionA)
{
    Ratio<int> a = Ratio<int>::convertFromFloat(-0.5f);

    EXPECT_EQ(-1, a.getNumerator());
    EXPECT_EQ(2, a.getDenominator());
}

TEST(Conversion, NegativeConversionB)
{
    Ratio<int> a = Ratio<int>::convertFromFloat(-5.0);

    EXPECT_EQ(-5, a.getNumerator());
    EXPECT_EQ(1, a.getDenominator());
}

// Methods

// // TODO cos
TEST(ComplexOperators, BasicCosine0)
{
    // cos(0) = 1
    Ratio<int> a = Ratio<int>::ZERO();
    Ratio<int> b = a.cos();

    EXPECT_EQ(1, b.getNumerator());
    EXPECT_EQ(1, b.getDenominator());
}

TEST(ComplexOperators, BasicCosineHalfPi)
{
    // cos(0) = 1
    Ratio<int> a = Ratio<int>::convertFromFloat(M_1_PI / 2);
    Ratio<int> b = a.cos();

    EXPECT_EQ(0, b.getNumerator());
    EXPECT_EQ(1, b.getDenominator());
}

TEST(ComplexOperators, BasicCosineMinusPi)
{
    // cos(0) = 1
    Ratio<int> a = Ratio<int>::convertFromFloat(-M_1_PI);
    Ratio<int> b = a.cos();

    EXPECT_EQ(-1, b.getNumerator());
    EXPECT_EQ(1, b.getDenominator());
}

// TODO exp
TEST(ComplexOperators, BasicExponential)
{
    // exp(0) = 1
    Ratio<int> a = Ratio<int>::ZERO();
    Ratio<int> b = a.exp();

    EXPECT_EQ(1, b.getNumerator());
    EXPECT_EQ(1, b.getDenominator());
}

// TODO sqrt
TEST(ComplexOperators, BasicSquareRoot)
{
    // sqrt(1) = 1
    Ratio<int> a(1, 1);
    Ratio<int> b = a.exp();

    EXPECT_EQ(1, b.getNumerator());
    EXPECT_EQ(1, b.getDenominator());
}

TEST(ComplexOperators, NaturalSquareRoot)
{
    // Exact value with only getNumerator()
    Ratio<int> a = Ratio<int>(49, 1).sqrt();
    Ratio<int> b = Ratio<int>(25, 1).sqrt();
    Ratio<int> c = Ratio<int>(121, 1).sqrt();

    EXPECT_EQ(7, a.getNumerator());
    EXPECT_EQ(1, a.getDenominator());

    EXPECT_EQ(5, b.getNumerator());
    EXPECT_EQ(1, b.getDenominator());

    EXPECT_EQ(11, c.getNumerator());
    EXPECT_EQ(1, c.getDenominator());
}
