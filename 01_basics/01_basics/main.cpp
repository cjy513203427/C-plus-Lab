#include "rational.hpp"
#include <iostream>

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

    std::cout << "simplified c: " << c.simplify() << std::endl;
    std::cout << "simplified d: " << d.simplify() << std::endl;
    std::cout << "simplified e: " << e.simplify() << std::endl;
    std::cout << "simplified f: " << f.simplify() << std::endl;

    return 0;
}
