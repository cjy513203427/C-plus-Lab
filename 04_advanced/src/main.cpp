#include <cctype>
#include <cstddef>
#include "strings.hpp"
#include "numerik.hpp"
#include <initializer_list>
#include <iostream>
#include <iterator>
#include <ostream>
#include <string>
#include <algorithm>
#include <cmath>

int main(int argc, char** argv) {
    
    std::string str1 = "apple,2";
    std::cout<<"***********test function countAbc()**********"<<std::endl;
    std::cout<<"input : "<<str1<<std::endl;
    std::cout<<"output : "<<countAbc(str1)<<std::endl;
    
    std::string str2 = "aaapple,2";
    std::cout<<"***********test function countIndividual()**********"<<std::endl;
    std::cout<<"input : "<<str2<<std::endl;
    std::map<char, size_t> getMap = countIndividual(str2);
    for (auto &m :getMap){
        std::cout<<"output : "<< m.first << ": " << m.second<<std::endl;
        }
        
    std::string str3 = "aasddfg+++";
    std::cout<<"***********test SymbolCounter**********"<<std::endl;
    std::cout<<"input : "<<str3<<std::endl;
    
    SymbolCounter sc ({'a','+'});
    
    std::cout<<"if a is in str3 : "<<sc('a')<<std::endl;
    std::cout<<"if + is in str3 : "<<sc('+')<<std::endl;
    std::cout<<"# of a and + is : "<<std::count_if(str3.begin(),str3.end(),sc)<<std::endl;
    
    std::string str4 = "aassddffg  --+++";
    std::cout<<"***********test usedSymbols**********"<<std::endl;
    std::cout<<"input : "<<str4<<std::endl;
    std::list<char> lookup = usedSymbols(str4);
    std::cout <<"found individual Symbols: ";
    for (const auto& element : lookup) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
    
    std::cout<<"***********test newton**********"<<std::endl;
    auto fx = [](double x){ return std::pow(x, 3) + 4 * std::pow(x, 2) - 7 * x + 12; };
    auto fderiv = [](float x){ return 3 * std::pow(x, 2) + 8 * x - 7; };
    double solution = newton(fx, fderiv, 0, 1000);
    std::cout<<"start at x = "<<0<<std::endl;
    std::cout<<"end at x = "<<solution<<std::endl;
}
