#pragma once
#include <string>
#include <map>
#include <list>
#include <algorithm>
#include <unordered_set>

size_t countAbc(const std::string& input);

std::map<char, size_t> countIndividual(const std::string& input);

std::list<char> usedSymbols(const std::string& input);

class SymbolCounter {
private:
    std::list<char> checkList_;

public:
    explicit SymbolCounter(std::initializer_list<char> lst);

    bool operator()(char c) const;
};
