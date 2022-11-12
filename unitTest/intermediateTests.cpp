#include "../libRatio/include/Ratio.hpp"

// Methods

bool testSimplifyB () {
    Ratio<int> a (0, 3);
    a.simplify ();

    return a == Ratio::ZERO;
}

bool testSimplifyC () {
    Ratio<int> a (5, 0);
    a.simplify ();

    return a == Ratio::INFINITY;
}

// Operators
bool testScalarMultiplyA () {
    Ratio<int> a (2, 5);
    Ratio<int> b = 5 * a;

    b.simplify();

    return a == Ratio<int>(2, 1);
}

bool testScalarMultiplyB () {
    Ratio<int> a (2, 5);
    Ratio<int> b = a * 5;

    b.simplify();

    return a == Ratio<int>(2, 1);
}

bool testDivisionB () {
    Ratio<int> a (5, 6);
    Ratio<int> b = Ratio::ZERO;

    Ratio<int> c = a / b;

    return c.denominator == 0;
}

// Operators with some letters
bool testPowA () {
    Ratio<int> a (5, 2);
    Ratio<int> b = a.pow(5);

    return b.denominator == 32 && b.numerator == 5*25*25;
}

bool testPowB () {
    Ratio<int> a (5, 2);
    Ratio<int> b = a.pow(-1);
    Ratio<int> c = a.inv();

    return b == c;
}

// Convert

bool testConvertA () {
    Ratio<int> a = Ratio::convert_from_float(2.0f);

    return a.numerator == 2 && a.denominator == 1;
}

bool testConvertB () {
    Ratio<int> a = Ratio::convert_from_float(0.5f);

    return a.numerator == 1 && a.denominator == 2;
}

bool testConvertC () { // Not sure if this one works
    Ratio<int> a = Ratio::convert_from_float(0.33f);

    return a.numerator == 33 && a.denominator == 100;
}

// Value binding (operator =)
// Copy ? Or direct value binding ?
