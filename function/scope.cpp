#include <iostream>
auto someFcn(bool b)
{
    if (b)
        return 5; // return type int
    else
        return 6; // return type double
}
int main(int argc, char const *argv[])
{
    int n = 10;

    {
        int n = 100;
        std::cout << "Number inside block:: " << n << std::endl;
    }

    std::cout << n << std::endl;
    auto x = 20;
    return 0;
}
