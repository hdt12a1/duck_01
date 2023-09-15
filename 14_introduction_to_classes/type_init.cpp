#include <iostream>

class Foo
{

public:
    int x;
    // Default constructor
    Foo()
    {
        std::cout << "Foo() Default Constructor\n";
    }

    // Normal constructor
    Foo(int x)
    {
        this->x = x;
        std::cout << "Foo(int) Normal Constructor" << x << '\n';
    }

    // Copy constructor
    Foo(const Foo&)
    {
        std::cout << "Foo(const Foo&) Copy constructor\n";
    }
};

int main()
{
    // Calls Foo() default constructor
     Foo f1;           // default initialization
    Foo f2{};         // value initialization (preferred)

    // Calls foo(int) normal constructor
    std::cout << f1.x << std::endl;
    std::cout << f2.x << std::endl;
    Foo f3 = 3;       // copy initialization (non-explicit constructors only)
    Foo f4(4);        // direct initialization
    Foo f5{ 5 };      // direct list initialization (preferred)
    Foo f6 = { 6 };   // copy list initialization (non-explicit constructors only) */
    Foo f7 = f3;      // copy initialization
    Foo f8(f3);       // direct initialization
  

    // Calls foo(const Foo&) copy constructor
    
    
    Foo f9{ f3 };     // direct list initialization (preferred)
    Foo f10 = { f3 }; // copy list initialization */

    return 0;
}