#include <iostream>

/*
There are 6 basic ways to initialize variables in C++:
+ int a // no initialzieer (default initialization)
+ int b = 5 // initializer after equals sign (copy initialization)
+ int c(6) // initializer in parenthesis (direct initialization)
// List Initialization methods (C++11) PREFERRED
+ int d { 8 } // initializer in brances (direct list init)
+ int e = {8} copy list init
+ int f{} 
*/

int main(int argc, char const *argv[])
{
    [[maybe_unused]] int x { 5 };

    /* narrowing conversion*/
    // int y = {4.5};
    int y (5.6);

    std::cout << y << std::endl;
    return 0;
}
