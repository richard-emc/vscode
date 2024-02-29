#ifndef INVENTORY_H
#define INVENTORY_H


#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


class Transaction 
{
    public:
    string timestamp;
    int quantityChange;

    Transaction(string time, int change):timestamp(time), quantityChange(change){}
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
        
        Product(string name, int quantity, double price);

        void display() const;

        void recordTransaction(int quantityChange, int unityprice);

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

    private:
        void loadData();
};
#endif // INVENTORY_H