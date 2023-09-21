#include <iostream>

int add(int a, int b)
{
    return a + b;
}

double add(double a, double b)
{
    return a + b;
}
int main(int argc, char const *argv[])
{
    int sum = add(1, 2);
    return 0;
}
