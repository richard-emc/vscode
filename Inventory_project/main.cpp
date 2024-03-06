#include "inventory.h"
#include <chrono>
#include <ctime>
#include <iostream>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;

void displayMenu()
{
    cout << "\n====== Inventory Menu ======\n";
    cout << "1. Display Inventory\n";
    cout << "2. Add Product\n";
    cout << "3. Record Transaction\n";
    cout << "4. Save and Exit\n";
    cout << "=============================\n";
    cout << "Enter your choice (1-4): ";
}


int main () {
    Inventory inventory("inventory.txt");
    int choice;

    do
    {
        displayMenu();
        cin>>choice;

        switch(choice)
        {
            case 1:
            {
            cout<<"\n=== Displaying Inventory ===\n";
            inventory.displayInventory();
            inventory.saveData();
            break;
            }

            case 2:
            {
            string name;
            int quantity;
            double initialprice;

            cout << "\nEnter product details:\n";
            cout << "Name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Initial Quantity: ";
            cin >> quantity;
            cout << "Initial Price: ";
            cin >> initialprice;

            Product newProduct(name, quantity, initialprice);
            inventory.addProduct(newProduct);
            std::cout << "Product added successfully! Code: " << newProduct.code << "\n";
            inventory.saveData();
            break;
            }  

            case 3: {
                int productCode, quantityChange;
                cout << "\nEnter product code: ";
                cin >> productCode;

                // Check if the product with the given code exists in stock
                bool productExists = false;
                Product selectedProduct; // To store the selected product
                for (const auto &product : inventory.getProducts()) {
                if (product.code == productCode) {
                    productExists = true;
                    selectedProduct = product;
                    break;
                    }
                }

                if (!productExists){
                cerr << "Error: Product with code " << productCode << " not found in stock. Transaction not recorded.\n";
                break; // Exit the function if the product is not found
                }

                cout << "Enter quantity change (positive for income, negative for outcome): ";
                cin >> quantityChange;

                // Check if quantity + quantityChange is negative
                if (selectedProduct.quantity + quantityChange < 0) {
                    cerr << "\n\nError: Cannot have negative quantity. Transaction not recorded.\n";
                    cout << "Max quantity in stock for product " << selectedProduct.name << " is: " << selectedProduct.quantity << endl;
                    break;
                }

                // Now that we know quantity + quantityChange is not negative, proceed to ask for the price
                int unitaryprice;
                if(quantityChange>0){
                cout << "Enter Price: ";
                cin >> unitaryprice;
                }else{
                    unitaryprice = selectedProduct.price;
                }

                inventory.recordTransaction(productCode, quantityChange, unitaryprice);
                cout << "Transaction recorded successfully!\n";
                inventory.saveData();
                break;
                }
            
            case 4:{
                std::cout << "Saving data and exiting...\n";
                inventory.saveData();
                break;
            }

            default:
                std::cout << "Invalid choice. Please enter a number between 1 and 4.\n";
                break;
                 
        }
    }while (choice !=4);

    return 0;
};