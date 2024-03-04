#ifndef _MACHINE_H_
#define _MACHINE_H_
#include <iostream>
#include <vector>
#include <fstream>
#include <string>



class Product{
    string name;
    double price;
    string category;

    Product(string productName, double productPrice, string productCategory)
    {
        name = productName;
        price = productPrice;
        category = productCategory;

    }


};

class Machine{
    int machineID;
    string name;
    string projectNumber;
    vector<Product> products;

    public:
    Machine(int id, string machineName, string projectNum,):
    machineID(id), name(machineName), projectNumber(projectNum){}

};


#endif //_MACHINE_H_