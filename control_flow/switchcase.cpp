#include <iostream>

void printDigitName(int x)
{
    switch (x) // x is evaluated to produce value 5
    {
    case 1:
        std::cout << "One";
        
    case 2:
        std::cout << "Two";
       
    default:
        std::cout << "unknown" << std::endl;
       
    case 3:
        std::cout << "Three";
       

    // no matching case exists and there is no default case
    }

    // so execution continues here
    std::cout << "Hello";
}

int main()
{
    double x { 3 }; 

    return 0;
}