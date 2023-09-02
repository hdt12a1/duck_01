#include <iostream>


int main(int argc, char const *argv[])
{
    std::string hello;
    int number;
    std::cout << "enter your number" << '\n';
    std::cin >> number;
    std::cout << "Enter your string::" << '\n';
    std::getline(std::cin, hello);


    std::cout << "Your string: " << hello;
    std::cout << "Endline";
    return 0;
}
