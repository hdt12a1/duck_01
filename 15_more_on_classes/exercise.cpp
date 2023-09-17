/*
Write a program that:
- Asks the user how many names they wish to enter
- Dynamically allocates a std::string array
- Asks the user to enter each name
- Calls std::sort to sort the names
- Prins the sorted list of names
*/
#include <iostream>
#include <string>
#include <algorithm>
int main(int argc, char const *argv[])
{
    /* code */
    int number_names = 0;
    std::cout << "How many names would you like to enter?";
    std::cin >> number_names;
    std::string newline;
    std::getline(std::cin, newline, '\n');
    std::string *array {new std::string[number_names]{} };
    for (int i = 0; i < number_names; ++i)
    {
        std::cout << "Enter name #" << (i+1) << ": ";
        std::cin >> array[i];
    }
    std::cout << "Here is your sorted list: " << std::endl;
    std::sort(array, array + number_names);
    for (int i = 0; i < number_names; ++i)
    {
        std::cout << "Name #" << (i + 1) << ": " << array[i] << std::endl;
    }
    delete[] array;
    return 0;
}
