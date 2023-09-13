# Operator Overloading C++
- Operator overloading in C++ allows you to define custom behaviors for operators when they are used with user-defined data types, such as classes or structs.
- It lets you redefine how operators work for objects of your custom types by providing special member functions called operator overload functions
- In C++, you can overload various operators, including arithmetic operator (+, -, *, /, etc.), comparison operators (==, !=, <, >, <=, >=), assignment operators (=), and more

```cpp

#include <iostream>

class Complex {
public:
    Complex(double real = 0.0, double imaginary = 0.0) : real(real), imaginary(imaginary) {}

    // Overloading the + operator
    Complex operator+(const Complex& other) {
        return Complex(real + other.real, imaginary + other.imaginary);
    }

    // Overloading the << operator for output
    friend std::ostream& operator<<(std::ostream& os, const Complex& complex) {
        os << complex.real << " + " << complex.imaginary << "i";
        return os;
    }

private:
    double real;
    double imaginary;
};

int main() {
    Complex a(3.0, 4.0);
    Complex b(1.0, 2.0);

    Complex c = a + b; // Calls the overloaded + operator

    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;
    std::cout << "c: " << c << std::endl;

    return 0;
}

```

# `this` keyword
- In C++, the `this` keyword is a pointer that points to the current instance (object) of a class. 
- It is a built-in keyword that allows you to access the members (data members and member functions) of the current object within the context of a member function

## Accessing Member Variables: 
- Inside a member function, you can use `this` to access the member variables of the current object.
- This particularly useful when there is a naming conflict between a paramemter or a local variable and a member variable of the same name

```cpp
class MyClass {
public:
    void SetData(int data) {
        this->data = data; // Use this-> to access the member variable
    }
private:
    int data;
};

```

---

## Returning the Current Object
- You can use `this` to return the current object from a member function, allowing for method chaining (where multiple member functions are called in succession on the same object)

```cpp
class MyClass {
public:
    MyClass& Increment() {
        this->data++;
        return *this; // Return the current object by reference
    }
private:
    int data;
};


```

## Avoiding Ambiguity
- In more complex scenarios, when you have multiple levels of inheritance and virtual function, `this` can be used to clarify which version of a function or variable is being referred to, especially in situation involving base and derived classes

```cpp
class Base {
public:
    virtual void SomeFunction() {
        std::cout << "Base::SomeFunction()" << std::endl;
    }
};

class Derived : public Base {
public:
    void SomeFunction() override {
        std::cout << "Derived::SomeFunction()" << std::endl;
    }

    void CallBaseFunction() {
        Base::SomeFunction(); // Use this to specify the base class version
    }
};


```

# Type deduction with pointer, reference and const
- We also noted that by default, type deduction will drop `const` (and `constexpr`) qualifiers:

```cpp
const double foo()
{
    return 5.6;
}

int main()
{
    const double cd{ 7.8 };

    auto x{ cd };    // double (const dropped)
    auto y{ foo() }; // double (const dropped)

    return 0;
}
```

> [!NOTE]
> Const or constexpr can be applied by adding the const or constexpr qualifier in the definition:

```cpp
const double foo()
{
    return 5.6;
}

int main()
{
    constexpr double cd{ 7.8 };

    const auto x{ foo() };  // const double (const dropped, const reapplied)
    constexpr auto y{ cd }; // constexpr double (constexpr dropped, constexpr reapplied)
    const auto z { cd };    // const double (constexpr dropped, const applied)

    return 0;
}
```

## Type deduction drops references

- In addtion to dropping const qualifiers, type deduction will also drop references:

```cpp
#include <string>

std::string& getRef(); // some function that returns a reference

int main()
{
    auto ref { getRef() }; // type deduced as std::string (not std::string&)

    return 0;
}
```
- You can reapply the reference at the point of definition

```cpp
#include <string>

std::string& getRef(); // some function that returns a reference

int main()
{
    auto ref1 { getRef() };  // std::string (reference dropped)
    auto& ref2 { getRef() }; // std::string& (reference reapplied)

    return 0;
}
```
## Top-level const and low-level const
- A top-level const is a const qualifier that applies to an object itself

```cpp
const int x;    // this const applies to x, so it is top-level
int* const ptr; // this const applies to ptr, so it is top-level
```

- A low-level const is a const qualifier that applies to the object being referenced or pointed to:

```cpp
const int& ref; // this const applies to the object being referenced, so it is low-level
const int* ptr; // this const applies to the object being pointed to, so it is low-level
```

> [!IMPORTANT]
> When we say that type deduction drops const qualifier, it only drop top-level consts. Low-level consts are not dropped. 

## Type deduction and const references
- If the initializer is a reference to const (or constexpr), the reference is dropped first and then any top-level const is dropped from the result

```cpp
#include <string>

const std::string& getConstRef(); // some function that returns a reference to const

int main()
{
    auto ref1{ getConstRef() }; // std::string (reference dropped, then top-level const dropped from result)

    return 0;
}
```

- Reapply

```cpp
#include <string>

const std::string& getConstRef(); // some function that returns a const reference

int main()
{
    auto ref1{ getConstRef() };        // std::string (top-level const and reference dropped)
    const auto ref2{ getConstRef() };  // const std::string (const reapplied, reference dropped)

    auto& ref3{ getConstRef() };       // const std::string& (reference reapplied, low-level const not dropped)
    const auto& ref4{ getConstRef() }; // const std::string& (reference and const reapplied)

    return 0;
}
```

## What about constexpr reference

```cpp
#include <string_view>

constexpr std::string_view hello { "Hello" };

constexpr const std::string_view& getConstRef()
{
    return hello;
}

int main()
{
    auto ref1{ getConstRef() };            // std::string_view (top-level const and reference dropped)
    constexpr auto ref2{ getConstRef() };  // constexpr std::string_view (constexpr reapplied, reference dropped)

    auto& ref3{ getConstRef() };           // const std::string_view& (reference reapplied, low-level const not dropped)
    constexpr auto& ref4{ getConstRef() }; // constexpr const std::string_view& (reference reapplied, low-level const not dropped, constexpr applied)

    return 0;
}
```

## Type deduction and pointers
- Unlike references, type deduction does not drop pointers

```cpp
#include <string>

std::string* getPtr(); // some function that returns a pointer

int main()
{
    auto ptr1{ getPtr() }; // std::string*

    return 0;
}
```

- We can also use an anterisk in conjunction with pointer type deduction

```cpp
#include <string>

std::string* getPtr(); // some function that returns a pointer

int main()
{
    auto ptr1{ getPtr() };  // std::string*
    auto* ptr2{ getPtr() }; // std::string*

    return 0;
}

```


## The difference between auto and auto*

- When we use `auto` with a pointer type initializer, the type deduced for `auto` includes the pointer. So for ptr1 above, the type substituted for auto is std::string*
- When we use auto* with a pointer type initializer, the type deduced for auto does not include the pointer -- the pointer is reapplied afterward after the type is deduced. So for ptr2 above, the type substituted for auto is std::string, and then the pointer is reapplied.

- However, there are a couple of difference between auto and auto* in practice. First, auto* must resolve to a pointer initializer, otherwise a compile error will result:
- 
```cpp
#include <string>

std::string* getPtr(); // some function that returns a pointer

int main()
{
    auto ptr3{ *getPtr() };      // std::string (because we dereferenced getPtr())
    auto* ptr4{ *getPtr() };     // does not compile (initializer not a pointer)

    return 0;
}
```

## Type deduction and const pointers
```cpp
#include <string>

std::string* getPtr(); // some function that returns a pointer

int main()
{
    const auto ptr1{ getPtr() };  // std::string* const
    auto const ptr2 { getPtr() }; // std::string* const

    const auto* ptr3{ getPtr() }; // const std::string*
    auto* const ptr4{ getPtr() }; // std::string* const

    return 0;
}
```

- When we use either auto const or const auto, we’re saying, “make whatever the deduced type is const”. So in the case of ptr1 and ptr2, the deduced type is std::string*, and then const is applied, making the final type std::string* const. This is similar to how const int and int const mean the same thing.
- However, when we use auto*, the order of the const qualifier matters. A const on the left means “make the deduced pointer type a pointer to const”, whereas a const on the right means “make the deduced pointer type a const pointer”. Thus ptr3 ends up as a pointer to const, and ptr4 ends up as a const pointer.


```cpp
#include <string>

const std::string* getConstPtr(); // some function that returns a pointer to a const value

int main()
{
    auto ptr1{ getConstPtr() };  // const std::string*
    auto* ptr2{ getConstPtr() }; // const std::string*

    auto const ptr3{ getConstPtr() };  // const std::string* const
    const auto ptr4{ getConstPtr() };  // const std::string* const

    auto* const ptr5{ getConstPtr() }; // const std::string* const
    const auto* ptr6{ getConstPtr() }; // const std::string*

    const auto const ptr7{ getConstPtr() };  // error: const qualifer can not be applied twice
    const auto* const ptr8{ getConstPtr() }; // const std::string* const

    return 0;
}

```

> [!NOTE]
> If you want a const pointer, reapply the `const` qualifier even when it's not strictly necessary, as it makes your intent clear and helps prevent mistakes