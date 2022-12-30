#ifndef __RATIO_H__
#define __RATIO_H__

#include <cmath>
#include <iostream>
#include <numeric>
#include <functional>

/// \class Ratio
/// \brief A rational is defined by the ratio of two integers a and b.
template <class T>
class Ratio {
private:
  T mNumerator;
  unsigned int mDenominator;

  void simplify();

  static Ratio<T> convertFromFloatAux(float value, int nbIter);

  constexpr static Ratio<T> reduce(std::function <const Ratio<T>(const Ratio<T>, const Ratio<T>)> f, const Ratio<T>& r1, const Ratio<T>& r2);

  template <typename... Args>
  constexpr static Ratio<T> reduce(std::function <const Ratio<T>(const Ratio<T>, const Ratio<T>)> f, const Ratio<T>& r1, Args... args);
public:
  /// \brief Converts a floating point number to a rational number.
  /// \param value a floating point number
  /// \return the rational number converted
  static Ratio<T> convertFromFloat(float value, int nbIter = 10);

  /// \brief Creates a rational number (a / b) with its two values : the
  /// numerator and the denominator. By default, it returns the rational 0. With
  /// only one argument, it returns a rational valued to the integer given.
  /// \param a the numerator
  /// \param b the denominator
  Ratio(T a = static_cast<T>(0), int b = 1);

  /****************************
   * CONSTANTS
   ****************************/
   /**
    * \defgroup Constants
    * @{
    */
    /// \return a rational number that evaluates at 0 (zero).
  static const Ratio<T> ZERO();

  /// \return a rational number that evaluates at +infinity.
  static const Ratio<T> PLUS_INF();

  /// \return a rational number that evaluates at -infinity.
  static const Ratio<T> MINUS_INF();
  /** @} */

  /****************************
   * GETTERS
   ****************************/
   /**
    * \defgroup Getters
    * @{
    * \brief Returns the value of the numerator.
    * \return the numerator
    */
  constexpr T getNumerator() const;

  /**
   * \brief Returns the value of the denominator.
   * \return the denominator
   */
  constexpr unsigned int getDenominator() const;

  /** @} */

  /****************************
   * OPERATORS
   ****************************/
   /**
    * \defgroup Operators
    * @{
    */
  constexpr Ratio<T> operator-(const Ratio<T>& r) const;
  constexpr Ratio<T> operator-() const;
  constexpr Ratio<T> operator+(const Ratio<T>& r) const;
  constexpr Ratio<T> operator*(double scalar) const;
  constexpr Ratio<T> operator*(const Ratio<T>& r) const;
  constexpr Ratio<T> operator/(const Ratio<T>& r) const;
  /** @} */

  /****************************
   * COMPARISON OPERATORS
   ****************************/
   /**
    * \defgroup Comparison operators
    * @{
    */
  constexpr bool operator>(const Ratio<T>& r) const;
  constexpr bool operator>=(const Ratio<T>& r) const;
  constexpr bool operator<(const Ratio<T>& r) const;
  constexpr bool operator<=(const Ratio<T>& r) const;
  constexpr bool operator==(const Ratio<T>& r) const;
  constexpr bool operator!=(const Ratio<T>& r) const;

  /** @} */
  /****************************
   * MATH OPERATORS
   ****************************/
   /**
    * \defgroup Math operators
    * @{
    */
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
  /** @} */

  /****************************
   * METHODS
   ****************************/
   /// \brief Returns the value of the rational number as a floating point
   /// number.
   /// \return the value as a floating point number
  double eval() const;

  /***********************
   * VARIADICS
   ***********************/
  template <typename... Args>
  constexpr static Ratio<T> min(const Ratio<T>& r, Args... args);

  template <typename... Args>
  constexpr static Ratio<T> max(const Ratio<T>& r, Args... args);

  template <typename... Args>
  constexpr static Ratio<T> sum(const Ratio<T>& r, Args... args);

  template <typename... Args>
  constexpr static Ratio<T> product(const Ratio<T>& r, Args... args);

};

template <typename T>
Ratio<T> Ratio<T>::convertFromFloatAux(float value, int nbIter) {
  if (value == 0 || nbIter == 0)
    return ZERO();
  if (value < 1)
    return convertFromFloatAux(1 / value, nbIter).inv();
  int q = int(value);
  return Ratio<T>(q) + convertFromFloatAux(value - q, nbIter - 1);
}

template <typename T>
Ratio<T> Ratio<T>::convertFromFloat(float value, int nbIter) {
  return ((value < 0) ? Ratio<T>(-1) : Ratio<T>(1)) *
    convertFromFloatAux(std::abs(value), nbIter);
}

template <typename T> const Ratio<T> Ratio<T>::ZERO() {
  return Ratio<T>(static_cast<T>(0), 1);
}

template <typename T> const Ratio<T> Ratio<T>::PLUS_INF() {
  return Ratio<T>(static_cast<T>(1), 0);
}

template <typename T> const Ratio<T> Ratio<T>::MINUS_INF() {
  return Ratio<T>(static_cast<T>(-1), 0);
}

template <typename T> void Ratio<T>::simplify() {
  int gcd = int(std::gcd(mNumerator, mDenominator));
  mNumerator /= gcd;
  mDenominator /= gcd;
}

template <typename T> double Ratio<T>::eval() const {
  return mNumerator / double(mDenominator);
}

/****************************
 * CONSTRUCTORS
 ****************************/

template <typename T>
Ratio<T>::Ratio(T a, int b): mNumerator(a), mDenominator(b) {
  if (a == 0 && b == 0) {
    throw std::domain_error("zero_by_zero: undefined rational");
  }
  if (b < 0) {
    mNumerator = -a;
    mDenominator = -b;
  }
  simplify();
}

/****************************
 * GETTERS
 ****************************/

template <typename T> constexpr T Ratio<T>::getNumerator() const {
  return mNumerator;
}

template <typename T> constexpr unsigned int Ratio<T>::getDenominator() const {
  return mDenominator;
}

/****************************
 * OPERATORS
 ****************************/
template <typename T>
constexpr Ratio<T> Ratio<T>::operator-(const Ratio<T>& r) const {
  return Ratio<T>(mNumerator * r.mDenominator - mDenominator * r.mNumerator,
    mDenominator * r.mDenominator);
}

template <typename T> constexpr Ratio<T> Ratio<T>::operator-() const {
  return Ratio<T>(-mNumerator, mDenominator);
}

template <typename T>
constexpr Ratio<T> Ratio<T>::operator+(const Ratio<T>& r) const {
  return Ratio<T>(mNumerator * r.mDenominator + mDenominator * r.mNumerator,
    mDenominator * r.mDenominator);
}

template <typename T>
constexpr Ratio<T> Ratio<T>::operator*(double scalar) const {
  return (*this) * convertFromFloat(scalar);
}

template <typename T>
constexpr Ratio<T> operator*(double scalar, const Ratio<T>& r) {
  return r * Ratio<T>::convertFromFloat(scalar);
}

template <typename T>
constexpr Ratio<T> Ratio<T>::operator*(const Ratio<T>& r) const {
  return Ratio<T>(mNumerator * r.mNumerator, mDenominator * r.mDenominator);
}

template <typename T>
constexpr Ratio<T> Ratio<T>::operator/(const Ratio<T>& r) const {
  return *this * r.inv();
}

/****************************
 *  COMPARISON OPERATORS
 ****************************/
template <typename T>
constexpr bool Ratio<T>::operator>(const Ratio<T>& r) const {
  return mNumerator * r.mDenominator > r.mNumerator * mDenominator;
}

template <typename T>
constexpr bool Ratio<T>::operator>=(const Ratio<T>& r) const {
  return mNumerator * r.mDenominator >= r.mNumerator * mDenominator;
}

template <typename T>
constexpr bool Ratio<T>::operator<(const Ratio<T>& r) const {
  return !(*this >= r);
}

template <typename T>
constexpr bool Ratio<T>::operator<=(const Ratio<T>& r) const {
  return !(*this > r);
}

template <typename T>
constexpr bool Ratio<T>::operator==(const Ratio<T>& r) const {
  return mNumerator == r.mNumerator && mDenominator == r.mDenominator;
}

template <typename T>
constexpr bool Ratio<T>::operator!=(const Ratio<T>& r) const {
  return !(*this == r);
}

template <typename T>
constexpr Ratio<T> Ratio<T>::inv() const {
  return Ratio<T>(((mNumerator < 0) ? -1 : 1) * static_cast<T>(mDenominator), std::abs(mNumerator));
}

template <typename T>
Ratio<T> Ratio<T>::pow(double value) const {
  double num = std::pow(getNumerator(), value);
  double den = std::pow(getDenominator(), value);
  return Ratio<T>::convertFromFloat(num / den);
}

template <typename T>
constexpr Ratio<T> Ratio<T>::abs() const {
  return Ratio<T>(std::abs(mNumerator), mDenominator);
}

template <typename T>
constexpr Ratio<T> Ratio<T>::truncate() const {
  return Ratio<T>((mNumerator - (mNumerator % mDenominator)) / mDenominator);
}

template <typename T>
constexpr Ratio<T> Ratio<T>::round() const {
  int rest = mNumerator % mDenominator;
  return Ratio<T>((mNumerator - rest) / mDenominator + ((rest >= double(mDenominator) / 2) ? 1 : 0));
}

template <typename T>
Ratio<T> Ratio<T>::cos() const {
  return Ratio<T>::convertFromFloat(std::cos(eval()));
}

template <typename T>
Ratio<T> Ratio<T>::exp() const {
  return Ratio<T>::convertFromFloat(std::exp(eval()));
}

template <typename T>
Ratio<T> Ratio<T>::sqrt() const {
  return Ratio<T>::convertFromFloat(std::sqrt(eval()));
}

template <typename T>
std::ostream& operator<< (std::ostream& out, const Ratio<T>& r) {
  if (r.getDenominator() == 0)
    out << ((r.getNumerator() == 1) ? "+infinity" : "-infinity");
  else if (r.getDenominator() == 1)
    out << r.getNumerator();
  else
    out << r.getNumerator() << " / " << r.getDenominator();
  return out;
}

/*******************
 * VARIADICS
 *******************/

template <typename T>
template <typename... Args>
constexpr Ratio<T> Ratio<T>::min(const Ratio<T>& r, Args... args) {
  return reduce([](const Ratio<T>& r1, const Ratio<T>& r2) {return (r1 < r2) ? r1 : r2;}, r, args...);
}

template <typename T>
template <typename... Args>
constexpr Ratio<T> Ratio<T>::max(const Ratio<T>& r, Args... args) {
  return reduce([](const Ratio<T>& r1, const Ratio<T>& r2) {return (r1 > r2) ? r1 : r2;}, r, args...);
}

template <typename T>
template <typename... Args>
constexpr Ratio<T> Ratio<T>::sum(const Ratio<T>& r, Args... args) {
  return reduce([](const Ratio<T>& r1, const Ratio<T>& r2) {return r1 + r2;}, r, args...);
}

template <typename T>
template <typename... Args>
constexpr Ratio<T> Ratio<T>::product(const Ratio<T>& r, Args... args) {
  return reduce([](const Ratio<T>& r1, const Ratio<T>& r2) {return r1 * r2;}, r, args...);
}

template <typename T>
constexpr Ratio<T> Ratio<T>::reduce(std::function <const Ratio<T>(const Ratio<T>, const Ratio<T>)> f, const Ratio<T>& r1, const Ratio<T>& r2) {
  return f(r1, r2);
}

template <typename T>
template <typename... Args>
constexpr Ratio<T> Ratio<T>::reduce(std::function <const Ratio<T>(const Ratio<T>, const Ratio<T>)> f, const Ratio<T>& r, Args... args) {
  return reduce(f, r, reduce(f, args...));
}

#endif
