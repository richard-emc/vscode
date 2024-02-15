#ifndef _INVENTORY_H_
#define _INVENTORY_H_
#include <iostream>
#include <vector>
#include <string>
#include "menu.h"

using namespace std;

struct product{
    string int_code;
    string description;
    string serial_number;
    double price;
    int quantity;
};
void displayinventory(const vector<product>& inventory);
void addProduct(std::vector<product>& inventory);
void testeinventory();

#endif //_INVENTORY_H_