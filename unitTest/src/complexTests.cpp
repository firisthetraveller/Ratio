#include <gtest/gtest.h>

#include "../../libRatio/include/Ratio.hpp"

// Disclaimer
// The following tests are by no means, as of November 17, 2022, complete.
// Passing all these tests does not guarantee a good behavior of the program.

// Conversions

TEST(Conversion, NegativeConversion)
{
    Ratio<int> a = Ratio<int>::convertFromFloat(-0.5f);

    EXPECT_EQ(-1, a.getNumerator());
    EXPECT_EQ(2, a.getDenominator());
}

// Methods

// TODO cos
TEST(ComplexOperators, BasicCosine)
{
    // cos(0) = 1
    Ratio<int> a = Ratio<int>::ZERO;
    Ratio<int> b = Ratio<int>::cos(a).simplify();

    EXPECT_EQ(1, b.getNumerator());
    EXPECT_EQ(1, b.getDenominator());
}

// TODO exp
TEST(ComplexOperators, BasicExponential)
{
    // exp(0) = 1
    Ratio<int> a = Ratio<int>::ZERO;
    Ratio<int> b = Ratio<int>::exp(a).simplify();

    EXPECT_EQ(1, b.getNumerator());
    EXPECT_EQ(1, b.getDenominator());
}

// TODO sqrt
TEST(ComplexOperators, BasicSquareRoot)
{
    // sqrt(1) = 1
    Ratio<int> a(1, 1);
    Ratio<int> b = Ratio<int>::exp(a).simplify();

    EXPECT_EQ(1, b.getNumerator());
    EXPECT_EQ(1, b.getDenominator());
}

TEST(ComplexOperators, NaturalSquareRoot)
{
    // Exact value with only getNumerator()
    Ratio<int> a = Ratio<int>::sqrt(Ratio<int>(49, 1));
    Ratio<int> b = Ratio<int>::sqrt(Ratio<int>(25, 1));
    Ratio<int> c = Ratio<int>::sqrt(Ratio<int>(121, 1));

    EXPECT_EQ(7, a.getNumerator());
    EXPECT_EQ(1, a.getDenominator());

    EXPECT_EQ(5, b.getNumerator());
    EXPECT_EQ(1, b.getDenominator());

    EXPECT_EQ(11, c.getNumerator());
    EXPECT_EQ(1, c.getDenominator());
}
