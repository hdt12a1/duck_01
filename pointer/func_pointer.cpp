#include <iostream>

int add(int a, int b)
{
    return a + b;
}

int main(int argc, char const *argv[])
{
    /* code */

    int (*funcPtr)(int, int) = add;

    std::cout << funcPtr(10, 11);
    return 0;
}
