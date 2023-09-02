#include <iostream>


int getTotal(int number[]);
int main(int argc, char const *argv[])
{
    int numbers[] = {1, 2, 3};
    int total = getTotal(numbers);
    std::cout << "total = " << total << '\n';
    return 0;
}


int getTotal(int number[])
{
    int total = 0;
    std::cout << "hello " << '\n';
    total = number[1];

    return total;
}
