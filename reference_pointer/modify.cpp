#include <iostream>

int main(int argc, char const *argv[])
{
    int x{5}; 
    int & ref {x};
    std::cout << x << " " << ref << std::endl;
    x = 10;
    std::cout << x << " " << ref << std::endl;
    ref = 99;
    std::cout << x << " " << ref << std::endl;
    return 0;
}
