#include <iostream>
#include <stdexcept> // pour std::runtime_error

int diviser(int a, int b) {
    if (b == 0) {
        throw std::runtime_error("Erreur : division par zéro !");
    }
    return a / b;
}

int main() {
    int x = 10, y = 0;

    try {
        std::cout << "10 / 2 = " << diviser(10, 2) << std::endl;
        std::cout << "10 / 0 = " << diviser(10, 0) << std::endl;
    } catch (const std::runtime_error& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
