#include "inventory.h"
#include <chrono>
#include <ctime>
#include <iostream>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>

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
            break;
            }

            case 2:
            {
            string name;
            int quantity;
            double initialprice;

            cout << "\nEnter product details:\n";
            cout << "Name: ";
            cin >> name;
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
                int productCode, quantityChange, unitaryprice;
                cout << "\nEnter product code: ";
                cin >> productCode;
                cout << "Enter quantity change (positive for income, negative for outcome): ";
                cin >> quantityChange;
                cout << "Enter Price";
                cin >> unitaryprice;

                inventory.recordTransaction(productCode, quantityChange, unitaryprice);
                cout << "Transaction recorded successfully!\n";
                break;
            }
            
            case 4:
                std::cout << "Saving data and exiting...\n";
                inventory.saveData();
                break;

            default:
                std::cout << "Invalid choice. Please enter a number between 1 and 4.\n";
                break;
                 
        }
    }while (choice !=4);

    return 0;
};