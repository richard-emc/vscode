#include <iostream>
#include <exception>
using namespace std;

void goesWrong() {
    bool error1Detected = true;
    bool error2Detected = false;

    if (error1Detected) {
        throw bad_alloc();
    }
    if (error2Detected) {
        throw exception();
    }
        /* code */
    }
    
int main() {
    try {
        goesWrong();
    } catch(bad_alloc &e){
        cout << "Catching bad_alloc: " << e.what() << '\n';
    } catch(exception &e){
        cout << "Catching exception: " << e.what() << '\n';
    }
    
    return 0;
}