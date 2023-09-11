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
- the nullptr keyword represents a null pointer literal. we can use nullptr to explicitly initialize or assign a pointer a null value.

```cpp
int main()
{
    int* ptr { nullptr }; // can use nullptr to initialize a pointer to be a null pointer

    int value { 5 };
    int* ptr2 { &value }; // ptr2 is a valid pointer
    ptr2 = nullptr; // Can assign nullptr to make the pointer a null pointer

    someFunction(nullptr); // we can also pass nullptr to a function that has a pointer parameter

    return 0;
}
```

---- 
## Dereferencing a null pointer results in undefined behavior

```cpp
#include <iostream>

int main()
{
    int* ptr {}; // Create a null pointer
    std::cout << *ptr << '\n'; // Dereference the null pointer

    return 0;
}
```

---

## Checking for null pointers

## Use nullptr to avoid dangling pointers
---
# Legacy null pointer literals: 0 and NULL
- In older code, you may see two other literal value used instead of `nullptr`
- the first is the literal 0. In the context of a pointer, the literal `0` is specially defined to mean a null value.

```cpp
int main()
{
    float* ptr { 0 };  // ptr is now a null pointer (for example only, don't do this)

    float* ptr2; // ptr2 is uninitialized
    ptr2 = 0; // ptr2 is now a null pointer (for example only, don't do this)

    return 0;
}
```

> [!NOTE]
> On modern architecture, the address `0` is typically used to represent a null pointer. However, this value is not guaranteed by the c++ standard, and some architecture use other value. the literal 0 when used in the context of a null pointer, will be translated into whatever address the architecture uses to represent a null pointer.
>
> There is a preprocessor macro named NULL

```cpp
#include <cstddef> // for NULL

int main()
{
    double* ptr { NULL }; // ptr is a null pointer

    double* ptr2; // ptr2 is uninitialized
    ptr2 = NULL; // ptr2 is now a null pointer

    return 0;
}
```

> [!IMPORTANT]
> Both `0` and `NULL` should be avoided in modern C++ (used nullptr instead)

> [!NOTE]
> Favor references over pointers unless the additional capabilities provided by pointers are needed.

---


# Pointers and const

## Pointer to const value
- Pointer to const value is a pointer that points to a constant value
- To delcare a pointer to a const value, use the `const` keyword before the pointer's data type

```cpp
int main()
{
    const int x{ 5 };
    const int* ptr { &x }; // okay: ptr is pointing to a "const int"

    *ptr = 6; // not allowed: we can't change a const value

    return 0;
}

```

> [!NOTE]
> Just like a reference to const, a pointer to const can point to non-const variables too.

```cpp
int main()
{
    int x{ 5 }; // non-const
    const int* ptr { &x }; // ptr points to a "const int"

    *ptr = 6;  // not allowed: ptr points to a "const int" so we can't change the value through ptr
    x = 6; // allowed: the value is still non-const when accessed through non-const identifier x

    return 0;
}
```

---

## Const Pointers

- A const pointer is a pointer whose address can not be changed after initialization.
- To delcare a const pointer, use the `const` keyword afer the asterisk in the pointer declaration

```cppp
int main()
{
    int x{ 5 };
    int* const ptr { &x }; // const after the asterisk means this is a const pointer

    return 0;
}
```

---

## Const pointer to a const value

- Finally, it is possible to declare a const pointer to a const value by using the const keyword both before the type and after the asterisk

```cpp
int main()
{
    int value { 5 };
    const int* const ptr { &value }; // a const pointer to a const value

    return 0;
}

```

# Pointer and const recap
- A non-const pointer can be assigned another address to change what it is pointing at
- A const pointer always points to the same address, and this address can not be changed
- A pointer to a non-const value can change the value it is pointing to. These can not point to a const value
- A pointer to a const value treats the value as const when accessed through the pointer.

```cpp
int main()
{
    int v{ 5 };

    int* ptr0 { &v };             // points to an "int" but is not const itself, so this is a normal pointer.
    const int* ptr1 { &v };       // points to a "const int" but is not const itself, so this is a pointer to a const value.
    int* const ptr2 { &v };       // points to an "int" and is const itself, so this is a const pointer (to a non-const value).
    const int* const ptr3 { &v }; // points to an "const int" and is const itself, so this is a const pointer to a const value.

    // if the const is on the left side of the *, the const belongs to the value
    // if the const is on the right side of the *, the const belongs to the pointer

    return 0;
}
```

---

# 9.10 Pass by address

**Recap**: In prior lessons, we have covered two different ways to pass an argument to a function
- Pass by value
- Pass by reference

## Pass by address
- With pass by address, instead of providing an objet as an argument, the caller provides an object's address (via a pointer)
- This pointer is copied into a pointer parameter of the called function


```cpp
#include <iostream>
#include <string>

void printByValue(std::string val) // The function parameter is a copy of str
{
    std::cout << val << '\n'; // print the value via the copy
}

void printByReference(const std::string& ref) // The function parameter is a reference that binds to str
{
    std::cout << ref << '\n'; // print the value via the reference
}

void printByAddress(const std::string* ptr) // The function parameter is a pointer that holds the address of str
{
    std::cout << *ptr << '\n'; // print the value via the dereferenced pointer
}

int main()
{
    std::string str{ "Hello, world!" };

    printByValue(str); // pass str by value, makes a copy of str
    printByReference(str); // pass str by reference, does not make a copy of str
    printByAddress(&str); // pass str by address, does not make a copy of str

    return 0;
}
```

## Pass by address does not make a copy of the object being pointed to
- Just like pass by reference, pass by address is fast, and avoids making a copy of the argument object

---

## Pass by address allows the function to modify the argument's value

```cpp
#include <iostream>

void changeValue(int* ptr) // note: ptr is a pointer to non-const in this example
{
    *ptr = 6; // change the value to 6
}

int main()
{
    int x{ 5 };

    std::cout << "x = " << x << '\n';

    changeValue(&x); // we're passing the address of x to the function

    std::cout << "x = " << x << '\n';

    return 0;
}
```

---

## Prefer pass by (const) reference

```cpp
#include <iostream>

void printByValue(int val) // The function parameter is a copy of the argument
{
    std::cout << val << '\n'; // print the value via the copy
}

void printByReference(const int& ref) // The function parameter is a reference that binds to the argument
{
    std::cout << ref << '\n'; // print the value via the reference
}

void printByAddress(const int* ptr) // The function parameter is a pointer that holds the address of the argument
{
    std::cout << *ptr << '\n'; // print the value via the dereferenced pointer
}

int main()
{
    printByValue(5);     // valid (but makes a copy)
    printByReference(5); // valid (because the parameter is a const reference)
    printByAddress(&5);  // error: can't take address of r-value

    return 0;
}
```

## Pass by address for "optional" argument
- One of the more common uses for pass by address is to allow a function to accept an "option" argument.

```cpp
#include <iostream>
#include <string>

void greet(std::string* name=nullptr)
{
    std::cout << "Hello ";
    std::cout << (name ? *name : "guest") << '\n';
}

int main()
{
    greet(); // we don't know who the user is yet

    std::string joe{ "Joe" };
    greet(&joe); // we know the user is joe

    return 0;
}
```
- However, in many cases, function overloading is a better alternative to achieve the same result

```cpp
#include <iostream>
#include <string>
#include <string_view>

void greet(std::string_view name)
{
    std::cout << "Hello " << name << '\n';
}

void greet()
{
    greet("guest");
}

int main()
{
    greet(); // we don't know who the user is yet

    std::string joe{ "Joe" };
    greet(joe); // we know the user is joe

    return 0;
}
```

> [!NOTE]
> This has a number of advantages: we no longer have to worry about null deferences, and we could pass in a string literal if we wanted

---

## Changing what a pointer parameter points at
- when we pass an address to a function, that address is copied from the argument into the pointer parameter (which is fine, because copying an address is fast)
- Now consider the following program:

```cpp
#include <iostream>

// [[maybe_unused]] gets rid of compiler warnings about ptr2 being set but not used
void nullify([[maybe_unused]] int* ptr2)
{
    ptr2 = nullptr; // Make the function parameter a null pointer
}

int main()
{
    int x{ 5 };
    int* ptr{ &x }; // ptr points to x

    std::cout << "ptr is " << (ptr ? "non-null\n" : "null\n");

    nullify(ptr);

    std::cout << "ptr is " << (ptr ? "non-null\n" : "null\n");
    return 0;
}
```

---
## Pass by address... by reference?
- Just like we can pass a normal variable by reference, we can also pass pointers by reference.

```cpp
#include <iostream>

void nullify(int*& refptr) // refptr is now a reference to a pointer
{
    refptr = nullptr; // Make the function parameter a null pointer
}

int main()
{
    int x{ 5 };
    int* ptr{ &x }; // ptr points to x

    std::cout << "ptr is " << (ptr ? "non-null\n" : "null\n");

    nullify(ptr);

    std::cout << "ptr is " << (ptr ? "non-null\n" : "null\n");
    return 0;
}
```

---
## Why using `0` or `NULL` is no longer prefered
- The literal `0` can be interpreted as either an interger literal, or as a null pointer literal.
- In certain cases, it can be ambiguous which one we intend
- The definition of preprocessor macro `NULL` is not defined by the language standard. It can be defined as 0, 0L, ((void*)0)
- the compiler can figure out which overloaded function you desire by the arguments passed in as part of the function call. when using 0 or null, this can cause problems:

```cpp
#include <iostream>
#include <cstddef> // for NULL

void print(int x) // this function accepts an integer
{
	std::cout << "print(int): " << x << '\n';
}

void print(int* ptr) // this function accepts an integer pointer
{
	std::cout << "print(int*): " << (ptr ? "non-null\n" : "null\n");
}

int main()
{
	int x{ 5 };
	int* ptr{ &x };

	print(ptr);  // always calls print(int*) because ptr has type int* (good)
	print(0);    // always calls print(int) because 0 is an integer literal (hopefully this is what we expected)

	print(NULL); // this statement could do any of the following:
	// call print(int) (Visual Studio does this)
	// call print(int*)
	// result in an ambiguous function call compilation error (gcc and Clang do this)

	print(nullptr); // always calls print(int*)

	return 0;
}
```

> [!IMPORTANT]
> Using `nullptr` removes this ambiguity (it will always call print(int*)), since nullptr will only match a pointer type

## std::nullptr_t 
- Since `nullptr` ca be differentiated from integer value in function overloads, it must have a different type.
- nullptr has type `std::nullptr_t`, this type can only hod one value : nullptr.
- It's useful in one situation
- If we want to write a function that accepts only anullptr literal argument, we can make the parameter a std::nullptr_t

```cpp
#include <iostream>
#include <cstddef> // for std::nullptr_t

void print(std::nullptr_t)
{
    std::cout << "in print(std::nullptr_t)\n";
}

void print(int*)
{
    std::cout << "in print(int*)\n";
}

int main()
{
    print(nullptr); // calls print(std::nullptr_t)

    int x { 5 };
    int* ptr { &x };

    print(ptr); // calls print(int*)

    ptr = nullptr;
    print(ptr); // calls print(int*) (since ptr has type int*)

    return 0;
}
```

- In the above example, the functionn call `print(nullptr)` resolves to the function `print(std::nullptr_t)` over print(int*) becauise it doesn't require a conversion

---

# Return by reference and return by address

## Return by reference
- Return by reference returns a reference that is obund to the object being returned, which avoids making a copy of the return value.

```cpp
std::string&       returnByReference(); // returns a reference to an existing std::string (cheap)
const std::string& returnByReferenceToConst(); // returns a const reference to an existing std::string (cheap)


#include <iostream>
#include <string>

const std::string& getProgramName() // returns a const reference
{
    static const std::string s_programName { "Calculator" }; // has static duration, destroyed at end of program

    return s_programName;
}

int main()
{
    std::cout << "This program is named " << getProgramName();

    return 0;
}
```


## The object being returned by referece must exist after the function returns

## The lifetime extension doesn't work across function boundaries
- Let's take a look at an example where we return a temporaty by reference

```cpp

#include <iostream>

const int& returnByConstReference()
{
    return 5; // returns const reference to temporary object
}

int main()
{
    const int& ref { returnByConstReference() };

    std::cout << ref; // undefined behavior

    return 0;
}
```

## Don't return non-const local static variable by reference
```cpp
#include <iostream>
#include <string>

const int& getNextId()
{
    static int s_x{ 0 }; // note: variable is non-const
    ++s_x; // generate the next id
    return s_x; // and return a reference to it
}

int main()
{
    const int& id1 { getNextId() }; // id1 is a reference
    const int& id2 { getNextId() }; // id2 is a reference

    std::cout << id1 << id2 << '\n'; // 2 2

    return 0;
}

```

## Assigning/init a normal variable with a returned reference makes a copy
- If a function returns a reference, and that reference is used to initlize or assign to a non-reference variable, the return value will be copied.

```cpp
#include <iostream>
#include <string>

const int& getNextId()
{
    static int s_x{ 0 };
    ++s_x;
    return s_x;
}

int main()
{
    const int id1 { getNextId() }; // id1 is a normal variable now and receives a copy of the value returned by reference from getNextId()
    const int id2 { getNextId() }; // id2 is a normal variable now and receives a copy of the value returned by reference from getNextId()

    std::cout << id1 << id2 << '\n';

    return 0;
}
```

## It's okay to return reference parameters by reference
- If a parameter is passed into a function by reference, it's fate to return that parameter by reference. This make sense: in order to pass an argument to a function, the argument must exits in the scope of the called. when the called funciton returns, that object must still exist in the scope of the caller

```cpp
#include <iostream>
#include <string>

// Takes two std::string objects, returns the one that comes first alphabetically
const std::string& firstAlphabetical(const std::string& a, const std::string& b)
{
	return (a < b) ? a : b; // We can use operator< on std::string to determine which comes first alphabetically
}

int main()
{
	std::string hello { "Hello" };
	std::string world { "World" };

	std::cout << firstAlphabetical(hello, world) << '\n';

	return 0;
}

```

---

## The caller can mofigy values through the reference
- when an argument is passed to a function by non-const reference, the function can use the reference to mofigy the value of the argument

```cpp

#include <iostream>

// takes two integers by non-const reference, and returns the greater by reference
int& max(int& x, int& y)
{
    return (x > y) ? x : y;
}

int main()
{
    int a{ 5 };
    int b{ 6 };

    max(a, b) = 7; // sets the greater of a or b to 7

    std::cout << a << b << '\n';

    return 0;
}
```

## Return by address
- The major advantage of return by address over return by reference is that we can have the function return `nullptr` if there is no valid object return.
- The major disavantage of return by address is that the caller has to remember to do a `nullptr` check before dereferecing the return value