#ifndef INVENTORY_H
#define INVENTORY_H


#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
using namespace std;


class Transaction 
{
    public:
    string timestamp;
    int quantityChange;
    int unitaryprice;
    int productCode;

    Transaction(int productCode, string time, int change):timestamp(time), quantityChange(change), productCode(productCode){}
};

class Product
{
    public:
        static int nextCode;
        int code;
        string name;
        int quantity;
        double price;
        vector<Transaction> transactionHistory;

        Product();
        
        Product(string name, int quantity, double price);

        void display() const;

        void recordTransaction(int productCode, int quantityChange, int unityprice);

        void saveTransactionToFile() const;
};

class Inventory
{
    private:
        vector<Product> products;
        string file;

    public:
        Inventory(string fileName);

        void addProduct(const Product& product);

        void displayInventory() const;

        void saveData() const;

        void recordTransaction(int productCode, int quantityChange, int unitaryprice);

        const std::vector<Product>& getProducts() const {
        return products;
        }

    private:
        void loadData();
};
#endif // INVENTORY_H