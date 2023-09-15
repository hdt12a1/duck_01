#include <iostream>

int main(int argc, char const *argv[])
{
    int x = 10;
    int& ref = x; // Reference declaration and initialization
    int value = ref; // No need to dereference, value is directly accessed

    std::cout << "Value: " << ref << std::endl;
    std::cout << "Address of ref : " << &ref << std::end;
    std::cout << value << std::endl;
    return 0;
}
