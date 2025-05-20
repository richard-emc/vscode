#include <iostream>
using namespace std;

class CanGoWrong {
public:
    CanGoWrong() {
        char *pMemory = new char[99999999999999];
        delete[] pMemory;
    }
};
int main() {
    try {
        CanGoWrong obj;
    } catch (bad_alloc &e) {
        cout << "Memory allocation failed: " << e.what() << endl;
    }

    cout << "Program continues..." << endl;

    return 0;
};

