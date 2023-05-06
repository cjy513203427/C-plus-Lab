#include "map.hpp"
#include "food.hpp"
#include <iostream>

int main(int argc, char** argv) {
    // TODO Kreativaufgabe
/*    
    cppp::Map myMap(10); // erstelle HashMap mit 10 Buckets
    
    std::vector<cppp::Item> items1{{2, "Pizza Margherita"}, {1, "Pasta Bolognese"}};
    myMap.insert("Bestellung1", items1);

    std::vector<cppp::Item> items2{{3, "Schnitzel Wiener Art"}, {2, "Kartoffelsalat"}};
    myMap.insert("Bestellung2", items2);
    
    std::vector<cppp::Item> bestellung1_items = myMap.get("Bestellung1");
    for (const auto& item : bestellung1_items) {
        std::cout << "Bestellung1: " << item.anzahl << "x " << item.bezeichnung << std::endl;
    }
    std::vector<cppp::Item> bestellung2_items = myMap.get("Bestellung2");
    for (const auto& item : bestellung2_items) {
        std::cout << "Bestellung2: " << item.anzahl << "x " << item.bezeichnung << std::endl;
    }
        
    myMap.remove("Bestellung2");*/
    
  // Create some food objects
    Food food1(1, "Pizza Margherita", 8.99);
    Food food2(2, "Spaghetti Carbonara", 9.99);
    Food food3(3, "Schnitzel Wiener Art", 12.99);

    // Add the foods to a vector
    std::vector<Food> foods = {food1, food2, food3};

    // Save the foods to a CSV file
    speichern("speisekarte.csv", foods);

    // Load the foods from the CSV file
    std::vector<Food> loadedFoods;
    laden("speisekarte.csv", loadedFoods);

    // Print the loaded foods to the console
    std::cout << "Loaded foods:\n";
    for (const auto& food : loadedFoods) {
        std::cout << "Bestellnummer: " << food.getBestellnummer() << ", Bezeichnung: " << food.getBezeichnung()
                  << ", Preis: " << food.getPreis() << "\n";
    }

    return 0;

}
