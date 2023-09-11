# Introduction to pointers
- In fact, pointers behave a lot like lvalue references.
- The nice thing about variables it that we don't need to worry about what specific memory addresses are assigned.
- For objects that use more than one byte of memory, address-of will return the memory address of the first byte used by the object.

## The dereference operator (*)
- The dereference operator returns the value at a given memory address as an value

```cpp
#include <iostream>

int main()
{
    int x{ 5 };
    std::cout << x << '\n';  // print the value of variable x
    std::cout << &x << '\n'; // print the memory address of variable x

    std::cout << *(&x) << '\n'; // print the value at the memory address of variable x (parentheses not required, but make it easier to read)

    return 0;
}
```

> [!NOTE]
> The address-of operator (&) and dereference operator (*) work as opposites: Address-of get the address of an object, and dereference gets the object at an address.

## Pointers
* A pointer is an object that hold a memory address as its value.

```cpp
int;  // a normal int
int&; // an lvalue reference to an int value

int*; // a pointer to an int value (holds the address of an integer value)
int main()
{
    int x { 5 };    // normal variable
    int& ref { x }; // a reference to an integer (bound to x)

    int* ptr;       // a pointer to an integer

    return 0;
}
```

> [!NOTE]
> Initializing a pointer with a literal value is disallowed
```cpp
int* ptr{ 5 }; // not okay
int* ptr{ 0x0012FF7C }; // not okay, 0x0012FF7C is treated as an integer literal

```

** There are some other differences between pointers and references worth mentioning: **
- References must be initialized, pointers are not required to be initialized.
- References are not objects, pointer are
- References can not be reseated, pointers can change what they are pointing at.
- References must always be bound to an object, pointers can point to nothing

## The size of pointer
- The size of pointer is dependent upon the architecture the executable is compile.

```cpp
#include <iostream>

int main() // assume a 32-bit application
{
    char* chPtr{};        // chars are 1 byte
    int* iPtr{};          // ints are usually 4 bytes
    long double* ldPtr{}; // long doubles are usually 8 or 12 bytes

    std::cout << sizeof(chPtr) << '\n'; // prints 4
    std::cout << sizeof(iPtr) << '\n';  // prints 4
    std::cout << sizeof(ldPtr) << '\n'; // prints 4

    return 0;
}

```
> [!IMPORTANT]
> The size of the pointer is always the same.
> this is because a pointer is just a memory address
> and number of bits needed to access a memory address is constant.

## Dangling pointers
```cpp
#include <iostream>

int main()
{
    int x{ 5 };
    int* ptr{ &x };

    std::cout << *ptr << '\n'; // valid

    {
        int y{ 6 };
        ptr = &y;

        std::cout << *ptr << '\n'; // valid
    } // y goes out of scope, and ptr is now dangling

    std::cout << *ptr << '\n'; // undefined behavior from dereferencing a dangling pointer

    return 0;
}
```

# Null pointers
- When a pointer i holding a null value, it means the pointer i not pointing at anything.

```cpp
int main()
{
    int* ptr {}; // ptr is now a null pointer, and is not holding an address

    return 0;
}

```

---

## The nullptr keyword