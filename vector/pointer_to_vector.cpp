#include <iostream>
#include <vector>

void foo(std::vector<int>& a)
{
    a.at(0) = 999;
    std::cout << a.at(0) << a.at(1) << a.at(2) << std::endl;
    // expected result is "123"
}

int main()
{
    std::vector<int> a;
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);

    foo(a);

    std::cout << "After modify: value at 0 index = " << a.at(0) << std::endl;

    std::cout << "The size " << a.size() << std::endl;
    return 0;
}