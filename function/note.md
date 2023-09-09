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
