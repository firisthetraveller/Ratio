#include <gtest/gtest.h>

#include "../../libRatio/include/Ratio.hpp"

// Types
// TODO : Ratio<unsigned int>

// Methods

TEST(Simplify, ToConstZero) {
  Ratio<int> a(0, 3);

  EXPECT_EQ(a, Ratio<int>::ZERO());
}

TEST(Simplify, ToConstInfinity) {
  Ratio<int> a(5, 0);

  EXPECT_EQ(a, Ratio<int>::PLUS_INF());
}

TEST(Simplify, ToConstNegativeInfinity) {
  Ratio<int> a(-5, 0);

  EXPECT_EQ(a.getNumerator(), Ratio<int>::MINUS_INF().getNumerator());
  EXPECT_EQ(a.getDenominator(), Ratio<int>::MINUS_INF().getDenominator());
  EXPECT_EQ(a, Ratio<int>::MINUS_INF());
}

// Operators
/*TEST(IntermediateOperators, ScalarMultiplyA)
{
    Ratio<int> a(2, 5);
    Ratio<int> b = 5 * a;

    EXPECT_EQ(b, Ratio<int>(2, 1));
}*/

TEST(IntermediateOperators, ScalarMultiplyB) {
  Ratio<int> a(2, 5);
  Ratio<int> b = a * 5;

  EXPECT_EQ(b.getNumerator(), 2);
  EXPECT_EQ(b.getDenominator(), 1);
}

/*TEST(IntermediateOperators, ScalarMultiplyDouble)
{
    Ratio<int> a(2, 5);
    Ratio<int> b = 7.5 * a;

    EXPECT_EQ(b, Ratio<int>(3, 1));
}*/

/*TEST(IntermediateOperators, ScalarMultiplyTrueDouble)
{
    Ratio<int> a(2, 5);
    Ratio<int> b = 7.9 * a;

    double c = 2.0 / 5;
    double d = 7.9 * c;

    EXPECT_NEAR(b.eval(), d, 10e-7);
}*/

TEST(IntermediateOperators, DivisionByZero) {
  Ratio<int> a(5, 6);
  Ratio<int> b = Ratio<int>::ZERO();

  Ratio<int> c = a / b;

  EXPECT_EQ(0, c.getDenominator());
  EXPECT_EQ(c.abs(), Ratio<int>::PLUS_INF());
}

TEST(IntermediateOperators, NegativeDivision) {
  Ratio<int> a(-5, 6);
  Ratio<int> b = Ratio<int>(6, 3);

  Ratio<int> c = a / b;

  EXPECT_EQ(12, c.getDenominator());
  EXPECT_EQ(-5, c.getNumerator());
}

TEST(IntermediateOperators, DivisionByZeroMinus) {
  Ratio<int> a(-5, 6);
  Ratio<int> b = Ratio<int>::ZERO();

  Ratio<int> c = a / b;

  EXPECT_EQ(0, c.getDenominator());
  EXPECT_EQ(-1, c.getNumerator());
  EXPECT_EQ(c, Ratio<int>::MINUS_INF());
}

// Operators with some letters
TEST(IntermediateMethodOperators, Power) {
  Ratio<int> a(5, 2);
  Ratio<int> b = a.pow(5);

  EXPECT_EQ(32, b.getDenominator());
  EXPECT_EQ(5 * 25 * 25, b.getNumerator());
  EXPECT_NEAR(b.eval(), (5.0 * 25 * 25) / 32.0, 10e-7);
}

TEST(IntermediateMethodOperators, NegativePower) {
  Ratio<int> a(5, 2);
  Ratio<int> b = a.pow(-1);
  Ratio<int> c = a.inv();

  EXPECT_EQ(b.getNumerator(), c.getNumerator());
  EXPECT_EQ(b.getDenominator(), c.getDenominator());
  EXPECT_EQ(b, c);
}

// Convert

TEST(Conversion, SimpleConversionInteger) {
  Ratio<int> a = Ratio<int>::convertFromFloat(2.0f);

  EXPECT_EQ(2, a.getNumerator());
  EXPECT_EQ(1, a.getDenominator());
}

TEST(Conversion, SimpleConversionBigInteger) {
  Ratio<int> a = Ratio<int>::convertFromFloat(150.0f);

  EXPECT_EQ(150, a.getNumerator());
  EXPECT_EQ(1, a.getDenominator());
}

TEST(Conversion, SimpleConversionBigInteger2) {
  Ratio<int> a = Ratio<int>::convertFromFloat(-150.0f);

  EXPECT_EQ(-150, a.getNumerator());
  EXPECT_EQ(1, a.getDenominator());
}

TEST(Conversion, SimpleConversionDecimal) {
  Ratio<int> a = Ratio<int>::convertFromFloat(0.5f);

  EXPECT_EQ(1, a.getNumerator());
  EXPECT_EQ(2, a.getDenominator());
}

TEST(Conversion, SimpleConversionDecimal2) {
  Ratio<int> a = Ratio<int>::convertFromFloat(0.2f);

  EXPECT_EQ(1, a.getNumerator());
  EXPECT_EQ(5, a.getDenominator());
  EXPECT_NEAR(1.0 / 5, a.eval(), 10e-10);
}


TEST(Conversion, SimpleConversionDecimal3) {
  Ratio<int> a = Ratio<int>::convertFromFloat(-150.2f);

  EXPECT_NEAR(-150.2f, a.eval(), 10e-10);
}

TEST(Conversion, SimpleConversionDecimal4_1) {
  Ratio<int> a = Ratio<int>::convertFromFloat(-150.1f, 10);

  EXPECT_NEAR(-150.1f, a.eval(), 10e-10);
}

TEST(Conversion, SimpleConversionDecimal4_2) {
  Ratio<int> a = Ratio<int>::convertFromFloat(-150.1f, 15);

  EXPECT_NEAR(-150.1f, a.eval(), 10e-10);
}

TEST(Conversion, ConversionDecimal) {
  Ratio<int> a = Ratio<int>::convertFromFloat(0.33, 10);

  EXPECT_NEAR(33.0 / 100, a.eval(), 10e-10);
}

TEST(Conversion, ConversionDecimal2) {
  Ratio<int> a = Ratio<int>::convertFromFloat(0.3333f, 10);

  EXPECT_NEAR(3333.0 / 10000, a.eval(), 10e-10);
}
