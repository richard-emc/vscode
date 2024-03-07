#include <iostream>
#include <vector>
#include <string>
#include "machine.h"

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