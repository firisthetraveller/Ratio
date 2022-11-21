#include <gtest/gtest.h>

#include "../../libRatio/include/Ratio.hpp"
#include "../../libRatio/include/RatioGenerator.hpp"

// Constant value tests

TEST(DefaultValues, Zero)
{
    EXPECT_EQ(0, Ratio<int>::ZERO.getNumerator());
    EXPECT_EQ(1, Ratio<int>::ZERO.getDenominator());
}

TEST(DefaultValues, Infinity)
{
    EXPECT_EQ(1, Ratio<int>::INFINITY.getNumerator());
    EXPECT_EQ(0, Ratio<int>::PLUS_INF.getDenominator());
}

// Type tests

TEST(TemplateType, Integer)
{
    RatioGenerator<int> gen = RatioGenerator<int>();
    Ratio<int> a = gen.get();

    EXPECT_TRUE(typeid(int) == typeid(a.getNumerator()));
}

TEST(TemplateType, LongInteger)
{
    RatioGenerator<long int> gen = RatioGenerator<long int>();
    Ratio<long int> a = gen.get();

    EXPECT_TRUE(typeid(long int) == typeid(a.getNumerator()));
}

TEST(TemplateType, NegativeDenominator)
{
    Ratio<int> a(1, -2);

    EXPECT_FALSE(a.getDenominator() < 0);
    EXPECT_EQ(-1, a.getNumerator());
    EXPECT_EQ(2, a.getDenominator());
}

TEST(TemplateType, SignCorrection)
{
    Ratio<int> a(-1, -2);

    EXPECT_FALSE(a.getDenominator() < 0);
    EXPECT_EQ(1, a.getNumerator());
    EXPECT_EQ(2, a.getDenominator());
}

// Constructor tests

TEST(Constructor, ClassicExplicit)
{
    Ratio<int> a(1, 2);

    EXPECT_EQ(1, a.getNumerator());
    EXPECT_EQ(2, a.getDenominator());
}

TEST(Constructor, Integer)
{
    Ratio<int> a(5); // integer

    EXPECT_EQ(5, a.getNumerator());
    EXPECT_EQ(1, a.getDenominator());
}

// Simplify tests

TEST(Simplify, Constructor)
{
    Ratio<int> a(2, 4);

    EXPECT_EQ(1, a.getNumerator());
    EXPECT_EQ(2, a.getDenominator());
}

// Operator tests

TEST(SimpleOperators, Addition)
{
    Ratio<int> a(1, 2);
    Ratio<int> b(1, 3);

    Ratio<int> c = a + b;

    EXPECT_EQ(5, c.getNumerator());
    EXPECT_EQ(6, c.getDenominator());
}

TEST(Simplify, Addition)
{
    Ratio<int> a(5, 6);
    Ratio<int> b(2, 3);

    Ratio<int> c = a + b;

    EXPECT_EQ(3, c.getNumerator());
    EXPECT_EQ(2, c.getDenominator());
}

TEST(SimpleOperators, AdditionBatch)
{
    RatioGenerator<int> gen = RatioGenerator<int>();
    Ratio<int> a[100], b[100], res[100];

    for (int i = 0; i < 100; i++)
    {
        a[i] = gen.get();
        b[i] = gen.get();
        // TODO res[i] = manually calculated ratio;
    }

    for (int i = 0; i < 100; i++)
    {
        Ratio<int> c = a[i] + b[i];
        EXPECT_EQ(c.getNumerator(), res[i].getNumerator());
        EXPECT_EQ(c.getDenominator(), res[i].getDenominator());
    }
}

TEST(SimpleOperators, Subtraction)
{
    Ratio<int> a(5, 6);
    Ratio<int> b(2, 3);

    Ratio<int> c = a - b;

    EXPECT_EQ(1, c.getNumerator());
    EXPECT_EQ(6, c.getDenominator());
}

TEST(SimpleOperators, SubtractionBatch)
{
    RatioGenerator<int> gen = RatioGenerator<int>();
    Ratio<int> a[100], b[100], res[100];

    for (int i = 0; i < 100; i++)
    {
        a[i] = gen.get();
        b[i] = gen.get();
        // TODO res[i] = manually calculated ratio;
    }

    for (int i = 0; i < 100; i++)
    {
        Ratio<int> c = a[i] - b[i];
        EXPECT_EQ(c.getNumerator(), res[i].getNumerator());
        EXPECT_EQ(c.getDenominator(), res[i].getDenominator());
    }
}

TEST(SimpleOperators, Multiply)
{
    Ratio<int> a(5, 6);
    Ratio<int> b(1, 3);

    Ratio<int> c = a * b;

    EXPECT_EQ(5, c.getNumerator());
    EXPECT_EQ(18, c.getDenominator());
}

TEST(Simplify, Multiply)
{
    Ratio<int> a(5, 6);
    Ratio<int> b(2, 3);

    Ratio<int> c = a * b;

    EXPECT_EQ(5, c.getNumerator());
    EXPECT_EQ(9, c.getDenominator()); // 10 / 18 -> 5 / 9
}

TEST(SimpleOperators, MultiplyBatch)
{
    RatioGenerator<int> gen = RatioGenerator<int>();
    Ratio<int> a[100], b[100], res[100];

    for (int i = 0; i < 100; i++)
    {
        a[i] = gen.get();
        b[i] = gen.get();
        // TODO res[i] = manually calculated ratio;
    }

    for (int i = 0; i < 100; i++)
    {
        Ratio<int> c = a[i] * b[i];
        EXPECT_EQ(c.getNumerator(), res[i].getNumerator());
        EXPECT_EQ(c.getDenominator(), res[i].getDenominator());
    }
}

TEST(SimpleOperators, Division)
{
    Ratio<int> a(5, 3);
    Ratio<int> b(7, 2);

    Ratio<int> c = a / b;

    EXPECT_EQ(10, c.getNumerator());
    EXPECT_EQ(21, c.getDenominator());
}

TEST(Simplify, Division)
{
    Ratio<int> a(5, 6);
    Ratio<int> b(2, 3);

    Ratio<int> c = a / b;

    EXPECT_EQ(5, c.getNumerator());
    EXPECT_EQ(4, c.getDenominator());
}

TEST(SimpleOperators, DivideBatch)
{
    RatioGenerator<int> gen = RatioGenerator<int>();
    Ratio<int> a[100], b[100], res[100];

    for (int i = 0; i < 100; i++)
    {
        a[i] = gen.get();
        b[i] = gen.get();
        // TODO res[i] = manually calculated ratio;
    }

    for (int i = 0; i < 100; i++)
    {
        Ratio<int> c = a[i] / b[i];
        EXPECT_EQ(c.getNumerator(), res[i].getNumerator());
        EXPECT_EQ(c.getDenominator(), res[i].getDenominator());
    }
}

TEST(StandardOperators, Absolute)
{
    Ratio<int> a(-5, 1);
    a = a.abs();

    EXPECT_EQ(5, a.getNumerator());
    EXPECT_EQ(1, a.getDenominator());
}

TEST(SimpleOperators, UnaryMinus)
{
    Ratio<int> a(2, 3);
    Ratio<int> b = -a;

    EXPECT_EQ(-2, b.getNumerator());
    EXPECT_EQ(3, b.getDenominator());
}

TEST(StandardOperators, Truncate)
{
    Ratio<int> a(2, 3);
    Ratio<int> b = a.truncate();

    EXPECT_EQ(0, b.getNumerator());
    EXPECT_EQ(1, b.getDenominator());
}

TEST(StandardOperators, RoundUpper)
{
    Ratio<int> a(2, 3);
    Ratio<int> b = a.round();

    EXPECT_EQ(1, b.getNumerator());
    EXPECT_EQ(1, b.getDenominator());
}

TEST(StandardOperators, RoundLower)
{
    Ratio<int> a(1, 3);
    Ratio<int> b = a.round();

    EXPECT_EQ(0, a.getNumerator());
    EXPECT_EQ(1, b.getDenominator());
}

TEST(StandardOperators, Inverse)
{
    Ratio<int> a(1, 3);
    Ratio<int> b = a.inv();

    EXPECT_EQ(b.getDenominator(), a.getNumerator());
    EXPECT_EQ(a.getDenominator(), b.getNumerator());
}

TEST(StandardOperators, NegativeInverse)
{
    Ratio<int> a(-1, 3);
    Ratio<int> b = a.inv();

    EXPECT_EQ(-b.getDenominator(), a.getNumerator());
    EXPECT_EQ(a.getDenominator(), b.getNumerator());
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

// Methods

// TODO Check for a private method simplify.
// TODO Check from "outside" that simplify is not usable.
