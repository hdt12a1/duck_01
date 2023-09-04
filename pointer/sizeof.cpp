#include <iostream>

int main(int argc, char const *argv[])
{
    std::cout << sizeof(int) << std::endl;
    int arr[2] = {11, 22};
    std::cout << "Add of arr" << &arr << std::endl;
    std::cout << "Address" << &arr[0] << std::endl;
    std::cout << "Address" << &arr[1] << std::endl;
    return 0;
}
