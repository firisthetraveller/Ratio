#include "../libRatio/include/Ratio.hpp"

// Disclaimer
// The following tests are by no means, as of November 17, 2022, complete.
// Passing all these tests does not guarantee a good behavior of the program.

// Conversions

TEST (Conversion, NegativeConversion) {
    Ratio<int> a = Ratio<int>::convert_from_float(-0.5f);

    EXPECT_EQ (-1, a.numerator);
    EXPECT_EQ (2, a.denominator);
}

// Methods

// TODO cos
TEST (ComplexOperators, BasicCosine) {
    // cos(0) = 1
    Ratio<int> a = Ratio<int>::ZERO;
    Ratio<int> b = Ratio<int>::cos(a).simplify();

    EXPECT_EQ(1, b.numerator);
    EXPECT_EQ(1, b.denominator);
}

// TODO exp
TEST (ComplexOperators, BasicExponential) {
    // exp(0) = 1
    Ratio<int> a = Ratio<int>::ZERO;
    Ratio<int> b = Ratio<int>::exp(a).simplify();

    EXPECT_EQ(1, b.numerator);
    EXPECT_EQ(1, b.denominator);
}

// TODO sqrt
TEST (ComplexOperators, BasicSquareRoot) {
    // sqrt(1) = 1
    Ratio<int> a (1, 1);
    Ratio<int> b = Ratio::exp(a).simplify();

    EXPECT_EQ(1, b.numerator);
    EXPECT_EQ(1, b.denominator);
}

TEST (ComplexOperators, NaturalSquareRoot) {
    // Exact value with only numerator
    Ratio<int> a = Ratio::sqrt(Ratio<int> (49, 1));
    Ratio<int> b = Ratio::sqrt(Ratio<int> (25, 1));
    Ratio<int> c = Ratio::sqrt(Ratio<int> (121, 1));

    EXPECT_EQ(7, a.numerator);
    EXPECT_EQ(1, a.denominator);

    EXPECT_EQ(5, b.numerator);
    EXPECT_EQ(1, b.denominator);

    EXPECT_EQ(11, c.numerator);
    EXPECT_EQ(1, c.denominator);
}
