#include <iostream>

int a;
template <typename T>

void print(T t_ins)
{
    t_ins++;
}


int main(int argc, char const *argv[])
{
    
    std::cout << "Hello Vietnam" << std::endl;
    print(5);
    return 0;
}
