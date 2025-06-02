#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream inFile;

    string inputFileName = "text.txt";

    inFile.open(inputFileName);
    if(inFile.is_open()) {
        string line;
        while(getline(inFile, line)) {
            cout << line << endl;
        }

        inFile.close();
    }
    else {
        cout << "Error opening file for reading: " << inputFileName << endl;
        return 1;
    }

    return 0;
}