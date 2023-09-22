#include <array>
#include <iostream>

int main()
{
    std::array<int, 5> prime{ 2, 3, 5, 7, 11 };

    std::cout << std::get<3>(prime); // print the value of element with index 3
    std::cout << std::get<2>(prime); // invalid index (compile error)

    return 0;
}