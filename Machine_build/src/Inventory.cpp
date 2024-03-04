#include "../include/menu.h"
#include "../include/inventory.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void displayinventory(const std::vector<product>& inventory){
    if (inventory.empty()){
        cout << "inventory is empty.\n";
    }else{
        cout << "inventory:\n";
        cout << "-------------------------\n";
        cout << "Name\t\tPrice\tQuantity\n";
        for (const auto& product : inventory) {
            std::cout << product.int_code << "\t\t" << product.price << "\t" << product.quantity << "\n";
        }
        std::cout << "----------------------------------------------\n";
    }

}
void addProduct(std::vector<product>& inventory) {
    product newProduct;

    std::cout << "Enter product code: ";
    std::cin >> newProduct.int_code;

    std::cout << "Enter product price: ";
    std::cin >> newProduct.price;

    std::cout << "Enter product quantity: ";
    std::cin >> newProduct.quantity;

    inventory.push_back(newProduct);
    std::cout << "Product added to inventory.\n";
}

void testeinventory(){
    cout << "funcao teste inventory" << endl;
}