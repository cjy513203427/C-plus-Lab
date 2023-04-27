#include "rational.hpp"
#include <iostream>

Rational::Rational() : z(1), n(2) {
    std::cout << "Rational " << z << "/" << n << " created" << std::endl;
}

Rational::Rational(int counter, int denominator) : z(counter), n(denominator) {
    std::cout << "Rational " << z << "/" << n << " created" << std::endl;
}

Rational::Rational(const Rational& other) : z(other.z), n(other.n) {
    std::cout << "Rational " << z << "/" << n << " copied" << std::endl;
}

Rational::~Rational() {
    std::cout << "Rational " << z << "/" << n << " destroyed" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Rational& rational) {
    os << rational.z << "/" << rational.n;
    return os;
}

Rational Rational::operator+(const Rational& rhs) const {
    Rational result;
    result.z = z * rhs.n + rhs.z * n;
    result.n = n * rhs.n;
    return result;
}

Rational Rational::operator-(const Rational& rhs) const {
    Rational result;
    result.z = z * rhs.n - rhs.z * n;
    result.n = n * rhs.n;
    return result;
}

Rational Rational::operator*(const Rational& rhs) const {
    Rational result;
    result.z = z * rhs.z;
    result.n = n * rhs.n;
    return result;
}

Rational Rational::operator/(const Rational& rhs) const {
    Rational result;
    result.z = z * rhs.n;
    result.n = n * rhs.z;
    return result;
}

bool Rational::operator<(const Rational& rhs) const {
    return z * rhs.n < rhs.z * n;
}

Rational Rational::simplify() const {
    Rational result = *this;
    // compute the greatest common divisor using Euclid's algorithm
    int a = result.z, b = result.n, tmp;
    while (b != 0) {
        tmp = b;
        b = a % b;
        a = tmp;
    }
    // simplify the fraction
    result.z /= a;
    result.n /= a;
    return result;
}

