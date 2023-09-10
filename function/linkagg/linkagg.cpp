#include <iostream>
#include "a.cpp"
using namespace std;
// Declaring the variable as an extern.
extern constexpr int num = 100;
void increment(); // Or extern void increment().

int main() {
    cout << "Number: " << num << endl;
    // Calling the global function.
    
    increment();
    cout << "Number: " << num << endl;

    return 0;
}
