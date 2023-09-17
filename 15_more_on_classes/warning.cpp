#include <iostream>
#include <vector>

template <typename T>
void printArray(const std::vector<T> &arr)
{
    // for(typename std::vector<T>::size_type index {0}; index < arr.size(); ++index)
    // {
    //     std::cout << arr[index] << ' ';
    // }

    /*
    A more concise and general solution is ot have the compiler fetch the type of the
    array type object for us. To do so, we can use the "decltype" keyword
    which returns the type of its parameters
    */
    for (decltype(arr)::size_type index{0}; index < arr.size(); ++index) // decltype(arr) resolves to std::vector<int>
    {
        std::cout << arr[index] << ' ';
    }
}

int main(int argc, char const *argv[])
{
    std::vector<int> arr{9, 7, 5, 3, 1};
    printArray(arr);
    return 0;
}
