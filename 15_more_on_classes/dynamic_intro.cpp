#include <iostream>

int main(int argc, char const *argv[])
{
    // int *ptr { new int};
    // int *ptr1 {new int (5)}; // use direct initialization
    // int *ptr2 {new int { 6} }; //use uniform initialization 

int *value { new (std::nothrow) int }; //value will be set to a null pointer if the integer allocation fails



//    int* ptr{ new int }; // dynamically allocate an integer
//     *ptr = 7; // put a value in that memory location

//     delete ptr; // return the memory to the operating system.  ptr is now a dangling pointer.

//     std::cout << *ptr; // Dereferencing a dangling pointer will cause undefined behavior
//     delete ptr; // trying to deallocate the memory again will also lead to undefined behavior.

    int fixedArray[5] = {1, 2, 3, 4, 5}; //initialize a fixed array before C++11
    int *array {new int[5]{1,2, 3, 4, 5}};// initialize a dynamic array since C++11

    int x = 99;
    int *ptr1 = &x;

    int *ptr2 { ptr1};

    std::cout << x << "  " << &x << "  " << ptr1 << " "  << *ptr1 << " " << ptr2 << " " << *ptr2 << std::endl;
    x = 88;
    std::cout << x << "  " << &x << "  " << ptr1 << " "  << *ptr1 << " " << ptr2 << " " << *ptr2 << std::endl;
    *ptr1 = 77;
    std::cout << x << "  " << &x << "  " << ptr1 << " "  << *ptr1 << " " << ptr2 << " " << *ptr2 << std::endl;
    *ptr2 = 66;
    std::cout << x << "  " << &x << "  " << ptr1 << " "  << *ptr1 << " " << ptr2 << " " << *ptr2 << std::endl;

    return 0;
}
