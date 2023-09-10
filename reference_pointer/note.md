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
> Lvalue references to non-const

```cpp

int main()
{
    int x { 5 };
    int& ref { x }; // valid: lvalue reference bound to a modifiable lvalue

    const int y { 5 };
    int& invalidRef { y };  // invalid: can't bind to a non-modifiable lvalue
    int& invalidRef2 { 0 }; // invalid: can't bind to an rvalue

    return 0;
}
```

- In most cases, the type of the reference must match the type of the referent.
```cpp
int main()
{
    int x { 5 };
    int& ref { x }; // okay: reference to int is bound to int variable

    double y { 6.0 };
    int& invalidRef { y }; // invalid; reference to int cannot bind to double variable
    double& invalidRef2 { x }; // invalid: reference to double cannot bind to int variable

    return 0;
}
```

> [!IMPORTANT]
> lvalue references to **void** are disallowed

### Reference can't be reseated (changed to refer to another object)
* Once initialized, a reference in C++ cannot be **reseated**, meaning it cannot be changed to reference another object.

```cpp

#include <iostream>

int main()
{
    int x { 5 };
    int y { 6 };

    int& ref { x }; // ref is now an alias for x

    ref = y; // assigns 6 (the value of y) to x (the object being referenced by ref)
    // The above line does NOT change ref into a reference to variable y!

    std::cout << x << '\n'; // user is expecting this to print 5

    return 0;
}
```

* when a reference is evaluated in an expression, It resolves to the object it's referencing. 

### Lvalue reference scope and duration
* Reference variables follow the same scoping and duration rules that normal variables do.

### references and referents have independent lifetimes
* A reference can be destroyed before the object it is referencing.
* The object being referenced can be destroyed before the reference.
* when a reference is destroyed before the referent, the referent is not impacted. 

```cpp
#include <iostream>

int main()
{
    int x { 5 };

    {
        int& ref { x };   // ref is a reference to x
        std::cout << ref << '\n'; // prints value of ref (5)
    } // ref is destroyed here -- x is unaware of this

    std::cout << x << '\n'; // prints value of x (5)

    return 0;
} // x destroyed here
```


### Dangling reference

When an object being referenced is destroyed before a reference to it, the reference is left referencing an object that no longer exists. 

### References are not objects
* Referens are not object in C++.
* they can't used anywhere an object is required
    - You can't have a reference to a reference, since an lvalue must reference an identifiable object.

```cpp
#include <iostream>

int main(int argc, char const *argv[])
{
    int var{100};
    int& ref1{ var };  // an lvalue reference bound to var
    int& ref2{ ref1 }; // an lvalue reference bound to var
    std::cout << var << " " << ref1 << " " << ref2 << std::endl;
    var = 99;
    std::cout << var << " " << ref1 << " " << ref2 << std::endl;
    ref1 = 98;
    std::cout << var << " " << ref1 << " " << ref2 << std::endl;
    ref2 = 97;
    std::cout << var << " " << ref1 << " " << ref2 << std::endl;
    return 0;
}
```

> [!NOTE]
> A reference to a reference would have syntax int && - but since C++ 
> doesn't support reference to reference, this syntax was repurposed in C++ 11.
