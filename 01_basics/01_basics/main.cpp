#include "rational.hpp"
#include <iostream>

Rational simplify(int counter, int denominator) {
    // compute the greatest common divisor using Euclid's algorithm
    int a = counter, b = denominator, tmp;
    if (b > a) {  // swap the values if denominator is greater than counter
        tmp = a;
        a = b;
        b = tmp;
    }
    while (b != 0) {
        tmp = b;
        b = a % b;
        a = tmp;
    }
    // simplify the fraction
    Rational rhs(counter, denominator);
    rhs.counter /= a;
    rhs.denominator /= a;
    return rhs;
}

int main() {
    Rational a(1, 4);
    Rational b(1, 2);

    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;

    Rational c = a + b;
    Rational d = a - b;
    Rational e = a * b;
    Rational f = a / b;

    std::cout << "c: " << c << std::endl;
    std::cout << "d: " << d << std::endl;
    std::cout << "e: " << e << std::endl;
    std::cout << "f: " << f << std::endl;

    if (c < d && c < e && c < f) {
        std::cout << "c is the smallest" << std::endl;
    } else if (d < e && d < f) {
        std::cout << "d is the smallest" << std::endl;
    } else if (e < f) {
        std::cout << "e is the smallest" << std::endl;
    } else {
        std::cout << "f is the smallest" << std::endl;
    }

    std::cout << "simplified c: " << simplify(c.counter,c.denominator) << std::endl;
    std::cout << "simplified d: " << simplify(d.counter,d.denominator) << std::endl;
    std::cout << "simplified e: " << simplify(e.counter,e.denominator) << std::endl;
    std::cout << "simplified f: " << simplify(f.counter,f.denominator) << std::endl;

    return 0;
}
