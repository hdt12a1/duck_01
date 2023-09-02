#include <iostream>

template <typename T, typename U>

auto max (T x, U y) -> auto
{
    return (x > y) ? x : y;
}


int main(int argc, char const *argv[])
{
    std::cout << max(1, 2.1) << '\n';
    return 0;
}
