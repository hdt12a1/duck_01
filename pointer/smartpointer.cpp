#include <iostream>

#include <memory>

int main(int argc, char const *argv[])
{
    std::unique_ptr<int> unPtr1(new int(24));
    // std::cout << unPtr1 << std::endl;

    std::cout << *unPtr1 << std::endl;


    return 0;
}
