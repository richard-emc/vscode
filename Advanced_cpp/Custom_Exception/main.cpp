#include <iostream> // for std::cout
#include <exception> // for std::exception
#include <cstring>  // for std::strerror
using namespace std;

class MyException : public exception { 
public:
    //MyException(const char* message) : msg(message) {}
    virtual const char* what() const throw() {
        return "Something went wrong!";
       // return msg;
    };
};

class Test {
public:
    void goeswrong() {
        // Simulate an error
        throw MyException();
    }
};


int main() {
    Test test;
    try {
        test.goeswrong();
    } catch (MyException &e) {
        cout << "Caught MyException: " << e.what() << endl;
    } /*catch (exception &e) {
        cout << "Caught exception: " << e.what() << endl;
    }*/

    cout << "Program continues..." << endl;

    return 0;
}