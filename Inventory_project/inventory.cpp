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

int Product::nextCode = 1;

Product::Product():
     code(0),name(""),quantity(0),price(0.0) {
    recordTransaction(0, 0, 0);
}

Product::Product(string name, int quantity, double pprice):
    code(nextCode++), name(name), quantity(quantity), price(pprice){
        recordTransaction(code, 0, pprice);
    }

void Product::display() const
{
    // Display header
     cout << setw(10) << "Code" << setw(20) << "Name" << setw(15) << "Quantity" << setw(15) << "Price" << '\n'; 

    // Display each product
    cout << setw(10) << code << setw(20) << name << setw(15) << quantity << setw(15) << price << '\n';
}

void Product::recordTransaction(int productCode, int quantityChange, int unityprice)
{
    auto now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    string timestamp = ctime(&now);
{
    transactionHistory.emplace_back(productCode, timestamp, quantityChange);
    quantity += quantityChange;
    price = unityprice;

    if(!transactionHistory.empty())
    {
        price= unityprice;
    }

    }
};

void Product::saveTransactionToFile() const{
    ofstream transactionFile(name + "_transactions.txt", ios::app);
    if (transactionFile.is_open()) 
    {
        if (!transactionHistory.empty()) 
        {
            //transactionFile << "Product Code: " << transactionHistory.back().productCode;
            transactionFile << "Quantity Change: " << transactionHistory.back().quantityChange;
            transactionFile << ", Total Quantity: " << quantity;
            transactionFile << ", Updated Price: " << price;
            transactionFile << ", Timestamp: " << transactionHistory.back().timestamp;
        }
    transactionFile.close();
    } 
    else 
    {
    std::cerr << "Error opening file to save transaction data." << std::endl;
    }
}

Inventory::Inventory(string fileName) : file(fileName)
{
    loadData();
}

void Inventory::addProduct(const Product& product)
{
    products.push_back(product);
}

void Inventory::displayInventory() const
{
    // Display header
     cout << setw(10) << "Code" << setw(20) << "Name" << setw(15) << "Quantity" << setw(15) << "Price" << '\n'; 
    
    for (const auto &product : products)
    {
        cout << setw(10) << product.code << setw(20) << product.name << setw(15) << product.quantity << setw(15) << product.price << '\n';
    }
}

void Inventory::saveData() const
{
    ofstream outputFile(file);
    if(outputFile.is_open())
    {
        for(const auto& product : products)
        {
            // Use quotes to encapsulate the product name to handle spaces
            outputFile << product.code << " \"" << product.name << "\" " << product.quantity << " " << product.price << endl;
        }
        outputFile.close();
    }
    else 
    {
        cerr << "Error opening file to save data." << endl;
    }
}

void Inventory::recordTransaction(int productCode, int quantityChange, int unitaryprice)
{
    for( auto& product:products)
    {
        if(product.code == productCode)
        {
            product.recordTransaction(productCode, quantityChange, unitaryprice);
            product.saveTransactionToFile();
            break;
        }
    }
}

void Inventory::loadData()
{
    ifstream inputFile(file);
    if(inputFile.is_open())
    {
        int productCode;
        string productName;
        int productQuantity;
        double productPrice;

 while (inputFile >> productCode)
{
    // Read the product name considering quotes
    inputFile >> std::quoted(productName);
    inputFile >> productQuantity >> productPrice;

    Product product(productName, productQuantity, productPrice);
    product.code = productCode;
    products.push_back(product);
}
        inputFile.close();

        int maxCode = 0;
        for (const auto& product : products)
        {
            if (product.code > maxCode)
            {
                maxCode = product.code;
            }
        }
        Product::nextCode = maxCode + 1;
    }
    else
    {
        cerr << "Inventory file not found. Creating a new inventory." << endl;
        Product::nextCode = 1;
    }
}

