#include "rational.hpp"
#include <iostream>

Rational::Rational() : counter(1), denominator(2) {
    std::cout << "Rational " << counter << "/" << denominator << " created" << std::endl;
}

Rational::Rational(int counter, int denominator) : counter(counter), denominator(denominator) {
    std::cout << "Rational " << counter << "/" << denominator << " created" << std::endl;
}

Rational::Rational(const Rational& other) : counter(other.counter), denominator(other.denominator) {
    std::cout << "Rational " <<counter << "/" << denominator << " copied" << std::endl;
}

Rational::~Rational() {
    std::cout << "Rational " << counter << "/" << denominator << " destroyed" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Rational& rational) {
    os << rational.counter << "/" << rational.denominator;
    return os;
}

Rational Rational::operator+(const Rational& rhs) const {
    Rational result;
    result.counter = counter * rhs.denominator + rhs.counter * denominator;
    result.denominator = denominator * rhs.denominator;
    return result;
}

Rational Rational::operator-(const Rational& rhs) const {
    Rational result;
    result.counter = counter * rhs.denominator - rhs.counter * denominator;
    result.denominator = denominator * rhs.denominator;
    return result;
}

Rational Rational::operator*(const Rational& rhs) const {
    Rational result;
    result.counter = counter * rhs.counter;
    result.denominator = denominator * rhs.denominator;
    return result;
}

Rational Rational::operator/(const Rational& rhs) const {
    Rational result;
    result.counter = counter * rhs.denominator;
    result.denominator = denominator * rhs.counter;
    return result;
}

bool Rational::operator<(const Rational& rhs) const {
    return counter * rhs.denominator < rhs.counter * denominator;
}

/*Rational Rational::simplify() const {
    Rational result = *this;
    // compute the greatest common divisor using Euclid's algorithm
    int a = result.counter, b = result.denominator, tmp;
    while (b != 0) {
        tmp = b;
        b = a % b;
        a = tmp;
    }
    // simplify the fraction
    result.counter /= a;
    result.denominator /= a;
    return result;
}*/

Rational simplify(Rational r)
{
    if (r.counter == 0) {
        std::cout << "check point" << std::endl;
        return r;
    }
    int a = (r.denominator > r.counter) ? r.denominator : r.counter;
    int b = (r.denominator > r.counter) ? r.counter : r.denominator;
    int temp;
    while (temp = a % b) {

        a = b;
        b = temp;
    }

    r.denominator = r.denominator / b;
    r.counter = r.counter / b;

    return r;
}
