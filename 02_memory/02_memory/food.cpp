#include "food.hpp"
#include <fstream>
#include <sstream>
#include <string>
#include <stdexcept>

Food::Food(int bestellnummer, std::string bezeichnung, float preis) : bestellnr(bestellnummer), bezeichnung(bezeichnung), preis(preis) {}

std::string Food::getBezeichnung() const {
    return bezeichnung;
}

float Food::getPreis() const {
    return preis;
}

int Food::getBestellnummer() const {
    return bestellnr;
}

void speichern(const std::string& dateiname, const std::vector<Food>& speisen) {
    // Öffne die Datei im Schreibmodus
    std::ofstream file(dateiname);

    // Überprüfe, ob die Datei geöffnet werden konnte
    if (!file) {
        throw std::runtime_error("Datei konnte nicht geöffnet werden");
    }

    // Schreibe die Speisen in die Datei
    for (const Food& speise : speisen) {
        file << speise.getBestellnummer() << ";" << speise.getBezeichnung() << ";" << speise.getPreis() << std::endl;
    }

    // Schließe die Datei
    file.close();
}

void laden(const std::string& dateiname, std::vector<Food>& speisen) {
    // Öffne die Datei im Lesemodus
    std::ifstream file(dateiname);

    // Überprüfe, ob die Datei geöffnet werden konnte
    if (!file) {
        throw std::runtime_error("Datei konnte nicht geöffnet werden");
    }

    // Lese die Speisen aus der Datei
    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string token;
        std::vector<std::string> tokens;
        while (std::getline(ss, token, ';')) {
            tokens.push_back(token);
        }
        if (tokens.size() != 3) {
            throw std::runtime_error("Ungültiges Format in der CSV-Datei");
        }
        int bestellnummer = std::stoi(tokens[0]);
        std::string bezeichnung = tokens[1];
        float preis = std::stof(tokens[2]);
        Food speise(bestellnummer, bezeichnung, preis);
        speisen.push_back(speise);
    }

    // Schließe die Datei
    file.close();
}
