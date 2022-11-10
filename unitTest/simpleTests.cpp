#include "../libRatio/include/Ratio.hpp"

// Constant value tests

bool testZero () {
    return Ratio::ZERO.numerator == 0 && Ratio::ZERO.denominator == 1;
}

bool testInfinity () {
    return Ratio::INFINITY.numerator == 1 && Ratio::PLUS_INF.denominator == 0;
}

bool testInfPlus () {
    return Ratio::PLUS_INF.numerator == 1 && Ratio::PLUS_INF.denominator == 0;
}

bool testInfPlus () {
    return Ratio::MINUS_INF.numerator == -1 && Ratio::MINUS_INF.denominator == 0;
}

// Type tests

bool testIntA () {
    Ratio<int> a (1, 2);

    return typeid(int) == typeid(a.numerator);
}

bool testIntB () {
    Ratio<long int> a (1, 2);

    return typeid(long int) == typeid(a.numerator);
}

// Operator tests

bool testAdditionA () {
    Ratio<int> a (5, 6);
    Ratio<int> b (2, 3);

    Ratio<int> c = a + b;

    return c.numerator == 9 && c.denominator == 6;
}

bool testSubtractionA () {
    Ratio<int> a (5, 6);
    Ratio<int> b (2, 3);

    Ratio<int> c = a - b;

    return c.numerator == 1 && c.denominator == 6;
}

bool testMultiplyA () {
    Ratio<int> a (5, 6);
    Ratio<int> b (2, 3);

    Ratio<int> c = a * b;

    return c.numerator == 10 && c.denominator == 18;
}

bool testDivideA () {
    Ratio<int> a (5, 6);
    Ratio<int> b (2, 3);

    Ratio<int> c = a / b;

    return c.numerator == 15 && c.denominator == 12;
}

bool testAbsA () {
    Ratio<int> a (-5, 1);
    a = a.abs();

    return a.numerator == 5 && b.denominator == 1;
}

bool testUnaryMinusA () {
    Ratio<int> a (2, 3);
    Ratio<int> b = -a;

    return b.numerator == -2 && b.denominator == 3;
}

bool testRoundA () {
    Ratio<int> a (2, 3);

    return b.numerator == 0 && b.denominator == 3;
}

bool testRoundA () {
    Ratio<int> a (2, 3);

    return b.numerator == 0 && b.denominator == 3;
}

// Comparison tests

bool testLowerA () {
    Ratio<int> a (3, 5);
    Ratio<int> b (6, 7);

    return (a < b) == true;
}

bool testLowerB () {
    Ratio<int> a (3, 5);
    Ratio<int> b (6, 7);

    return (b < a) == false;
}

bool testLowerEqualA () {
    Ratio<int> a (3, 5);
    Ratio<int> b (6, 10);

    return (a <= b) == true;
}

bool testLowerEqualB () {
    Ratio<int> a (3, 5);
    Ratio<int> b (6, 10);

    return (b <= a) == true;
}

bool testLowerEqualC () {
    Ratio<int> a (4, 5);
    Ratio<int> b (3, 5);

    return (b <= a) == true;
}

bool testLowerEqualD () {
    Ratio<int> a (4, 5);
    Ratio<int> b (3, 5);

    return (a <= b) == false;
}

bool testEqualA () {
    Ratio<int> a (4, 5);
    Ratio<int> b (3, 5);

    return (a == b) == false;
}

bool testEqualB () {
    Ratio<int> a (4, 5);
    Ratio<int> b (8, 10);

    return (a == b) == true;
}

bool testGreaterA () {
    Ratio<int> a (3, 5);
    Ratio<int> b (6, 7);

    return (a > b) == false;
}

bool testGreaterB () {
    Ratio<int> a (3, 5);
    Ratio<int> b (6, 7);

    return (b > a) == true;
}

bool testGreaterEqualA () {
    Ratio<int> a (3, 5);
    Ratio<int> b (6, 10);

    return (a >= b) == true;
}

bool testGreaterEqualB () {
    Ratio<int> a (3, 5);
    Ratio<int> b (6, 10);

    return (b >= a) == true;
}

bool testGreaterEqualC () {
    Ratio<int> a (4, 5);
    Ratio<int> b (3, 5);

    return (b >= a) == false;
}

bool testGreaterEqualD () {
    Ratio<int> a (4, 5);
    Ratio<int> b (3, 5);

    return (a >= b) == true;
}

// Exception tests
// TODO

// Constructor tests

bool testConstructorA () {
    Ratio<int> a (1, 2);

    return a.numerator == 1 && b.denominator == 2;
}

bool testConstructorB () {
    Ratio<int> a (5); // integer

    return a.numerator == 1 && b.denominator == 2;
}

bool testAutoCorrectA () {
    Ratio<int> a (5, -6);

    return a.numerator == -5 && b.denominator == 6;
}

bool testAutoCorrectB () {
    Ratio<int> a (-5, -6);

    return a.numerator == 5 && b.denominator == 6;
}

// Methods

bool testSimplifyA () {
    Ratio<int> a = Ratio<int> (5, 6);
    Ratio<int> b = Ratio<int> (2, 3);

    Ratio<int> c = a * b;
    c.simplify();

    return c.numerator == 5 && c.denominator == 9;
}
