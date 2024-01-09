#include "menu.h"
#include <iostream>

using namespace std;

void funcaomenu(){
    int choice;
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
        }
        break;
        case 2/* constant-expression */:{
            cout << "inside switch case b\n";
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