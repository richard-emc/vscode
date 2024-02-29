#include "inventory.h"
#include <chrono>
#include <ctime>
#include <iostream>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>

int Product::nextCode = 1;

Product::Product(string name, int quantity, double pprice):
    code(nextCode++), name(name), quantity(quantity), price(pprice){
        recordTransaction(0, pprice);
    }

void Product::display() const
{
    cout<<"Code: "<<code<<endl;
    cout<<"Name: "<<name<<endl;
    cout<<"QUantity: "<<quantity<<endl;
    cout<<"Price: "<<price<<endl;
}

void Product::recordTransaction(int quantityChange, int unityprice)
{
    auto now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    string timestamp = ctime(&now);

    transactionHistory.emplace_back(timestamp, quantityChange);
    quantity += quantityChange;
    price = unityprice;

    if(!transactionHistory.empty())
    {
        price= unityprice;

    }
};

void Product::saveTransactionToFile() const{
    ofstream transactionFile(name + "_transactions.txt", ios::app);
    if (transactionFile.is_open()) 
    {
        if (!transactionHistory.empty()) 
        {
            transactionFile << "Timestamp: " << transactionHistory.back().timestamp;
            transactionFile << ", Quantity Change: " << transactionHistory.back().quantityChange;
            transactionFile << ", Updated Price: " << price << std::endl;
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
    for(const auto& product:products)
    {
        product.display();
    }
}

void Inventory::saveData() const
{
    ofstream outputFile(file);
    if(outputFile.is_open())
    {
        for(const auto& product : products)
        {
            outputFile<<product.code<<" "<<product.name<<" "<<product.quantity<<" "<<product.price<<endl;
        }
        outputFile.close();
    }else 
    {
        cerr<<"error opening file to save data."<<endl;
    }
}

void Inventory::recordTransaction(int productCode, int quantityChange, int unitaryprice)
{
    for( auto& product:products)
    {
        if(product.code == productCode)
        {
            product.recordTransaction(quantityChange, unitaryprice);
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

        while (inputFile>>productCode>>productName>>productQuantity>>productPrice)
        {
            Product product(productName, productQuantity, productPrice);
            product.code = productCode;
            products.push_back(product);
        }

        inputFile.close();

        int maxCode = 0;
        for (const auto& product:products)
        {
            if (product.code > maxCode)
            {
                maxCode = product.code;
            }
        }
        Product::nextCode = maxCode +1;
    }else
    {
        cerr<<"Inventory file not found. Creating a new inventory. "<<endl;
        Product::nextCode = 1;
    }

}