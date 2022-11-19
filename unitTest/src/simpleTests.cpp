#include "Ratio.hpp"

#include <gtest/gtest.h>

// Constant value tests

TEST(DefaultValues, Zero)
{
    EXPECT_EQ(0, Ratio<int>::ZERO.numerator);
    EXPECT_EQ(1, Ratio<int>::ZERO.denominator);
}

TEST(DefaultValues, Infinity)
{
    EXPECT_EQ(1, Ratio<int>::INFINITY.numerator);
    EXPECT_EQ(0, Ratio<int>::PLUS_INF.denominator);
}

// bool testInfPlus () {
//     return Ratio::PLUS_INF.numerator == 1 && Ratio::PLUS_INF.denominator == 0;
// }

// bool testInfPlus () {
//     return Ratio::MINUS_INF.numerator == -1 && Ratio::MINUS_INF.denominator == 0;
// }

// Type tests

TEST(TemplateType, Integer)
{
    Ratio<int> a(1, 2);

    EXPECT_TRUE(typeid(int) == typeid(a.numerator));
}

TEST(TemplateType, LongInteger)
{
    Ratio<long int> a(1, 2);

    EXPECT_TRUE(typeid(long int) == typeid(a.numerator));
}

TEST(TemplateType, NegativeDenominator)
{
    Ratio<int> a(1, -2);

    EXPECT_FALSE(a.denominator < 0);
    EXPECT_EQ(-1, a.numerator);
    EXPECT_EQ(2, a.denominator);
}

TEST(TemplateType, SignCorrection)
{
    Ratio<int> a(-1, -2);

    EXPECT_FALSE(a.denominator < 0);
    EXPECT_EQ(1, a.numerator);
    EXPECT_EQ(2, a.denominator);
}

// Simplify tests

TEST(Simplify, Constructor)
{
    Ratio<int> a(2, 4);

    EXPECT_EQ(1, a.numerator);
    EXPECT_EQ(2, a.denominator);
}

// Operator tests

TEST(SimpleOperators, Addition)
{
    Ratio<int> a(1, 2);
    Ratio<int> b(1, 3);

    Ratio<int> c = a + b;

    EXPECT_EQ(5, c.numerator);
    EXPECT_EQ(6, c.denominator);
}

TEST(Simplify, Addition)
{
    Ratio<int> a(5, 6);
    Ratio<int> b(2, 3);

    Ratio<int> c = a + b;

    EXPECT_EQ(3, c.numerator);
    EXPECT_EQ(2, c.denominator);
}

TEST(SimpleOperators, Subtraction)
{
    Ratio<int> a(5, 6);
    Ratio<int> b(2, 3);

    Ratio<int> c = a - b;

    EXPECT_EQ(1, c.numerator)
    EXPECT_EQ(6, c.denominator);
}

// TEST(Simplify, Subtraction) {
//     Ratio<int> a (1, 1);
//     Ratio<int> b (1, 2);

//     Ratio<int> c = a + b;

//     EXPECT_EQ(3, c.numerator);
//     EXPECT_EQ(2, c.denominator);
// }

TEST(SimpleOperators, Multiply)
{
    Ratio<int> a(5, 6);
    Ratio<int> b(1, 3);

    Ratio<int> c = a * b;

    EXPECT_EQ(5, c.numerator);
    EXPECT_EQ(18, c.denominator);
}

TEST(Simplify, Multiply)
{
    Ratio<int> a(5, 6);
    Ratio<int> b(2, 3);

    Ratio<int> c = a * b;

    EXPECT_EQ(5, c.numerator);
    EXPECT_EQ(9, c.denominator); // 10 / 18 -> 5 / 9
}

TEST(SimpleOperators, Division)
{
    Ratio<int> a(5, 3);
    Ratio<int> b(7, 2);

    Ratio<int> c = a / b;

    EXPECT_EQ(10, c.numerator);
    EXPECT_EQ(21, c.denominator);
}

TEST(Simplify, Division)
{
    Ratio<int> a(5, 6);
    Ratio<int> b(2, 3);

    Ratio<int> c = a / b;

    EXPECT_EQ(5, c.numerator);
    EXPECT_EQ(4, c.denominator);
}

TEST(StandardOperators, Absolute)
{
    Ratio<int> a(-5, 1);
    a = a.abs();

    EXPECT_EQ(5, a.numerator);
    EXPECT_EQ(1, a.denominator);
}

TEST(SimpleOperators, UnaryMinus)
{
    Ratio<int> a(2, 3);
    Ratio<int> b = -a;

    EXPECT_EQ(-2, b.numerator);
    EXPECT_EQ(3, b.denominator);
}

TEST(StandardOperators, Truncate)
{
    Ratio<int> a(2, 3);
    Ratio<int> b = a.truncate();

    EXPECT_EQ(0, b.numerator);
    EXPECT_EQ(1, b.denominator);
}

TEST(StandardOperators, RoundUpper)
{
    Ratio<int> a(2, 3);
    Ratio<int> b = a.round();

    EXPECT_EQ(1, b.numerator);
    EXPECT_EQ(1, b.denominator);
}

TEST(StandardOperators, RoundLower)
{
    Ratio<int> a(1, 3);
    Ratio<int> b = a.round();

    EXPECT_EQ(0, a.numerator);
    EXPECT_EQ(1, b.denominator);
}

TEST(StandardOperators, Inverse)
{
    Ratio<int> a(1, 3);
    Ratio<int> b = a.inv();

    EXPECT_EQ(b.denominator, a.numerator);
    EXPECT_EQ(a.denominator, b.numerator);
}

TEST(StandardOperators, NegativeInverse)
{
    Ratio<int> a(-1, 3);
    Ratio<int> b = a.inv();

    EXPECT_EQ(-b.denominator, a.numerator);
    EXPECT_EQ(a.denominator, b.numerator);
}

// Comparison tests

TEST(ComparisonOperators, LowerWhenTrue)
{
    Ratio<int> a(3, 5);
    Ratio<int> b(6, 7);

    EXPECT_TRUE(a < b);
}

TEST(ComparisonOperators, LowerWhenFalse)
{
    Ratio<int> a(3, 5);
    Ratio<int> b(6, 7);

    EXPECT_FALSE(b < a);
}

TEST(ComparisonOperators, LowerEqualWhenEqualA)
{
    Ratio<int> a(3, 5);
    Ratio<int> b(6, 10);

    EXPECT_TRUE(a <= b);
}

TEST(ComparisonOperators, LowerEqualWhenEqualB)
{
    Ratio<int> a(3, 5);
    Ratio<int> b(6, 10);

    EXPECT_TRUE(b <= a);
}

TEST(ComparisonOperators, LowerEqualWhenTrue)
{
    Ratio<int> a(4, 5);
    Ratio<int> b(3, 5);

    EXPECT_TRUE(b <= a);
}

TEST(ComparisonOperators, LowerEqualWhenFalse)
{
    Ratio<int> a(4, 5);
    Ratio<int> b(3, 5);

    EXPECT_FALSE(a <= b);
}

TEST(ComparisonOperators, EqualWhenFalse)
{
    Ratio<int> a(4, 5);
    Ratio<int> b(3, 5);

    EXPECT_FALSE(a == b);
}

TEST(ComparisonOperators, EqualWhenTrue)
{
    Ratio<int> a(4, 5);
    Ratio<int> b(8, 10);

    EXPECT_TRUE(a == b);
}

TEST(ComparisonOperators, GreaterWhenFalse)
{
    Ratio<int> a(3, 5);
    Ratio<int> b(6, 7);

    EXPECT_FALSE(a > b);
}

TEST(ComparisonOperators, GreaterWhenTrue)
{
    Ratio<int> a(3, 5);
    Ratio<int> b(6, 7);

    EXPECT_TRUE(b > a);
}

TEST(ComparisonOperators, GreaterEqualWhenEqualA)
{
    Ratio<int> a(3, 5);
    Ratio<int> b(6, 10);

    EXPECT_TRUE(a >= b);
}

TEST(ComparisonOperators, GreaterEqualWhenEqualB)
{
    Ratio<int> a(3, 5);
    Ratio<int> b(6, 10);

    EXPECT_TRUE(b >= a);
}

TEST(ComparisonOperators, GreaterEqualWhenFalse)
{
    Ratio<int> a(4, 5);
    Ratio<int> b(3, 5);

    EXPECT_FALSE(b >= a);
}

TEST(ComparisonOperators, GreaterEqualWhenTrue)
{
    Ratio<int> a(4, 5);
    Ratio<int> b(3, 5);

    EXPECT_TRUE(a >= b);
}

// Exception tests
// TODO

// Constructor tests

TEST(Constructor, ClassicExplicit)
{
    Ratio<int> a(1, 2);

    EXPECT_EQ(1, a.numerator);
    EXPECT_EQ(2, a.denominator);
}

TEST(Constructor, Integer)
{
    Ratio<int> a(5); // integer

    EXPECT_EQ(5, a.numerator);
    EXPECT_EQ(1, a.denominator);
}

// Methods

// TODO Check for a private method simplify.
// TODO Check from "outside" that simplify is not usable.
