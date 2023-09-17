#include <iostream>
#include <vector>

// Write your printElement function here
template <typename T>
void printElement(const std::vector<T> &v, unsigned int index)
{
    if (index > static_cast<unsigned int>(v.size() - 1))
    {
        // 3 elements: -> size = 3, index 0->2.
        std::cout << "Invalid index" << std::endl;
    }
    else
    {
        std::cout << "The element has value " << v[index] << std::endl;
    }
}
int main()
{
    std::vector<int> v1{0, 1, 2, 3, 4};
    printElement(v1, 2);
    printElement(v1, 5);

    std::vector<double> v2{1.1, 2.2, 3.3};
    printElement(v2, 0);
    printElement(v2, -1);

    return 0;
}