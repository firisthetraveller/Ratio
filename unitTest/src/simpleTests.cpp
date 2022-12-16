#include <gtest/gtest.h>
#include <random>
#include <vector>

#include "../../libRatio/include/Ratio.hpp"

// Constant value tests

const uint DEFAULT_MAX_VALUE = 20;

TEST(DefaultValues, Zero)
{
    EXPECT_EQ(0, Ratio<int>::ZERO().getNumerator());
    EXPECT_EQ(1, Ratio<int>::ZERO().getDenominator());
}

TEST(DefaultValues, Infinity)
{
    EXPECT_EQ(1, Ratio<int>::PLUS_INF().getNumerator());
    EXPECT_EQ(0, Ratio<int>::PLUS_INF().getDenominator());
}

TEST(DefaultValues, NegativeInfinity)
{
    EXPECT_EQ(-1, Ratio<int>::MINUS_INF().getNumerator());
    EXPECT_EQ(0, Ratio<int>::MINUS_INF().getDenominator());
}

// // Type tests

// TEST(TemplateType, Integer)
// {
//     Ratio<int> a(1, 2);

//     EXPECT_TRUE(typeid(int) == typeid(a.getNumerator()));
// }

// TEST(TemplateType, LongInteger)
// {
//     Ratio<long int> a = Ratio<long int>(3, 5);

//     EXPECT_TRUE(typeid(long int) == typeid(a.getNumerator()));
// }

// TEST(TemplateType, NegativeDenominator)
// {
//     Ratio<int> a(1, -2);

//     EXPECT_FALSE(a.getDenominator() < 0);
//     EXPECT_EQ(-1, a.getNumerator());
//     EXPECT_EQ(2, a.getDenominator());
// }

// TEST(TemplateType, SignCorrection)
// {
//     Ratio<int> a(-1, -2);

//     EXPECT_FALSE(a.getDenominator() < 0);
//     EXPECT_EQ(1, a.getNumerator());
//     EXPECT_EQ(2, a.getDenominator());
// }

// // Constructor tests

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

// // Operator tests

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

// // TEST(SimpleOperators, AdditionBatch)
// // {
// //     std::default_random_engine generator(0);
// //     std::uniform_int_distribution<int> uniformPositiveIntDistribution(1,
// DEFAULT_MAX_VALUE);
// //     std::uniform_int_distribution<int>
// uniformIntDistribution(-DEFAULT_MAX_VALUE, DEFAULT_MAX_VALUE);
// //     std::vector<Ratio<int>> a(100), b(100);
// //     auto gen = [&uniformIntDistribution, &uniformPositiveIntDistribution,
// &generator]()
// //     { return Ratio<int>(uniformIntDistribution(generator),
// uniformPositiveIntDistribution(generator)); };

// //     std::generate(a.begin(), a.end(), gen);
// //     std::generate(b.begin(), b.end(), gen);

// //     for (int i = 0; i < 100; i++)
// //     {
// //         Ratio<int> res = a[i] + b[i];
// //         double c = a[i].eval() + b[i].eval();
// //         EXPECT_NEAR(c, res.eval(), 10e-7);
// //         EXPECT_EQ(Ratio<int>::convertFromFloat(c), res);
// //     }
// // }

TEST(SimpleOperators, Subtraction)
{
    Ratio<int> a(5, 6);
    Ratio<int> b(2, 3);

    Ratio<int> c = a - b;

    EXPECT_EQ(1, c.getNumerator());
    EXPECT_EQ(6, c.getDenominator());
}

// // TEST(SimpleOperators, SubtractionBatch)
// // {
// //     const std::mt19937 generator = std::mt19937(0);
// //     std::uniform_int_distribution<int> uniformPositiveIntDistribution(1,
// DEFAULT_MAX_VALUE);
// //     std::uniform_int_distribution<int>
// uniformIntDistribution(-DEFAULT_MAX_VALUE, DEFAULT_MAX_VALUE);
// //     std::vector<Ratio<int>> a(100), b(100), res(100);
// //     auto gen = [&uniformIntDistribution, &uniformPositiveIntDistribution,
// &generator]()
// //     { return Ratio<int>(uniformIntDistribution(generator),
// uniformPositiveIntDistribution(generator)); };

// //     std::generate(a.begin(), a.end(), gen);
// //     std::generate(b.begin(), b.end(), gen);

// //     for (int i = 0; i < 100; i++)
// //     {
// //         Ratio<int> c = a[i] - b[i];
// //         EXPECT_EQ(c.getNumerator(), res[i].getNumerator());
// //         EXPECT_EQ(c.getDenominator(), res[i].getDenominator());
// //     }
// // }

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

TEST(Simplify, MultiplyScalar)
{
    Ratio<int> a(5, 6);
    double b(3.0);

    Ratio<int> c = a * b;

    EXPECT_EQ(5, c.getNumerator());
    EXPECT_EQ(2, c.getDenominator());
}

// // TEST(SimpleOperators, MultiplyBatch)
// // {
// //     const std::mt19937 generator = std::mt19937(0);
// //     std::uniform_int_distribution<int> uniformPositiveIntDistribution(1,
// DEFAULT_MAX_VALUE);
// //     std::uniform_int_distribution<int>
// uniformIntDistribution(-DEFAULT_MAX_VALUE, DEFAULT_MAX_VALUE);
// //     std::vector<Ratio<int>> a(100), b(100), res(100);
// //     auto gen = [&uniformIntDistribution, &uniformPositiveIntDistribution,
// &generator]()
// //     { return Ratio<int>(uniformIntDistribution(generator),
// uniformPositiveIntDistribution(generator)); };

// //     std::generate(a.begin(), a.end(), gen);
// //     std::generate(b.begin(), b.end(), gen);

// //     for (int i = 0; i < 100; i++)
// //     {
// //         Ratio<int> c = a[i] * b[i];
// //         EXPECT_EQ(c.getNumerator(), res[i].getNumerator());
// //         EXPECT_EQ(c.getDenominator(), res[i].getDenominator());
// //     }
// // }

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

// // TEST(SimpleOperators, DivideBatch)
// // {
// //     RatioGenerator<int> gen = RatioGenerator<int>();
// //     Ratio<int> a[100], b[100], res[100];

// //     for (int i = 0; i < 100; i++)
// //     {
// //         a[i] = gen.get();
// //         b[i] = gen.get();
// //         // TODO res[i] = manually calculated ratio;
// //     }

// //     for (int i = 0; i < 100; i++)
// //     {
// //         Ratio<int> c = a[i] / b[i];
// //         EXPECT_EQ(c.getNumerator(), res[i].getNumerator());
// //         EXPECT_EQ(c.getDenominator(), res[i].getDenominator());
// //     }
// // }

// TEST(StandardOperators, Absolute)
// {
//     Ratio<int> a(-5, 1);
//     a = a.abs();

//     EXPECT_EQ(5, a.getNumerator());
//     EXPECT_EQ(1, a.getDenominator());
// }

TEST(SimpleOperators, UnaryMinus)
{
    Ratio<int> a(2, 3);
    Ratio<int> b = -a;

    EXPECT_EQ(-2, b.getNumerator());
    EXPECT_EQ(3, b.getDenominator());
}

// TEST(StandardOperators, Truncate)
// {
//     Ratio<int> a(2, 3);
//     Ratio<int> b = a.truncate();

//     EXPECT_EQ(0, b.getNumerator());
//     EXPECT_EQ(1, b.getDenominator());
// }

// TEST(StandardOperators, RoundUpper)
// {
//     Ratio<int> a(2, 3);
//     Ratio<int> b = a.round();

//     EXPECT_EQ(1, b.getNumerator());
//     EXPECT_EQ(1, b.getDenominator());
// }

// TEST(StandardOperators, RoundLower)
// {
//     Ratio<int> a(1, 3);
//     Ratio<int> b = a.round();

//     EXPECT_EQ(0, a.getNumerator());
//     EXPECT_EQ(1, b.getDenominator());
// }

// TEST(StandardOperators, Inverse)
// {
//     Ratio<int> a(1, 3);
//     Ratio<int> b = a.inv();

//     EXPECT_EQ(b.getDenominator(), a.getNumerator());
//     EXPECT_EQ(a.getDenominator(), b.getNumerator());
// }

// TEST(StandardOperators, NegativeInverse)
// {
//     Ratio<int> a(-1, 3);
//     Ratio<int> b = a.inv();

//     EXPECT_EQ(-b.getDenominator(), a.getNumerator());
//     EXPECT_EQ(a.getDenominator(), -b.getNumerator());
// }

// // // Comparison tests

TEST(ComparisonOperators, LowerWhenTrue)
{
    Ratio<int> a(3, 5);
    Ratio<int> b(6, 7);

    EXPECT_TRUE(a < b);
    EXPECT_TRUE(Ratio<int>(1, 5) < Ratio<int>(3, 2));
    EXPECT_TRUE(Ratio<int>(1, 2) < Ratio<int>(9, 6));
    EXPECT_TRUE(Ratio<int>(2) < Ratio<int>(5));
    EXPECT_TRUE(Ratio<int>(2) < Ratio<int>(5, 2));
}

TEST(ComparisonOperators, LowerWhenFalse)
{
    Ratio<int> a(3, 5);
    Ratio<int> b(6, 7);

    EXPECT_FALSE(b < a);
}

// TEST(ComparisonOperators, LowerEqualWhenEqualA)
// {
//     Ratio<int> a(3, 5);
//     Ratio<int> b(6, 10);

//     EXPECT_TRUE(a <= b);
// }

// TEST(ComparisonOperators, LowerEqualWhenEqualB)
// {
//     Ratio<int> a(3, 5);
//     Ratio<int> b(6, 10);

//     EXPECT_TRUE(b <= a);
// }

TEST(ComparisonOperators, LowerEqualWhenTrue)
{
    Ratio<int> a(4, 5);
    Ratio<int> b(3, 5);

    EXPECT_TRUE(b <= a);
    EXPECT_TRUE(Ratio<int>(1, 5) <= Ratio<int>(3, 2));
    EXPECT_TRUE(Ratio<int>(1, 2) <= Ratio<int>(9, 6));
    EXPECT_TRUE(Ratio<int>(2) <= Ratio<int>(5));
    EXPECT_TRUE(Ratio<int>(2) <= Ratio<int>(5, 2));
}

TEST(ComparisonOperators, LowerEqualWhenFalse)
{
    Ratio<int> a(4, 5);
    Ratio<int> b(3, 5);

    EXPECT_FALSE(a <= b);
    EXPECT_FALSE(Ratio<int>(3, 2) <= Ratio<int>(1, 5));
    EXPECT_FALSE(Ratio<int>(9, 6) <= Ratio<int>(1, 2));
    EXPECT_FALSE(Ratio<int>(5) <= Ratio<int>(2));
    EXPECT_FALSE(Ratio<int>(5, 2) <= Ratio<int>(2));
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

// TEST(ComparisonOperators, EqualWhenTrueB) {
//   Ratio<int> a(10, 7);
//   Ratio<int> b(4, 7);

//   EXPECT_EQ(a + b, 2);
// }

/*TEST(ComparisonOperators, EqualIntTrue)
{
    Ratio<int> a(4);

    EXPECT_TRUE(a == 4);
    EXPECT_TRUE(4 == a);
    EXPECT_EQ(4, a);
    EXPECT_EQ(a, 4);
}*/

// TEST(ComparisonOperators, EqualIntFalse)
// {
//     Ratio<int> a(5);

//     EXPECT_NE(a, 4);
//     EXPECT_NE(4, a);
// }

TEST(ComparisonOperators, GreaterWhenFalse)
{
    Ratio<int> a(3, 5);
    Ratio<int> b(6, 7);

    EXPECT_FALSE(a > b);
    EXPECT_FALSE(Ratio<int>(1, 5) > Ratio<int>(3, 2));
    EXPECT_FALSE(Ratio<int>(1, 2) > Ratio<int>(9, 6));
    EXPECT_FALSE(Ratio<int>(2) > Ratio<int>(5));
    EXPECT_FALSE(Ratio<int>(2) > Ratio<int>(5, 2));
}

TEST(ComparisonOperators, GreaterWhenTrue)
{
    Ratio<int> a(3, 5);
    Ratio<int> b(6, 7);

    EXPECT_TRUE(b > a);
    EXPECT_TRUE(Ratio<int>(3, 2) > Ratio<int>(1, 5));
    EXPECT_TRUE(Ratio<int>(9, 6) > Ratio<int>(1, 2));
    EXPECT_TRUE(Ratio<int>(5) > Ratio<int>(2));
    EXPECT_TRUE(Ratio<int>(5, 2) > Ratio<int>(2));
}

// TEST(ComparisonOperators, GreaterEqualWhenEqualA)
// {
//     Ratio<int> a(3, 5);
//     Ratio<int> b(6, 10);

//     EXPECT_TRUE(a >= b);
// }

// TEST(ComparisonOperators, GreaterEqualWhenEqualB)
// {
//     Ratio<int> a(3, 5);
//     Ratio<int> b(6, 10);

//     EXPECT_TRUE(b >= a);
// }

TEST(ComparisonOperators, GreaterEqualWhenFalse)
{
    Ratio<int> a(4, 5);
    Ratio<int> b(3, 5);

    EXPECT_FALSE(b >= a);
    EXPECT_FALSE(Ratio<int>(1, 5) >= Ratio<int>(3, 2));
    EXPECT_FALSE(Ratio<int>(1, 2) >= Ratio<int>(9, 6));
    EXPECT_FALSE(Ratio<int>(2) >= Ratio<int>(5));
    EXPECT_FALSE(Ratio<int>(2) >= Ratio<int>(5, 2));
}

TEST(ComparisonOperators, GreaterEqualWhenTrue)
{
    Ratio<int> a(4, 5);
    Ratio<int> b(3, 5);

    EXPECT_TRUE(a >= b);
    EXPECT_TRUE(Ratio<int>(3, 2) >= Ratio<int>(1, 5));
    EXPECT_TRUE(Ratio<int>(9, 6) >= Ratio<int>(1, 2));
    EXPECT_TRUE(Ratio<int>(5) >= Ratio<int>(2));
    EXPECT_TRUE(Ratio<int>(5, 2) >= Ratio<int>(2));
}

// // Exception tests

// // Methods
