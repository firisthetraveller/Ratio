#include <gtest/gtest.h>
#include <iostream>
#include <random>
#include <vector>

#include <Ratio.hpp>

// Constant value tests

// const uint DEFAULT_MAX_VALUE = 20;

TEST(DefaultValues, Zero) {
  EXPECT_EQ(0, Ratio<int>::ZERO().getNumerator());
  EXPECT_EQ(1, Ratio<int>::ZERO().getDenominator());
}

TEST(DefaultValues, Infinity) {
  EXPECT_EQ(1, Ratio<int>::PLUS_INF().getNumerator());
  EXPECT_EQ(0, Ratio<int>::PLUS_INF().getDenominator());
}

TEST(DefaultValues, NegativeInfinity) {
  EXPECT_EQ(-1, Ratio<int>::MINUS_INF().getNumerator());
  EXPECT_EQ(0, Ratio<int>::MINUS_INF().getDenominator());
}

// // Type tests

TEST(TemplateType, Integer) {
  Ratio<int> a(1, 2);

  EXPECT_TRUE(typeid(int) == typeid(a.getNumerator()));
}

TEST(TemplateType, LongInteger) {
  Ratio<long int> a = Ratio<long int>(3, 5);

  EXPECT_TRUE(typeid(long int) == typeid(a.getNumerator()));
}

TEST(TemplateType, NegativeDenominator) {
  Ratio<int> a(1, -2);

  EXPECT_FALSE(a.getDenominator() < 0);
  EXPECT_EQ(-1, a.getNumerator());
  EXPECT_EQ(2, a.getDenominator());
}

TEST(TemplateType, SignCorrection) {
  Ratio<int> a(-1, -2);

  EXPECT_FALSE(a.getDenominator() < 0);
  EXPECT_EQ(1, a.getNumerator());
  EXPECT_EQ(2, a.getDenominator());
}

// // Constructor tests

TEST(Constructor, ClassicExplicit) {
  Ratio<int> a(1, 2);

  EXPECT_EQ(1, a.getNumerator());
  EXPECT_EQ(2, a.getDenominator());
}

TEST(Constructor, Integer) {
  Ratio<int> a(5); // integer

  EXPECT_EQ(5, a.getNumerator());
  EXPECT_EQ(1, a.getDenominator());
}

// Simplify tests

TEST(Simplify, Constructor) {
  Ratio<int> a(2, 4);

  EXPECT_EQ(1, a.getNumerator());
  EXPECT_EQ(2, a.getDenominator());
}

// // Operator tests

TEST(SimpleOperators, Addition) {
  Ratio<int> a(1, 2);
  Ratio<int> b(1, 3);

  Ratio<int> c = a + b;

  EXPECT_EQ(5, c.getNumerator());
  EXPECT_EQ(6, c.getDenominator());
}

TEST(Simplify, Addition) {
  Ratio<int> a(5, 6);
  Ratio<int> b(2, 3);

  Ratio<int> c = a + b;

  EXPECT_EQ(3, c.getNumerator());
  EXPECT_EQ(2, c.getDenominator());
}

TEST(SimpleOperators, Subtraction) {
  Ratio<int> a(5, 6);
  Ratio<int> b(2, 3);

  Ratio<int> c = a - b;

  EXPECT_EQ(1, c.getNumerator());
  EXPECT_EQ(6, c.getDenominator());
}

TEST(Simplify, Subtraction) {
  Ratio<int> a(5, 6);
  Ratio<int> b(1, 3);

  Ratio<int> c = a - b;

  EXPECT_EQ(1, c.getNumerator());
  EXPECT_EQ(2, c.getDenominator());
}

TEST(SimpleOperators, Multiply) {
  Ratio<int> a(5, 6);
  Ratio<int> b(1, 3);

  Ratio<int> c = a * b;

  EXPECT_EQ(5, c.getNumerator());
  EXPECT_EQ(18, c.getDenominator());
}

TEST(Simplify, Multiply) {
  Ratio<int> a(5, 6);
  Ratio<int> b(2, 3);

  Ratio<int> c = a * b;

  EXPECT_EQ(5, c.getNumerator());
  EXPECT_EQ(9, c.getDenominator()); // 10 / 18 -> 5 / 9
}

TEST(Simplify, MultiplyScalar) {
  Ratio<int> a(5, 6);
  double b(3.0);

  Ratio<int> c = a * b;

  EXPECT_EQ(5, c.getNumerator());
  EXPECT_EQ(2, c.getDenominator());
}

TEST(SimpleOperators, Division) {
  Ratio<int> a(5, 3);
  Ratio<int> b(7, 2);

  Ratio<int> c = a / b;

  EXPECT_EQ(10, c.getNumerator());
  EXPECT_EQ(21, c.getDenominator());
}

TEST(Simplify, Division) {
  Ratio<int> a(5, 6);
  Ratio<int> b(2, 3);

  Ratio<int> c = a / b;

  EXPECT_EQ(5, c.getNumerator());
  EXPECT_EQ(4, c.getDenominator());
}

TEST(StandardOperators, Absolute) {
  Ratio<int> a(-5, 1);
  a = a.abs();

  EXPECT_EQ(5, a.getNumerator());
  EXPECT_EQ(1, a.getDenominator());
}

TEST(SimpleOperators, UnaryMinus) {
  Ratio<int> a(2, 3);
  Ratio<int> b = -a;

  EXPECT_EQ(-2, b.getNumerator());
  EXPECT_EQ(3, b.getDenominator());
}

TEST(StandardOperators, Truncate) {
  Ratio<int> a(2, 3);
  Ratio<int> b = a.truncate();

  EXPECT_EQ(0, b.getNumerator());
  EXPECT_EQ(1, b.getDenominator());
}

TEST(StandardOperators, RoundUpper) {
  Ratio<int> a(2, 3);
  Ratio<int> b = a.round();

  EXPECT_EQ(1, b.getNumerator());
  EXPECT_EQ(1, b.getDenominator());
}

TEST(StandardOperators, RoundLower) {
  Ratio<int> a(1, 3);
  Ratio<int> b = a.round();

  EXPECT_EQ(0, b.getNumerator());
  EXPECT_EQ(1, b.getDenominator());
}

TEST(StandardOperators, Inverse) {
  Ratio<int> a(1, 3);
  Ratio<int> b = a.inv();

  EXPECT_EQ(b.getDenominator(), a.getNumerator());
  EXPECT_EQ(a.getDenominator(), b.getNumerator());
}

TEST(StandardOperators, NegativeInverse) {
  Ratio<int> a(-1, 3);
  Ratio<int> b = a.inv();

  EXPECT_EQ(-b.getDenominator(), a.getNumerator());
  EXPECT_EQ(a.getDenominator(), -b.getNumerator());
}

// Comparison tests

TEST(ComparisonOperators, LowerWhenTrue) {
  Ratio<int> a(3, 5);
  Ratio<int> b(6, 7);

  EXPECT_TRUE(a < b);
  EXPECT_TRUE(Ratio<int>(1, 5) < Ratio<int>(3, 2));
  EXPECT_TRUE(Ratio<int>(1, 2) < Ratio<int>(9, 6));
  EXPECT_TRUE(Ratio<int>(2) < Ratio<int>(5));
  EXPECT_TRUE(Ratio<int>(2) < Ratio<int>(5, 2));
}

TEST(ComparisonOperators, LowerWhenFalse) {
  Ratio<int> a(3, 5);
  Ratio<int> b(6, 7);

  EXPECT_FALSE(b < a);
}

TEST(ComparisonOperators, LowerEqualWhenEqualA) {
  Ratio<int> a(3, 5);
  Ratio<int> b(6, 10);

  EXPECT_TRUE(a <= b);
}

TEST(ComparisonOperators, LowerEqualWhenEqualB) {
  Ratio<int> a(3, 5);
  Ratio<int> b(6, 10);

  EXPECT_TRUE(b <= a);
}

TEST(ComparisonOperators, LowerEqualWhenTrue) {
  Ratio<int> a(4, 5);
  Ratio<int> b(3, 5);

  EXPECT_TRUE(b <= a);
  EXPECT_TRUE(Ratio<int>(1, 5) <= Ratio<int>(3, 2));
  EXPECT_TRUE(Ratio<int>(1, 2) <= Ratio<int>(9, 6));
  EXPECT_TRUE(Ratio<int>(2) <= Ratio<int>(5));
  EXPECT_TRUE(Ratio<int>(2) <= Ratio<int>(5, 2));
}

TEST(ComparisonOperators, LowerEqualWhenFalse) {
  Ratio<int> a(4, 5);
  Ratio<int> b(3, 5);

  EXPECT_FALSE(a <= b);
  EXPECT_FALSE(Ratio<int>(3, 2) <= Ratio<int>(1, 5));
  EXPECT_FALSE(Ratio<int>(9, 6) <= Ratio<int>(1, 2));
  EXPECT_FALSE(Ratio<int>(5) <= Ratio<int>(2));
  EXPECT_FALSE(Ratio<int>(5, 2) <= Ratio<int>(2));
}

TEST(ComparisonOperators, EqualWhenFalse) {
  Ratio<int> a(4, 5);
  Ratio<int> b(3, 5);

  EXPECT_FALSE(a == b);
}

TEST(ComparisonOperators, EqualWhenTrue) {
  Ratio<int> a(4, 5);
  Ratio<int> b(8, 10);

  EXPECT_TRUE(a == b);
}

TEST(ComparisonOperators, DifferentWhenTrue) {
  Ratio<int> a(4, 5);
  Ratio<int> b(3, 5);

  EXPECT_TRUE(a != b);
}

TEST(ComparisonOperators, DifferentWhenFalse) {
  Ratio<int> a(4, 5);
  Ratio<int> b(8, 10);

  EXPECT_FALSE(a != b);
}

TEST(ComparisonOperators, EqualWhenTrueB) {
  Ratio<int> a(10, 7);
  Ratio<int> b(4, 7);

  EXPECT_EQ(a + b, 2);
}

TEST(ComparisonOperators, GreaterWhenFalse) {
  Ratio<int> a(3, 5);
  Ratio<int> b(6, 7);

  EXPECT_FALSE(a > b);
  EXPECT_FALSE(Ratio<int>(1, 5) > Ratio<int>(3, 2));
  EXPECT_FALSE(Ratio<int>(1, 2) > Ratio<int>(9, 6));
  EXPECT_FALSE(Ratio<int>(2) > Ratio<int>(5));
  EXPECT_FALSE(Ratio<int>(2) > Ratio<int>(5, 2));
}

TEST(ComparisonOperators, GreaterWhenTrue) {
  Ratio<int> a(3, 5);
  Ratio<int> b(6, 7);

  EXPECT_TRUE(b > a);
  EXPECT_TRUE(Ratio<int>(3, 2) > Ratio<int>(1, 5));
  EXPECT_TRUE(Ratio<int>(9, 6) > Ratio<int>(1, 2));
  EXPECT_TRUE(Ratio<int>(5) > Ratio<int>(2));
  EXPECT_TRUE(Ratio<int>(5, 2) > Ratio<int>(2));
}

TEST(ComparisonOperators, GreaterEqualWhenEqualA) {
  Ratio<int> a(3, 5);
  Ratio<int> b(6, 10);

  EXPECT_TRUE(a >= b);
}

TEST(ComparisonOperators, GreaterEqualWhenEqualB) {
  Ratio<int> a(3, 5);
  Ratio<int> b(6, 10);

  EXPECT_TRUE(b >= a);
}

TEST(ComparisonOperators, GreaterEqualWhenFalse) {
  Ratio<int> a(4, 5);
  Ratio<int> b(3, 5);

  EXPECT_FALSE(b >= a);
  EXPECT_FALSE(Ratio<int>(1, 5) >= Ratio<int>(3, 2));
  EXPECT_FALSE(Ratio<int>(1, 2) >= Ratio<int>(9, 6));
  EXPECT_FALSE(Ratio<int>(2) >= Ratio<int>(5));
  EXPECT_FALSE(Ratio<int>(2) >= Ratio<int>(5, 2));
}

TEST(ComparisonOperators, GreaterEqualWhenTrue) {
  Ratio<int> a(4, 5);
  Ratio<int> b(3, 5);

  EXPECT_TRUE(a >= b);
  EXPECT_TRUE(Ratio<int>(3, 2) >= Ratio<int>(1, 5));
  EXPECT_TRUE(Ratio<int>(9, 6) >= Ratio<int>(1, 2));
  EXPECT_TRUE(Ratio<int>(5) >= Ratio<int>(2));
  EXPECT_TRUE(Ratio<int>(5, 2) >= Ratio<int>(2));
}

// Print operator
TEST(FriendOperators, Print) {
  std::ostringstream oss117;
  oss117 << Ratio<int>(5, 2) << std::endl;
  EXPECT_EQ("5 / 2\n", oss117.str());
}

TEST(FriendOperators, PrintInteger) {
  std::ostringstream oss117;
  oss117 << Ratio<int>(5) << std::endl;
  EXPECT_EQ("5\n", oss117.str());
}

TEST(FriendOperators, PrintPlusInfinity) {
  std::ostringstream oss117;
  oss117 << Ratio<int>::PLUS_INF() << std::endl;
  EXPECT_EQ("+infinity\n", oss117.str());
}

TEST(FriendOperators, PrintMinusInfinity) {
  std::ostringstream oss117;
  oss117 << Ratio<int>::MINUS_INF() << std::endl;
  EXPECT_EQ("-infinity\n", oss117.str());
}

// Exception tests
TEST(Exception, ZeroByZero) {
  EXPECT_THROW(Ratio<int>(0, 0), std::domain_error);
}

TEST(Exception, IntoZeroByZero) {
  EXPECT_THROW(Ratio<int>::ZERO() * Ratio<int>::PLUS_INF(), std::domain_error);
}
