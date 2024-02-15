#include "../include/menu.h"
#include "../include/inventory.h"
#include <iostream>

using namespace std;

void clearScreen() {
#ifdef _WIN32
    // For Windows
    std::system("cls");
#else
    // For Unix-like systems
    std::system("tput clear || clear");
#endif
}

void funcaomenu(){
    int choice;
    clearScreen();
    std::vector<product> inventory;

    while(true){
    cout << "\nMenu:\n";
    cout << "1. Display Inventory\n";
    cout << "2. Add Product\n";
    cout << "3. Remove Product\n";
    cout << "4. Exit\n";
    cout << "chose your option\n";
    cin >> choice;
    
   if(choice == 4) {
    cout << "exiting the program\n";
    break;
   } 


    switch (choice){
        case 1/* constant-expression */:{
            cout << "inside switch case 1\n";
            displayinventory(inventory);
        }
        break;
        case 2/* constant-expression */:{
            cout << "inside switch case b\n";
            addProduct(inventory);
            }
        break;
        case 3:{
            cout << "inside switch case 3\n";
        };
        default:
            cout << "invalid choice. Please choose another one";
            break;
    };
    };


};

void teste(){
    testeinventory();
    cout << "funcao teste" << endl;
}