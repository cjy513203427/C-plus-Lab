#include "numerik.hpp"
#include <cstddef>

double newton(std::function<double(double)>fx, std::function<double(double)>fderiv, double x0, size_t n) {
    double rtn = x0;
    for(size_t i = 0; i<n; i++){
        rtn = rtn - fx(rtn)/fderiv(rtn);
        }
    
    return rtn;
}
