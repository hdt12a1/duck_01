#include <iostream>


int main(int argc, char const *argv[])
{
    int* ptr = new int;
    *ptr = 99;
    std::cout << "Addr: " << ptr << " Value: "  << *ptr << std::endl;
    delete ptr;
    std::cout << "Addr: " << ptr << " Value: "  << *ptr << std::endl;
    return 0;
}
