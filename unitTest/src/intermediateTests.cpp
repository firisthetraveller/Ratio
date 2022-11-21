#include <gtest/gtest.h>

#include "Ratio.hpp"

// Types
// TODO : Ratio<unsigned int> , Ratio<float>

// Methods

TEST(Simplify, ToConstZero)
{
    Ratio<int> a(0, 3);

    EXPECT_EQ(a, Ratio<int>::ZERO);
}

TEST(Simplify, ToConstInfinity)
{
    Ratio<int> a(5, 0);

    EXPECT_EQ(a, Ratio<int>::INFINITY);
}

// Operators
TEST(IntermediateOperators, ScalarMultiplyA)
{
    Ratio<int> a(2, 5);
    Ratio<int> b = 5 * a;

    EXPECT_EQ(a, Ratio<int>(2, 1));
}

TEST(IntermediateOperators, ScalarMultiplyB)
{
    Ratio<int> a(2, 5);
    Ratio<int> b = a * 5;

    EXPECT_EQ(a, Ratio<int>(2, 1));
}

TEST(IntermediateOperators, DivisionByZero)
{
    Ratio<int> a(5, 6);
    Ratio<int> b = Ratio<int>::ZERO;

    Ratio<int> c = a / b;

    EXPECT_EQ(0, c.getDenominator());
    EXPECT_EQ(c.abs(), Ratio<int>::INFINITY);
}

// Operators with some letters
TEST(IntermediateMethodOperators, Power)
{
    Ratio<int> a(5, 2);
    Ratio<int> b = a.pow(5);

    EXPECT_EQ(32, b.getDenominator());
    EXPECT_EQ(5 * 25 * 25, b.getNumerator());
}

TEST(IntermediateMethodOperators, NegativePower)
{
    Ratio<int> a(5, 2);
    Ratio<int> b = a.pow(-1);
    Ratio<int> c = a.inv();

    EXPECT_EQ(b, c);
}

// Convert

TEST(Conversion, SimpleConversionInteger)
{
    Ratio<int> a = Ratio<int>::convertFromFloat(2.0f);

    EXPECT_EQ(2, a.getNumerator());
    EXPECT_EQ(1, a.getDenominator());
}

TEST(Conversion, SimpleConversionDecimal)
{
    Ratio<int> a = Ratio<int>::convertFromFloat(0.5f);

    EXPECT_EQ(1, a.getNumerator());
    EXPECT_EQ(2, a.getDenominator());
}

TEST(Conversion, ConversionDecimal)
{ // Not sure if this one works
    Ratio<int> a = Ratio<int>::convertFromFloat(0.33f);

    EXPECT_EQ(33, a.getNumerator());
    EXPECT_EQ(100, a.getDenominator());
}
