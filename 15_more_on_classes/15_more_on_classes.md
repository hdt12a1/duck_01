# 15.1 The hidden "this" pointer and member function chaining.

- When a member function is called, how does the C++ keep track of which obecjt it was called on?

## The hidden `this` pointer
- Inside every member function, the keyword **this** is a const pointer that hold address of the current implicit object

```cpp
#include <iostream>

class Simple
{
private:
    int m_id{};

public:
    Simple(int id)
        : m_id{ id }
    {
    }

    int getID() { return m_id; }
    void setID(int id) { m_id = id; }

    void print() { std::cout << this->m_id; } // use `this` pointer to access the implicit object and operator-> to select member m_id
};

int main()
{
    Simple simple{ 1 };
    simple.setID(2);

    simple.print();

    return 0;
void print() { std::cout << m_id; }       // implicit use of this
void print() { std::cout << this->m_id; } // explicit use of this
}
```

> [!NOTE]
> All non-static member functions have a `this` const pointer that holds the address of the implicit object.

- `this` always points to the object being operated on
- Each member function has a single **this** pointer parameter that point to the implicit object

```cpp
int main()
{
    Simple a{1}; // this = &a inside the Simple constructor
    Simple b{2}; // this = &b inside the Simple constructor
    a.setID(3); // this = &a inside member function setID()
    b.setID(4); // this = &b inside member function setID()

    return 0;
}
```

> [!NOTE]
> Because this is just a function parameter (and not a member), it does not make isntances of your class larger memory-wise.

## Explicitly referencing `this`

```cpp
struct Something
{
    int data{}; // not using m_ prefix because this is a struct

    void setData(int data)
    {
        this->data = data; // this->data is the member, data is the local parameter
    }
};
```

## Returning `*this`
- It can sometimes be useful to have a member function return the implicit object as a return value.
- The primary reason to do this is to allow member functions to be "chained" together, so several member function can be called on the same object in a single expression. This is called function chaining.

```cpp
class Calc
{
private:
    int m_value{};

public:
    Calc& add(int value) { m_value += value; return *this; }
    Calc& sub(int value) { m_value -= value; return *this; }
    Calc& mult(int value) { m_value *= value; return *this; }

    int getValue() { return m_value; }
};

#include <iostream>

int main()
{
    Calc calc{};
    calc.add(5).sub(3).mult(4); // method chaining

    std::cout << calc.getValue() << '\n';

    return 0;
}
```

## Resetting a class back to default state
- The best way to reset a class back to a default state is to create a `reset()` member function, have that function create a new object, and then assign that new object to the current implicit object.

```cpp
#include <iostream>

class Calc
{
private:
    int m_value{};

public:
    Calc& add(int value) { m_value += value; return *this; }
    Calc& sub(int value) { m_value -= value; return *this; }
    Calc& mult(int value) { m_value *= value; return *this; }

    int getValue() { return m_value; }

    void reset() { *this = {}; }
};


int main()
{
    Calc calc{};
    calc.add(5).sub(3).mult(4);

    std::cout << calc.getValue() << '\n'; // prints 8

    calc.reset();

    std::cout << calc.getValue() << '\n'; // prints 0

    return 0;
}
```

# 15.2 Const class object and const member functions

```cpp
const int x;      // compile error: not initialized
const int y{};    // ok: value initialized
const int z{ 5 }; // ok: list initialized
```

- Class object can also be made const by using `const` keyword. Such object must also be initialized at the time of creation

```cpp
// assume Date is a class
const Date date1;                 // ok: default initialized using default constructor
const Date date2{};               // ok: value initialized using default constructor
const Date date3{ 2020, 10, 16 }; // ok: initialized using parameterized constructor
```

## Modifying the data members of const object is disallowed.
## Const object may not call non-const member functions
## Const member functions

```cpp
#include <iostream>

class Something
{
private:
    int m_value{};

public:
    int getValue() const { return m_value ; } // now a const member function
};

int main()
{
    const Something something{}; // something is const

    std::cout << something.getValue(); // ok to call const member function on const object

    return 0;
}
```

> [!IMPORTANT]
> Constructors cannot be made const. This is because constructors need to be able to initialize their member variables, and a const contructor would not be able to do so.

## Const member functions may be called on non-const object
## For const object, `this` is a const pointer to a const value

# Static member variables
- Static member variables are shared by all object of the class.
- Static members exits even if no object of the class have been instantiated.
- Static member are global variables that live inside the scope regiion of the class. 
- Static member definition is not subject to access control: you can define and initialize the value even if it's declared as private in the class