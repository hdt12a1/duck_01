#include <iostream>


int number = 10;
int main(int argc, char const *argv[])
{
    int number = 20;
    /* :: for using global scope */
    std::cout << "Number = " << ::number << '\n';


    return 0;
}
