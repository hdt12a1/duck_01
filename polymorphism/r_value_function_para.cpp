#include <iostream>

void func(const int &lref)
{
    std::cout << "L-value reference to const: " << lref << std::endl;
    
}

void func(int &&rref)
{
    std::cout << "R-value reference: " << rref << std::endl;
    rref = 100;
    std::cout << "R-value reference: " << rref << std::endl;
}

int main(int argc, char const *argv[])
{
    int x {5};
    func(x);
    func(5);
    int&& ref{99};
    func(ref);
    return 0;
}
