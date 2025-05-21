#include <iostream>
using namespace std;

void mightGoWrong() {

    bool error = true;

    if(error){
        throw "something went wrong";
    }
}

int main() {
    try {
        mightGoWrong();
    } catch (const char* e) {
        cout << "Error: " << e << endl;
    }

    cout << "Program continues..." << endl;

    return 0;
}