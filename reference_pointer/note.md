### Lvalue references
- In C++, a reference is an alias for an existing object. Once a reference has been defined, any operation on the reference is applied to the object being referenced.

### Lvalue reference types

- To declare an lvalue reference type, we use an ampersand (&) int eh type declaration.






```cpp
int      // a normal int type
int&     // an lvalue reference to an int object
double&  // an lvalue reference to a double object

#include <iostream>

int main()
{
    int x { 5 };    // x is a normal integer variable
    int& ref { x }; // ref is an lvalue reference variable that can now be used as an alias for variable x

    std::cout << x << '\n';  // print the value of x (5)
    std::cout << ref << '\n'; // print the value of x via ref (5)

    return 0;
}

```

> [!NOTE]
> When defining a reference, place the ampersand next to the type (not the reference variable's name)

### Modifying values through an lvalue reference

```cpp

#include <iostream>

int main()
{
    int x { 5 }; // normal integer variable
    int& ref { x }; // ref is now an alias for variable x

    std::cout << x << ref << '\n'; // print 55

    x = 6; // x now has value 6

    std::cout << x << ref << '\n'; // prints 66

    ref = 7; // the object being referenced (x) now has value 7

    std::cout << x << ref << '\n'; // prints 77

    return 0;
}
```

### Initialization of lvalue references
* Much like constants, all references must be initialized.
* When a reference is initialized with an object (or function), we say it is bound to that object.

> [!IMPORTANT]
> Lvalue references must be bound to a modifiable lvalue.