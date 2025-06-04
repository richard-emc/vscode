#include    <iostream>
#include    <fstream>
using namespace std;

#pragma pack(push, 1) // Ensure no padding is added to the struct
struct Person {
    char name[20];
    int age;
    double weight;
};
#pragma pack(pop) // Restore the previous packing alignment

int main() {

    string filename = "test.bin";
    Person Somenone = {"John Doe", 30, 75.5};

    // Writing to a binary file
        ofstream outputFile;
        outputFile.open(filename, ios::binary);
        if (!outputFile) {
            cerr << "Error opening file for writing: " << filename << endl;
            return 1;
        }
        outputFile.write(reinterpret_cast<const char*>(&Somenone), sizeof(Somenone));
        outputFile.close();


    // Reading from a binary file
    {
        Person readPerson = {};
        ifstream inFile(filename, ios::binary);
        if (!inFile) {
            cerr << "Error opening file for reading: " << filename << endl;
            return 1;
        }
        inFile.read(reinterpret_cast<char*>(&readPerson), sizeof(readPerson));

        inFile.close();

        cout << "Name: " << readPerson.name << ", Age: " << readPerson.age << endl;
    }

    return 0;
}