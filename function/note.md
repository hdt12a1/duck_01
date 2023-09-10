# Namespace

* The :: symbol is an operator called **scope resolution operator**

* When an identifier inlucdes namespace preix, the identifier is called a **qualied name**

## Using namespace std
* Another way to access identifier inside a namespace is to use a **directive statement**

### const vs constexpr

**Constant Expression**

- A constant expression is an expression that can be evaluated by the
compiler at compile-time.
- To be a constant expression, all the value in the expression must be
known at compile-time ( and all of the operators and functions called must support compile-time evaluation)
- Evaluating constatn expressions at compile-time makes our compilation take longer, but such expression only need to be evaluated once (rather than every time the program is run). The rusulting executables are faster and use less memory.

**Compile-time const**
- A const variable is a compile-time constant if its initializer is a constant expression.

**Runtime const**
- any const variable that is initialized with a non-constant expression is a runtime constant.

**The `**constexpr**` keywork**
- A constexpr variable can only be a compile-time constant. 
- If the initialization value of a constexpr variable is not a constant expression, the compiler will error.

```cpp
#include <iostream>

int five()
{
    return 5;
}

int main()
{
    constexpr double gravity { 9.8 }; // ok: 9.8 is a constant expression
    constexpr int sum { 4 + 5 };      // ok: 4 + 5 is a constant expression
    constexpr int something { sum };  // ok: sum is a constant expression

    std::cout << "Enter your age: ";
    int age{};
    std::cin >> age;

    constexpr int myAge { age };      // compile error: age is not a constant expression
    constexpr int f { five() };       // compile error: return value of five() is not a constant expression

    return 0;
}
```

> [!NOTE]
> Any variable that should not be modification after initlization and whose initlization is known at the compile-time shoud be declare as **constexpr**
> Any variable that should not be modification after initlization and whose initlizer is not known at compile-time should be declared as **const** 


> [!IMPORTANT]
> Because long literals can be hard to read, C++14 also adds the ability to use a quotation mark (') as a digit separator

```cpp
#include <iostream>

int main()
{
    int bin { 0b1011'0010 };  // assign binary 1011 0010 to the variable
    long value { 2'132'673'462 }; // much easier to read than 2132673462
/* int bin { 0b'1011'0010 };  // error: ' used before first digit of value */
    return 0;
}
```

### Consteval
- C++ 20 introduces the keyword consteval, which is used to indicate that a funciton must evaluate at compile-time, otherwise a compile error will result.

```cpp
#include <iostream>

consteval int greater(int x, int y) // function is now consteval
{
    return (x > y ? x : y);
}

int main()
{
    constexpr int g { greater(5, 6) };              // ok: will evaluate at compile-time
    std::cout << g << '\n';

    std::cout << greater(5, 6) << " is greater!\n"; // ok: will evaluate at compile-time

    int x{ 5 }; // not constexpr
    std::cout << greater(x, 6) << " is greater!\n"; // error: consteval functions must evaluate at compile-time

    return 0;
}
```

### Unnamed (anonymous) namespaces
* An unnamed namespace is a namespace that is defined without a name

```cpp
#include <iostream>

namespace // unnamed namespace
{
    void doSomething() // can only be accessed in this file
    {
        std::cout << "v1\n";
    }
}

int main()
{
    doSomething(); // we can call doSomething() without a namespace prefix

    return 0;
}
```

### inline namespace
* An inline namespace is a namespace that is typically used to version content.
* Anything declared inside an inline namespace is considered part of the parent namespace. However, unlike unnamed namespace, inline namespace don't effect linkage.

```cpp
#include <iostream>

inline namespace V1 // declare an inline namespace named V1
{
    void doSomething()
    {
        std::cout << "V1\n";
    }
}

namespace V2 // declare a normal namespace named V2
{
    void doSomething()
    {
        std::cout << "V2\n";
    }
}

int main()
{
    V1::doSomething(); // calls the V1 version of doSomething()
    V2::doSomething(); // calls the V2 version of doSomething()

    doSomething(); // calls the inline version of doSomething() (which is V1)

    return 0;
}

```