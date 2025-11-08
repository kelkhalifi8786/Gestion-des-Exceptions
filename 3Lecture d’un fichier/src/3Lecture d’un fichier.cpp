#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>

void lireFichier(const std::string& nomFichier) {
    std::ifstream fichier(nomFichier);
    if (!fichier.is_open()) {
        throw std::runtime_error("Erreur : impossible d’ouvrir le fichier " + nomFichier);
    }

    std::string ligne;
    while (std::getline(fichier, ligne)) {
        std::cout << ligne << std::endl;
    }
    fichier.close();
}

int main() {
    try {
        lireFichier("monfichier.txt");
    } catch (const std::runtime_error& e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
