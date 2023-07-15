#include "strings.hpp"
#include <algorithm>
#include <cctype>
#include <iterator>
#include <unordered_set>

size_t countAbc(const std::string& input) {
    auto counter = [](const std::string& s){
        std::unordered_set<char> letters;
            for(char c :s){
                if(isalpha(c)) letters.insert(c);
            }
        return letters.size();
    };
    return counter(input);
}

std::map<char, size_t> countIndividual(const std::string& input) {
    auto counter = [](const std::string& s){
        std::map<char,size_t> counterMap;
        for (char c : s){
            if(isalpha(c)){
                char getlower = std::tolower(c);
                counterMap[getlower]++;
                }
            
            }
        return counterMap;
        };
        return counter(input);
}

SymbolCounter::SymbolCounter(std::initializer_list<char> lst): checkList_(lst) {}

bool SymbolCounter::operator()(char c) const {
    for(char symbol :checkList_){
        if(symbol == c) return true;
        }
    return false;
}

std::list<char> usedSymbols(const std::string& input) {
    auto checker  = [](const std::string& s){
        std::list<char> checkedList(s.begin(),s.end());
        for(char &c : checkedList){
            
            if(std::isalpha(c) && std::isupper(c))  c = std::tolower(c);
            }
        checkedList.sort();
        checkedList.unique([](char a, char b){return a == b;});
        return checkedList;
        };
        
    return checker(input);
        
}
