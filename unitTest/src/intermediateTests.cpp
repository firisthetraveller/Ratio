#include "Ratio.hpp"

#include <gtest/gtest.h>

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

    EXPECT_EQ(0, c.denominator);
    EXPECT_EQ(c.abs(), Ratio<int>::INFINITY);
}

// Operators with some letters
TEST(IntermediateMethodOperators, Power)
{
    Ratio<int> a(5, 2);
    Ratio<int> b = a.pow(5);

    EXPECT_EQ(32, b.denominator);
    EXPECT_EQ(5 * 25 * 25, b.numerator);
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
    Ratio<int> a = Ratio::convert_from_float(2.0f);

    EXPECT_EQ(2, a.numerator);
    EXPECT_EQ(1, a.denominator);
}

TEST(Conversion, SimpleConversionDecimal)
{
    Ratio<int> a = Ratio::convert_from_float(0.5f);

    EXPECT_EQ(1, a.numerator);
    EXPECT_EQ(2, a.denominator);
}

TEST(Conversion, ConversionDecimal)
{ // Not sure if this one works
    Ratio<int> a = Ratio::convert_from_float(0.33f);

    EXPECT_EQ(33, a.numerator);
    EXPECT_EQ(100, a.denominator);
}

// Value binding (operator =)
// Copy ? Or direct value binding ?
