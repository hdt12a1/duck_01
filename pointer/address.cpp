#include <iostream>

int main(int argc, char const *argv[])
{
    int numbers[] = {4, 5, 6, 3};
    std::cout << "Sizeof int " << sizeof(int) << std::endl;
    for (int i = 0; i < 4; ++i)
    {
        std::cout << "Address: " << &numbers[i] << " value " << numbers[i]
            << std::endl;
    }
    return 0;
}
