#include <iostream>
#include <vector>


int main(int argc, char const *argv[])
{
    std::vector<int> arr1 {1, 2, 3, 4, 5};
    std::vector<int> arr2 {arr1};
    std::vector<int> arr3 {arr2};
    
    return 0;
}
