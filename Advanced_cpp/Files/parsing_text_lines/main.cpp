#include    <fstream>
#include    <iostream>
           
using namespace std;
int main() {
    ifstream inFile;
    string inputFileName = "stats.txt";

    inFile.open(inputFileName);
    if(inFile.is_open()) {
        string line;
        while(inFile) {
            getline(inFile, line, ':'); // Read until newline character
            int population;
            inFile >> population; // Read the population value
            cout << "'" << line << "\n --" << population << endl;
        }

        inFile.close();
    }
    else {
        cout << "Error opening file for reading: " << inputFileName << endl;
        return 1;
    }

    return 0;
}