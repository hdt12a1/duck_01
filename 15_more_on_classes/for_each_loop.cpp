#include <iostream>
#include <vector>

int main(int argc, char const *argv[])
{
    std::vector<int> fibonacci { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89 };
    for (auto num : fibonacci)
    {
        std::cout << num << std::endl;
    }
    return 0;
}
