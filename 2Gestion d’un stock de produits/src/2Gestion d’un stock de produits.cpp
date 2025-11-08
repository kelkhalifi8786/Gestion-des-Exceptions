#include <iostream>
#include <stdexcept>

class StockInsuffisantException : public std::runtime_error {
public:
    StockInsuffisantException(const std::string& msg)
        : std::runtime_error(msg) {}
};

class Produit {
    int stock;
public:
    Produit(int initial) : stock(initial) {}

    void vendre(int quantite) {
        if (quantite > stock) {
            throw StockInsuffisantException("Stock insuffisant pour la vente !");
        }
        stock -= quantite;
        std::cout << "Vente réussie. Stock restant : " << stock << std::endl;
    }
};

int main() {
    Produit p(5);

    try {
        p.vendre(3);
        p.vendre(4); // déclenche l’exception
    } catch (const StockInsuffisantException& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
