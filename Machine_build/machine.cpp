#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
#include "machine.h"

using namespace std;

void menu(){
    Inventory inventory("inventory.txt");
    int choice;
    displayMenu();
    cin >> choice; 

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
            double price;
            string category;

            cout << "\nEnter product details:\n";
            cout << "Name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Initial Quantity: ";
            cin >> quantity;
            cout << "Initial Price: ";
            cin >> price;
            cout << "product Category";
            cin >> category;

            Product newProduct(name, quantity, price, category);
            inventory.addProduct(newProduct);
            //std::cout << "Product added successfully! Code: " << newProduct.productCode << "\n";
            inventory.recordTransaction(quantity, price);
            inventory.saveData();
            break;
            }  

            /*case 3: {
                int productCode, quantityChange;
                cout << "\nEnter product code: ";
                cin >> productCode;

                // Check if the product with the given code exists in stock
                bool productExists = false;
                Product selectedProduct; // To store the selected product
                for (const auto &product : inventory.getProducts()) {
                if (productCode == productCode) {
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
                    cout << "Max quantity in stock for product " << selectedProduct.productName << " is: " << selectedProduct.quantity << endl;
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
                }*/

            case 4:{
                std::cout << "Saving data and exiting...\n";
                inventory.saveData();
                break;
            }

            default:
                std::cout << "Invalid choice. Please enter a number between 1 and 4.\n";
                break;
              
        }while (choice !=4);
};

void displayMenu()
{
    cout << "\n====== Inventory Menu ======\n";
    cout << "1. Display Inventory\n";
    cout << "2. Create Project\n";
    cout << "3. Create Product\n";
    cout << "4. Add Product to Project\n";
    cout << "5. Record Transaction\n";
    cout << "6. See all registered products\n";
    cout << "=============================\n";
    cout << "Enter your choice (1-4): ";
};

void Product::display() const{
    // Display header
     cout << setw(10) << "Code" << setw(20) << "Name" << setw(15) << "Quantity" << setw(15) << "Price" << '\n'; 

    // Display each product
    cout << setw(10) << productCode << setw(20) << productName << setw(15) << productQuantity << setw(15) << productPrice << '\n';
};

void Inventory::addProduct(const Product& producttoadd){

    inventoryProducts.push_back(producttoadd);
};

void Inventory::displayInventory() const{
    // Display header
     cout << setw(10) << "Code" << setw(20) << "Name" << setw(15) << "Quantity" << setw(15) << "Price" << '\n'; 
    
    for (const auto &product : inventoryProducts)
    {
        cout << setw(10) << product.getproductID() << setw(20) << product.getproductName() << setw(15) << product.getproductQuantity() << setw(15) << product.getproductPrice() << '\n';
    }
}

void Inventory::saveData() const{
    
    ofstream outputFile(inventoryFile);
    if(outputFile.is_open())
    {
        for(const auto& product : inventoryProducts)
        {
            // Use quotes to encapsulate the product name to handle spaces
            outputFile << product.getproductID() << " \"" << product.getproductName() << "\" " << product.getproductQuantity() << " " << product.getproductPrice() << endl;
        }
        outputFile.close();
    }
    else 
    {
        cerr << "Error opening file to save data." << endl;
    }
}