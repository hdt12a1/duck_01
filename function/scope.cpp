#include <iostream>

int main(int argc, char const *argv[])
{
    int n = 10;

    {
        int n = 100;
        std::cout << "Number inside block:: " << n << std::endl;
    }

    std::cout << n << std::endl;
    return 0;
}
