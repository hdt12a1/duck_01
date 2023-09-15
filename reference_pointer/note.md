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

# Lvalue references to const

## Lvalue reference to const
* Lvalue references to const can bind to non-modifiable lvalue:

```cpp
#include <iostream>

int main()
{
    const int x { 5 };    // x is a non-modifiable lvalue
    const int& ref { x }; // okay: ref is a an lvalue reference to a const value

    std::cout << ref << '\n'; // okay: we can access the const object
    ref = 6;                  // error: we can not modify an object through a const reference

    return 0;
}
```

## Initializing an lvalue reference to const with a modifiable lvalue.
* Lvalue references to const can also bind to modifialbe lvalues. 
* In such case, the object being referenced is treated as const when accessed through the referece.


```cpp
#include <iostream>

int main()
{
    int x { 5 };          // x is a modifiable lvalue
    const int& ref { x }; // okay: we can bind a const reference to a modifiable lvalue

    std::cout << ref << '\n'; // okay: we can access the object through our const reference
    ref = 7;                  // error: we can not modify an object through a const reference

    x = 6;                // okay: x is a modifiable lvalue, we can still modify it through the original identifier

    return 0;
}

```

## Initializing an lvalue reference to const with an rvalue

```cpp
#include <iostream>

int main()
{
    const int& ref { 5 }; // okay: 5 is an rvalue

    std::cout << ref << '\n'; // prints 5

    return 0;
}
```

**A temporary object is an object that is created for temporay use within a single expression.**
* Temporay objects have no scope at all. This means a temporary object can only be used directly at the point where it is created, since there is no way to refer to it beyond that point.

> [!IMPORTANT]
> When a const lvalue reference is bound to a temporary objet, the lifetime of the temporary object is extended to match the lifetime of the reference.

```cpp
#include <iostream>

int main()
{
    const int& ref { 5 }; // The temporary object holding value 5 has its lifetime extended to match ref

    std::cout << ref << '\n'; // Therefore, we can safely use it here

    return 0;
} // Both ref and the temporary object die here

```

> [!NOTE]
> lvalue references can only bind to modifiable lvalues
> lvalue references to const can bind to modificable lvalues, non-modifialbe value and rvalue

## constexpr lvalue references
* constexpr references have a particular limitation: They can only be bound to object with static duration
* A constexpr reference cannot bind to a (non-static) local variable. This is because the address of local variables is not known until the function they are defined within is actually called.


```cpp
int g_x { 5 };

int main()
{
    [[maybe_unused]] constexpr int& ref1 { g_x }; // ok, can bind to global

    static int s_x { 6 };
    [[maybe_unused]] constexpr int& ref2 { s_x }; // ok, can bind to static local

    int x { 6 };
    [[maybe_unused]] constexpr int& ref3 { x }; // compile error: can't bind to non-static object

    return 0;
}

```

> [!NOTE]
> When defining a constexpr reference to const variable, we need to apply both **constexpr** and const

# Pass by lvalue reference

## Some objects are expensive to copy

* Most of the type provied by the standard library are **class type**
* Class type are usually expensive to copy.

## Pass by value
* one way to avoud making an expensive copy of an argument when calling a function is to use **pass by reference** instead of **pass by value**

```cpp
#include <iostream>
#include <string>

void printValue(std::string& y) // type changed to std::string&
{
    std::cout << y << '\n';
} // y is destroyed here

int main()
{
    std::string x { "Hello, world!" };

    printValue(x); // x is now passed by reference into reference parameter y (inexpensive)

    return 0;
}
```

> [!IMPORTANT]
> Passy b reference allows us to pass arguments to a funciton without making copies  of those arguments each time the function is called.

## Pass by reference allows us to change the value of an argument
```cpp
#include <iostream>

void addOne(int& y) // y is bound to the actual object x
{
    ++y; // this modifies the actual object x
}

int main()
{
    int x { 5 };

    std::cout << "value = " << x << '\n';

    addOne(x);

    std::cout << "value = " << x << '\n'; // x has been modified

    return 0;
}
```

## Pass by reference can oly accept modifiable lvalue arguments
```cpp
#include <iostream>

void printValue(int& y) // y only accepts modifiable lvalues
{
    std::cout << y << '\n';
}

int main()
{
    int x { 5 };
    printValue(x); // ok: x is a modifiable lvalue

    const int z { 5 };
    printValue(z); // error: z is a non-modifiable lvalue

    printValue(5); // error: 5 is an rvalue

    return 0;
}

```

# Pass by const lvalue reference
```cpp
#include <iostream>

void printValue(const int& y) // y is now a const reference
{
    std::cout << y << '\n';
}

int main()
{
    int x { 5 };
    printValue(x); // ok: x is a modifiable lvalue

    const int z { 5 };
    printValue(z); // ok: z is a non-modifiable lvalue

    printValue(5); // ok: 5 is a literal rvalue

    return 0;
}
```

## Mixing pass by value and pass by reference
```cpp
#include <string>

void foo(int a, int& b, const std::string& c)
{
}

int main()
{
    int x { 5 };
    const std::string s { "Hello, world!" };

    foo(5, x, s);

    return 0;
}
```

## When to pass by (const) reference

## The cost of pass by value vs pass by reference


