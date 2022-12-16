#ifndef __RATIO_H__
#define __RATIO_H__

#include <numeric>
#include <cmath>
#include <iostream>

/// \class Ratio
/// \brief A rational is defined by the ratio of two integers a and b.
template <class T>
class Ratio
{
private:
    T m_numerator;
    unsigned int m_denominator;

    void simplify();

    static Ratio<T> convertFromFloatAux(float value, int nbIter);

public:
    /// \brief Converts a floating point number to a rational number.
    /// \param value a floating point number
    /// \return the rational number converted
    static Ratio<T> convertFromFloat(float value, int nbIter = 10);

    /// \brief Creates a rational number based on an integer. Its value is the number given.
    /// By default, it returns the rational 0.
    /// \param n an integer-type value
    Ratio(T n = static_cast<T>(0));

    /// \brief Creates a rational number (a / b) with its two values : the numerator and the denominator.
    /// \param a the numerator
    /// \param b the denominator
    Ratio(T a, int b);

    /****************************
     * GETTERS
     ****************************/

    /// \return a rational number that evaluates at 0 (zero).
    static const Ratio<T> ZERO();

    /// \return a rational number that evaluates at +infinity.
    static const Ratio<T> PLUS_INF();

    /// \return a rational number that evaluates at -infinity.
    static const Ratio<T> MINUS_INF();

    /****************************
     * GETTERS
     ****************************/
    /// \brief Returns the value of the numerator.
    /// \return the numerator
    constexpr T getNumerator() const;

    /// \brief Returns the value of the denominator.
    /// \return the denominator
    constexpr unsigned int getDenominator() const;

    /****************************
     * OPERATORS
     ****************************/
    constexpr Ratio<T> operator-(const Ratio<T> &r) const;
    constexpr Ratio<T> operator-() const;
    constexpr Ratio<T> operator+(const Ratio<T> &r) const;
    constexpr Ratio<T> operator*(double scalar) const;
    constexpr Ratio<T> operator*(const Ratio<T> &r) const;
    constexpr Ratio<T> operator/(const Ratio<T> &r) const;

    /****************************
     * COMPARISON OPERATORS
     ****************************/
    constexpr bool operator>(const Ratio<T> &r) const;
    constexpr bool operator>=(const Ratio<T> &r) const;
    constexpr bool operator<(const Ratio<T> &r) const;
    constexpr bool operator<=(const Ratio<T> &r) const;
    constexpr bool operator==(const Ratio<T> &r) const;

    constexpr bool operator==(const int a) const;

    /****************************
     * MATH OPERATORS
     ****************************/

    /// \brief Returns the absolute value of the rational number.
    /// \return the absolute value as a rational number
    constexpr Ratio<T> abs() const;

    /// \brief Returns the rational number at the power given.
    /// \param value the power value
    /// \return the power as a rational number
    Ratio<T> pow(double value) const;

    /// \brief Returns the inverse of rational number.
    /// \return the inverse
    constexpr Ratio<T> inv() const;

    /// \brief Returns the cos of rational number.
    /// \return the cosinus as a rational number
    Ratio<T> cos() const;

    /// \brief Returns the square root of rational number.
    /// \return the square root as a rational number
    Ratio<T> sqrt() const;

    /// \brief Returns the exponential of rational number.
    /// \return the exponential as a rational number
    Ratio<T> exp() const;

    /// \brief Returns the integer part.
    /// \return the integer part as a rational number
    constexpr Ratio<T> truncate() const;

    /// \brief Returns the nearest integer.
    /// \return the nearest integer as a rational number
    constexpr Ratio<T> round() const;

    /****************************
     * METHODS
     ****************************/
    /// \brief Returns the value of the rational number as a floating point number.
    /// \return the value as a floating point number
    double eval() const;
};

template <typename T>
Ratio<T> Ratio<T>::convertFromFloatAux(float value, int nbIter)
{
    if (value == 0 || nbIter == 0)
        return ZERO();
    if (value < 1)
        return convertFromFloatAux(1 / value, nbIter).inv();
    int q = int(value);
    return Ratio<T>(q) + convertFromFloatAux(value - q, nbIter - 1);
}

template <typename T>
Ratio<T> Ratio<T>::convertFromFloat(float value, int nbIter)
{
    return ((value < 0) ? Ratio<T>(-1) : Ratio<T>(1)) * convertFromFloatAux(std::abs(value), nbIter);
}

#endif
