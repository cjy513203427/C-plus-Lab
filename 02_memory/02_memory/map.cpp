#include "map.hpp"
#include <string>
#include <vector>
#include <stdexcept>
#include <algorithm>

cppp::Map::Map(const std::size_t size) : size(size) {
    arr = new MapBucket[size];
}

cppp::Map::~Map() {
    for (std::size_t i = 0; i < size; ++i) {
        arr[i].clear();
    }
    delete[] arr;
}

std::size_t cppp::Map::calcHash(const std::string& key) {
    std::size_t hash = 0;
    for (const char& c : key) {
        hash += static_cast<std::size_t>(c);
    }
    return hash % size;
}

void cppp::Map::insert(const std::string& key, const std::vector<Item>& order) {
    std::size_t index = calcHash(key);
    for (MapElement& element : arr[index]) {
        if (element.key == key) {
            element.value = order;
            return;
        }
    }
    arr[index].push_back(MapElement{ key, order });
}

std::vector<cppp::Item> cppp::Map::get(const std::string& key) {
    std::size_t index = calcHash(key);
    for (const MapElement& element : arr[index]) {
        if (element.key == key) {
            return element.value;
        }
    }
    throw std::invalid_argument("Key not found");
}

void cppp::Map::remove(const std::string& key) {
    std::size_t index = calcHash(key);
    for (auto it = arr[index].begin(); it != arr[index].end(); ++it) {
        if (it->key == key) {
            arr[index].erase(it);
            return;
        }
    }
}
