#include <iostream>

int main(int argc, char const *argv[])
{
    int&& rref {5};
    rref = 10;
    std::cout << rref << "\n";
    return 0;
}
