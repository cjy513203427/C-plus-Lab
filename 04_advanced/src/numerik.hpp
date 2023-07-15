#pragma once
#include <cstddef>
#include <functional>
#include <cmath>

double newton(std::function<double(double)> fx, std::function<double(double)> fderiv, double x0, size_t n);

template <typename T>
T newtonTemp(std::function<T(T)> fx, std::function<T(T)> fderiv, T x0, size_t n) {
    T rtn = x0;
    for(size_t i = 0; i<n; i++){
        rtn = rtn - fx(rtn)/fderiv(rtn);
    }
    
    return rtn;
}

template <typename T>
T fxTemp(T x) {
    return x * x * x + 4 * x * x - 7 * x + 12;
}

template <typename T>
T fderivTemp(T x) {
    return 3 * x * x + 8 * x - 7;
}
