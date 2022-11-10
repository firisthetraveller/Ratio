#include "../libRatio/include/Ratio.hpp"

// Conversions

bool testConvertNegativeA () {
    Ratio<int> a = Ratio::convert_from_float(-0.5f);

    return a.numerator == -1 && a.denominator == 2;
}

// Methods

bool testSimplifyB () {
    Ratio<int> a (0, 3);
    a.simplify ();

    return a == Ratio::ZERO;
}

// TODO cos
bool testCosA () {
    // cos(0) = 1
    Ratio<int> a = Ratio::ZERO;
    Ratio<int> b = Ratio::cos(a).simplify();

    return b.numerator == 1 && b.denominator == 1;
}

// TODO exp
bool testExpA () {
    // exp(0) = 1
    Ratio<int> a = Ratio::ZERO;
    Ratio<int> b = Ratio::exp(a).simplify();

    return b.numerator == 1 && b.denominator == 1;
}

// TODO sqrt
bool testSqrtA () {
    // sqrt(1) = 1
    Ratio<int> a (1, 1);
    Ratio<int> b = Ratio::exp(a).simplify();

    return b.numerator == 1 && b.denominator == 1;
}

bool testSqrtB () {
    // Exact value with only numerator
    Ratio<int> a (25, 1);
    Ratio<int> b = Ratio::sqrt(a).simplify();

    return b.numerator == 5 && b.denominator == 1;
}
