#ifndef _MACHINE_H_
#define _MACHINE_H_

#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <string> // Add this line


class Product{
    std::string name;
    double price;
    std::string category;

    Product(std::string productName, double productPrice, std::string productCategory)
    {
        name = productName;
        price = productPrice;
        category = productCategory;

    }


};

class Machine{
    int machineID;
    std::string name;
    std::string projectNumber;
    std::vector<Product> products;

    public:
    Machine(int id, std::string machineName, std::string projectNum):
    machineID(id), name(machineName), projectNumber(projectNum){}

};


#endif //_MACHINE_H_