#ifndef _MACHINE_H_
#define _MACHINE_H_

#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <string> // Add this line

void menu();
void displayMenu();

class Product{
    private:
    static int nextCode;
    int productCode;
    double productQuantity;
    std::string productName;
    double productPrice;
    std::string productCategory;

    public:
    Product(std::string name, double quantity, double price, std::string category)//initializing a product Constructor
    {
        productQuantity = quantity;
        productName = name;
        productPrice = price;
        productCategory = category;
    }

    int getproductID() const{
        return productCode;
    }
    
    string getproductName() const{
        return productName;
    }

    double getproductQuantity() const{
        return productQuantity;
    }

    double getproductPrice() const{
        return productPrice;
    }

    void display() const;

    void recordTransaction(int productCode, int quantityChange, int unityprice);

    void saveTransactionToFile() const;

};

class Machine{
    static int nextID;
    string machineFile;

    int machineID;
    std::string machineName;
    std::string projectNumber;
    std::vector<Product> machineProducts;
    string machinefile;

    public:
    Machine(std::string name, std::string projectNum):
    machineID(nextID++), machineName(name), projectNumber(projectNum){}

    int getMachineID() const{
        return machineID;
    }
    
    string getmachineName() const{
        return machineName;
    }


};

class Inventory{
    private:
    vector<Product> inventoryProducts;
    string inventoryFile;
    void loadData();

    public:
    Inventory(string file);
    void addProduct(const Product& producttoadd);
    void displayInventory() const;
    void saveData() const;
    void recordTransaction(int quantityChange, int unitaryprice);
    const std::vector<Product>& getProducts() const {
        return inventoryProducts;
        }
};

#endif //_MACHINE_H_