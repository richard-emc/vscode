#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream outFile;

    string outputFileName = "text.txt";

    outFile.open(outputFileName);
    if(outFile.is_open()) {
        outFile << "Hello, World!" << endl;
        outFile << "This is a test file." << endl;
        outFile << "Writing to a text file in C++." << endl;

        outFile.close();
        cout << "Data written to " << outputFileName << endl;
    }
    else {
        cout << "Error opening file for writing" << outputFileName << endl;
        return 1;
    }

    return 0;
}