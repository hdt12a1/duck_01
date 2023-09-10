#include <iostream>

int main(int argc, char const *argv[])
{
    int var{100};
    int& ref1{ var };  // an lvalue reference bound to var
    int& ref2{ ref1 }; // an lvalue reference bound to var
    std::cout << var << " " << ref1 << " " << ref2 << std::endl;
    var = 99;
    std::cout << var << " " << ref1 << " " << ref2 << std::endl;
    ref1 = 98;
    std::cout << var << " " << ref1 << " " << ref2 << std::endl;
    ref2 = 97;
    std::cout << var << " " << ref1 << " " << ref2 << std::endl;
    return 0;
}
