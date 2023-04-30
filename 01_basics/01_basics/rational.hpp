#ifndef RATIONAL_HPP_
#define RATIONAL_HPP_

#include <iostream>

class Rational {
public:
    int counter;
    int denominator;

    Rational();
    Rational(int counter, int denominator);
    Rational(const Rational& other);
    ~Rational();

    friend std::ostream& operator<<(std::ostream& os, const Rational& rational);
    Rational operator+(const Rational& rhs) const;
    Rational operator-(const Rational& rhs) const;
    Rational operator*(const Rational& rhs) const;
    Rational operator/(const Rational& rhs) const;
    bool operator<(const Rational& rhs) const;

    Rational simplify() const;
};

#endif /* RATIONAL_HPP_ */
