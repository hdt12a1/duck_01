# 14.1 Introduction to object oriented programming

## Procedural Programming
- In produral programming, the forcus is on creating that implement our program logical

## The class invariant problem
- A class invariant is a condition that must be true throughout the lifetime of an object in order for the object to remain in a vaild state
- An ojbect that has a violated class invariant is said to be in an invalid state, and unexpected or undefined behavior may result from futher use of that object

## Introduction to classes
- Just like structs, a class is a program-defined compound type that can have many member variables with different types.
- Defining a class

```cpp
class Employee
{
    int m_id {};
    int m_age {};
    double m_wage {};
}
```

```cpp
#include <iostream>


class Date
{
    public:
        int m_day{};
        int m_month{};
        int m_year{};

        Date(int day, int month, int year)
        {
            this->m_day = day;
            this->m_month = month;
            this->m_year = year;
        }
};

void printDate(const Date& date)
{
    std::cout << date.m_day << '/' << date.m_month 
                << '/' << date.m_year << std::endl;
    
}

int main(int argc, char const *argv[])
{
    Date date { 4, 10, 21};
    printDate(date);

    return 0;
}

```

> [!IMPORTANT]
> Most of the C++ standard library is classes

# Member functions
- In addtion to having member variables, class types (which includes struct, classes, and union) can also have their own functions!
- Function that belong to a class type are called `member functions`

> [!IMPORTANT] 
> Member functions must be declared inside the class type definition, and can be defined inside or outside of the class type definition.

```cpp
// Member function version
#include <iostream>

struct Date
{
    int year {};
    int month {};
    int day {};

    void print() // defines a member function named print
    {
        std::cout << year << '/' << month << '/' << day;
    }
};

int main()
{
    Date today { 2020, 10, 14 }; // aggregate initialize our struct

    today.day = 16; // member variables accessed using member selection operator (.)
    today.print();  // member functions also accessed using member selection operator (.)

    return 0;
}
```

- All (non-static) member function must be called using an object of that class type.

## Member functions and variables can be defined in any order

- With member functions (and member data initializers), we can define our members in any order we like

```cpp
struct Foo
{
    int m_x{ y() };   // okay to call y() here, even though y() isn't defined until later

    void x() { y(); } // okay to call y() here, even though y() isn't defined until later
    int y()  { return 5; }
};

```

> [!NOTE]
> Member functions can be used with both structs and classes

## Public and private members and access specifiers

### Member access
- Each member of a class type has a property called an **access level** that determines who can access that member

> [!NOTE]
> C++ has three different access level: public, private and protected.

## The members of a struct are public by default
- Public members are members of a class type that do not have any restriction on how they can be accessed.
- Public members can be accessed by other members of the same class. 

> [!NOTE]
> The member of a struct are public by default. Public members can be accessed by other members of the class type, and by the public

```cpp
#include <iostream>

struct Date
{
    // struct members are public by default, can be accessed by anyone
    int year {};  // public by default
    int month {}; // public by default
    int day {};   // public by default

    void print()  // public by default
    {
        // public members can be accessed in member functions of the class type
        std::cout << year << '/' << month << '/' << day;
    }
};

// non-member function main is part of "the public"
int main()
{
    Date today { 2020, 10, 14 }; // aggregate initialize our struct

    // public members can be accessed by the public
    today.day = 16; // okay: the day member is public
    today.print();  // okay: the print() member function is public

    return 0;
}
```

## The members of a class are private by default
- Members that have private level are called private members
- Private members are members of a class type that can only be accessed by other members of the same class

```cpp
#include <iostream>

class Date // now a class instead of a struct
{
    // class members are private by default, can only be accessed by other members
    int m_year {};  // private by default
    int m_month {}; // private by default
    int m_day {};   // private by default

    void print() // private by default
    {
        // private members can be accessed in member functions
        std::cout << m_year << '/' << m_month << '/' << m_day;
    }
};

int main()
{
    Date today { 2020, 10, 14 }; // compile error: can no longer use aggregate initialization

    // private members can not be accessed by the public
    today.m_day = 16; // compile error: the m_day member is private
    today.print();    // compile error: the print() member function is private

    return 0;
}
```

## Naming your private member variables
- In C++, it is a common convention to name private data members starting with an "m_" prefix.

## Setting access levels via access specifiers
```cpp
class Date
{
// Any members defined here would default to private

public: // here's our public access specifier

    void print()  // public due to above public: specifier
    {
        // members can access other private members
        std::cout << m_year << '/' << m_month << '/' << m_day;
    }

private: // here's our private access specifier

    int m_year { 2020 };  // private due to above private: specifier
    int m_month { 14 }; // private due to above private: specifier
    int m_day { 10 };   // private due to above private: specifier
};

int main()
{
    Date d{};
    d.print();  // okay, main() allowed to access public members

    return 0;
}
```

## Access level best pratices for struct and classes

# Access function

```cpp
#include <iostream>

class Date
{
private:
    int m_year{ 2020 };
    int m_month{ 10 };
    int m_day{ 14 };

public:
    void print()
    {
        std::cout << m_year << '/' << m_month << '/' << m_day << '\n';
    }
};

int main()
{
    Date d{};  // create a Date object
    d.print(); // print the date

    return 0;
}
```

- Access function is a trivial public member function whose job is to retrieve or change the value of a private member variable.
- Access function come in two flavors: getters and setters

```cpp
#include <iostream>

class Date
{
private:
    int m_year { 2020 };
    int m_month { 10 };
    int m_day { 14 };

public:
    void print()
    {
        std::cout << m_year << '/' << m_month << '/' << m_day << '\n';
    }

    int getYear() { return m_year; }              // getter for year
    void setYear(int year) { m_year = year; }     // setter for year

    int getMonth() { return m_month; }            // getter for month
    void setMonth(int month) { m_month = month; } // setter for month

    int getDay() { return m_day; }                // getter for day
    void setDay(int day) { m_day = day; }         // setter for day
};

int main()
{
    Date d{};
    d.setYear(2021);
    std::cout << "The year is: " << d.getYear() << '\n';

    return 0;
}

```

---

## Getters should be read-only
- Getters should return by value or const reference.
- It is okay to return a (const) reference to a member, because the implicit object (containing the data member) is still valid in the scope of the caller.

## Don't return non-const references to private data members
- Because a reference acts like the obect being reference, a member function that returns a non-const reference provides direct access to that member
```cpp
#include <iostream>

class Foo
{
private:
    int m_value{ 4 }; // private member

public:
    int& value() { return m_value; } // returns a non-const reference (don't do this)
};

int main()
{
    Foo f{};                // f.m_value is initialized to default value 4
    f.value() = 5;          // The equivalent of m_value = 5
    std::cout << f.value(); // prints 5

    return 0;
}
```

---

## Access functions concerns

# Why make data private if we're going to provide access functions to it?

# The benefits of data hiding (encapsulation)
- The interface of a clas type defines how a user of the class type will interact with object of the class type.

## Data hiding (encapsulation)
- Data hiding (information hiding or data abstraction) is a technique used to enforce the separation of interface.

## How to implement data hiding
- First, we ensure the data members of the class type are private
- Second, we ensure the member funcitons are public.

### Data hiding make classes easire to use, and reduces complexity
- To used an encapsulated class, you don't need to know how it is implemented.
### Data hiding allows us to maintain invariants

### Data hiding allows to do better error detection 

### Data hiding makes it possible to change implementation details without breaking existing programs

## Constructors
- A constructor is a special function that is automatically called after a non-aggreagate class type object is created.
- If an accessible matching constructor is found, memory for the object is allocated, and the constructor function is called.
- If no accessible matching constructor can be found, a compilation error will be generated.
- Constructors generally perform two functions:
    - They typically perform initialization of any member variables (via a member initialization list)
    - They perform other setup functions (via statements inthe body of the constructor)

> [!IMPORTANT]
> Constructor must have the same name as the class 
> Constructors have no return type

```cpp
#include <iostream>

class Foo
{
private:
    int m_x {};
    int m_y {};

public:
    Foo(int x, int y) // here's our constructor function that takes two initializers
    {
        std::cout << "Foo(" << x << ", " << y << ") constructed\n";
    }

    void print()
    {
        std::cout << "Foo(" << m_x << ", " << m_y << ")\n";
    }
};

int main()
{
    Foo foo{ 6, 7 }; // calls Foo(int, int) constructor
    foo.print();

    return 0;
}
```

## Constructor implicit conversion of arguments

# 14.8 Constructor member initializer lists

## Member initialization via a member initialization list

```cpp
#include <iostream>

class Foo
{
private:
    int m_x {};
    int m_y {};

public:
    Foo(int x, int y)
        : m_x { x }, m_y { y } // here's our member initialization list
    {
        std::cout << "Foo(" << x << ", " << y << ") constructed\n";
    }

    void print()
    {
        std::cout << "Foo(" << m_x << ", " << m_y << ")\n";
    }
};

int main()
{
    Foo foo{ 6, 7 };
    foo.print();

    return 0;
}
```

- The member initializer list is defined after the constructor paramemters.
- Memeber initializer list formating: freedom to format your member init.

> [!IMPORTANT]
> Members in the member initialzier list should be listed in the order in which they are defined in the class. 

## Member initializer list vs default member initializers
- Member can be initialized in a few different ways:
    - If a member is listed in the member initializer list, that initialization value is used
    - Otherwise, if the member has a default member initializer, that initialization value is used
    - Otherwise, the member is default initialized.

```cpp
#include <iostream>

class Foo
{
private:
    int m_x{};    // default member initializer (will be ignored)
    int m_y{ 2 }; // default member initializer (will be used)
    int m_z;      // no initializer

public:
    Foo(int x)
        : m_x{ x } // member initializer list
    {
        std::cout << "Foo constructed\n";
    }

    void print()
    {
        std::cout << "Foo(" << m_x << ", " << m_y << ", " << m_z << ")\n";
    }
};

int main()
{
    Foo foo{ 6 };
    foo.print();

    return 0;
}
```

## Constructor functrion bodies
- The bodies of constructors functions are most often left empty.


## Default constructor
- A default constructor is a constructor that accepts no arguments. Typically, this is a constructor that has been defined with no parameter.

```cpp
#include <iostream>

class Foo
{
public:
    Foo() // default constructor
    {
        std::cout << "Foo default constructed\n";
    }
};

int main()
{
    Foo foo{}; // No initialization values, calls Foo's default constructor

    return 0;
}
```

## Value initialization vs default initialization for class type

```cpp
Foo foo{}; // value initialization, calls Foo() default constructor
Foo foo2;  // default initialization, calls Foo() default constructor
```

> [!NOTE]
> Prefer value initialization over default initialization for all class types

## Constructor with default arguments
```cpp

#include <iostream>

class Foo
{
private:
    int m_x { };
    int m_y { };

public:
    Foo(int x=0, int y=0) // has default arguments
        : m_x { x }
        , m_y { y }
    {
        std::cout << "Foo(" << x << ", " << y << ") constructed\n";
    }
};

int main()
{
    Foo foo1{};     // calls Foo(int, int) constructor using default arguments
    Foo foo2{6, 7}; // calls Foo(int, int) constructor

    return 0;
}
```

## Overloaded constructors
- Because constructors are functions, they can be overloaded.

```cpp
#include <iostream>

class Foo
{
private:
    int m_x {};
    int m_y {};

public:
    Foo() // default constructor
    {
        std::cout << "Foo constructed\n";
    }

    Foo(int x, int y) // non-default constructor
        : m_x { x }, m_y { y }
    {
        std::cout << "Foo(" << x << ", " << y << ") constructed\n";
    }
};

int main()
{
    Foo foo1{};     // Calls Foo() constructor
    Foo foo2{6, 7}; // Calls Foo(int, int) constructor

    return 0;
}
```

> [!IMPORTANT]
> A class should only have one default constructor.

```cpp
#include <iostream>

class Foo
{
private:
    int m_x {};
    int m_y {};

public:
    Foo() // default constructor
    {
        std::cout << "Foo constructed\n";
    }

    Foo(int x=1, int y=2) // default constructor
        : m_x { x }, m_y { y }
    {
        std::cout << "Foo(" << x << ", " << y << ") constructed\n";
    }
};

int main()
{
    Foo foo{}; // compile error: ambiguous constructor function call

    return 0;
}
```

## An implicit default constructor
- If a non-aggregate class type object has no user-declared constructor, the complier will generate a default contructor. This constructor is called an **implicit default constructor**
```cpp
#include <iostream>

class Foo
{
private:
    int m_x{};
    int m_y{};

    // Note: no constructors declared
};

int main()
{
    Foo foo{};

    return 0;
}
```

## Using `=default` to generate a default constructor
- Incase where we would write a default constructor that is equivalent to the implicitly generated default contructtor, we can instead tell the compiler to generate an implicit default constructor.

```cpp
#include <iostream>

class Foo
{
private:
    int m_x {};
    int m_y {};

public:
    Foo() = default; // generate an implicit default constructor

    Foo(int x, int y)
        : m_x { x }, m_y { y }
    {
        std::cout << "Foo(" << x << ", " << y << ") constructed\n";
    }
};

int main()
{
    Foo foo{}; // calls Foo() default constructor

    return 0;
}
```

## Implicit default constructor vs empty user constructor
- If the class has a user-provided default constructor, the object will be default initialized
- If the class has a default constructor that is not user-provided, the object will be zero-initialized before being default initiazed.

```cpp
#include <iostream>

class User
{
public:
    int a;      // note: no default initialization value
    int b {};

    User() {}; // user-provided empty constructor
};

class Default
{
public:
    int a;      // note: no default initialization value
    int b {};

    Default() = default; // defaulted default constructor
};

class Implicit
{
public:
    int a;      // note: no default initialization value
    int b {};

    // implicit default constructor
};

int main()
{
    User user{}; // default initialized
    std::cout << user.a << ' ' << user.b << '\n';

    Default def{}; // zero initialized, then default initialized
    std::cout << def.a << ' ' << def.b << '\n';

    Implicit imp{}; // zero initialized, then default initialized
    std::cout << imp.a << ' ' << imp.b << '\n';

    return 0;
}
```

## Only create a default constructor when it makes sense

# 14.10 Delegating constructors and default arguments

## Constructors are allowed to call other functions, including other member functions of the class

```cpp
#include <iostream>
#include <string>
#include <string_view>

class Employee
{
private:
    std::string m_name{};
    int m_id{ 0 };

    void printCreated()
    {
        std::cout << "Employee " << m_name << " created\n";
    }

public:
    Employee(std::string_view name)
        : m_name{ name }
    {
        printCreated();
    }

    Employee(std::string_view name, int id)
        : m_name{ name }, m_id{ id }
    {
        printCreated();
    }
};

int main()
{
    Employee e1{ "James" };
    Employee e2{ "Dave", 42 };
}
```

### NOTE

```cpp
#include <iostream>
struct Foo
{
    int x{};
    int y{};

public:
    Foo()
    {
        x = 5;
    }

    Foo(int value): y { value }
    {
        // intent: call Foo() function
        // actual: value initializes nameless temporary Foo (which is then discarded)
        Foo(); // note: this is the equivalent of writing Foo{}
    }
};

int main()
{
    Foo f{ 9 };
    std::cout << f.x << ' ' << f.y; // prints 0 9
}
```

> [!IMPORTANT]
> Constructors should not be called directly from the body of another function.

## Delegating constructors
- Constructors are allowed to delegate (transfer responsibility) initialization to another constructor from the same class type. This process is sometimes called sonstructor chaining and such constructor are call **delegating constructors**
```cpp
#include <iostream>
#include <string>
#include <string_view>

class Employee
{
private:
    std::string m_name{};
    int m_id{ 0 };

public:
    Employee(std::string_view name)
        : Employee(name, 0) // delegate initialization to Employee(std::string_view, int) constructor
    {
    }

    Employee(std::string_view name, int id)
        : m_name(name), m_id{ id } // actually initializes the members
    {
        std::cout << "Employee " << m_name << " created\n";
    }

};

int main()
{
    Employee e1{ "James" };
    Employee e2{ "Dave", 42 };
}
```

> [!NOTE]
> It's possible for one constructor to delegate to another constructor, which delegates back to the first constructor. This forms an infinite loop, and will cause your program to run out of stack space and crash.

## Reducing constructors using default arguments

```cpp
#include <iostream>
#include <string>
#include <string_view>

class Employee
{
private:
    std::string m_name{};
    int m_id{ 0 }; // default member initializer

public:

    Employee(std::string_view name, int id = 0) // default argument for id
        : m_name(name), m_id{ id }
    {
        std::cout << "Employee " << m_name << " created\n";
    }
};

int main()
{
    Employee e1{ "James" };
    Employee e2{ "Dave", 42 };
}
```

## Temporary class objects

**NOTE**: We will use a class here, but everything in this lesson is equally applicable to structs that are initialized usign aggragate.

- A temporary object (sometimes called an anynymous object or an unnamed object) is an object that has no name and exitst ony for duration of a single expression
```cpp
#include <iostream>

class IntPair
{
private:
    int m_x;
    int m_y;
public:
    IntPair(int x, int y)
        : m_x { x }, m_y { y }
    {}
};

void print(IntPair p)
{
    std::cout << "(" << p.x() << ", " << p.y() << ")\n";
}

int main()
{
    // Case 1: Pass variable
    IntPair p { 3, 4 };
    print(p);

    // Case 2: Construct temporary IntPair and pass to function
    print(IntPair { 5, 6 } );

    // Case 3: Implicitly convert { 7, 8 } to a temporary Intpair and pass to function
    print( { 7, 8 } );

    return 0;
}
```

> [!NOTE]
> Temporary objects are crated at the point of definition, and destroyed at the end of the full expression in which they are defined. A full expression is an expression that is not a subexpression.


## Introduction to the copy constructor

```cpp
#include <iostream>

class Fraction
{
private:
    int m_numerator{ 0 };
    int m_denominator{ 1 };

public:
    // Default constructor
    Fraction(int numerator=0, int denominator=1)
        : m_numerator{numerator}, m_denominator{denominator}
    {
    }

    void print()
    {
        std::cout << "Fraction(" << m_numerator << ", " << m_denominator << ")\n";
    }
};

int main()
{
    Fraction f { 5, 3 };  // Calls Fraction(int, int) constructor
    Fraction fCopy { f }; // What constructor is used here?

    f.print();
    fCopy.print();

    return 0;
}
```

- The copy constructor is a constructor that is used to initialize an object with an existing object of the same type.

### An implicit copy constructor

- If you do not provide a copy constructor for your classes, C++ will create a public implicit ocpy constructor for you

### Defining your own copy constructor

```cpp
#include <iostream>

class Fraction
{
private:
    int m_numerator{ 0 };
    int m_denominator{ 1 };

public:
    // Default constructor
    Fraction(int numerator=0, int denominator=1)
        : m_numerator{numerator}, m_denominator{denominator}
    {
    }

    // Copy constructor
    Fraction(const Fraction& fraction)
        // Initialize our members using the corresponding member of the parameter
        : m_numerator{ fraction.m_numerator }
        , m_denominator{ fraction.m_denominator }
    {
        std::cout << "Copy constructor called\n"; // just to prove it works
    }

    void print()
    {
        std::cout << "Fraction(" << m_numerator << ", " << m_denominator << ")\n";
    }
};

int main()
{
    Fraction f { 5, 3 };  // Calls Fraction(int, int) constructor
    Fraction fCopy { f }; // Calls Fraction(const Fraction&) copy constructor

    f.print();
    fCopy.print();

    return 0;
}
```

## Pass by value (and return by value) and the copy constructor

```cpp
#include <iostream>

class Fraction
{
private:
    int m_numerator{ 0 };
    int m_denominator{ 1 };

public:
    // Default constructor
    Fraction(int numerator = 0, int denominator = 1)
        : m_numerator{ numerator }, m_denominator{ denominator }
    {
    }

    // Copy constructor
    Fraction(const Fraction& fraction)
        : m_numerator{ fraction.m_numerator }
        , m_denominator{ fraction.m_denominator }
    {
        std::cout << "Copy constructor called\n";
    }

    void print()
    {
        std::cout << "Fraction(" << m_numerator << ", " << m_denominator << ")\n";
    }
};

void printFraction(Fraction f) // f is pass by value
{
    f.print();
}

Fraction generateFraction(int n, int d)
{
    Fraction f{ n, d };
    return f;
}

int main()
{
    Fraction f{ 5, 3 };

    printFraction(f); // f is copied into the function parameter using copy constructor

    Fraction f2{ generateFraction(1, 2) }; // Fraction is returned using copy constructor

    printFraction(f2); // f is copied into the function parameter using copy constructor

    return 0;
}
```

## Using `= default` to generate a default copy constructor
- If a class has no copy constructor, the compiler will implicity generate one for us, If we prefer, we can explicitly request the compiler create a default copy consttructor for us using `= default`
```cpp
#include <iostream>

class Fraction
{
private:
    int m_numerator{ 0 };
    int m_denominator{ 1 };

public:
    // Default constructor
    Fraction(int numerator=0, int denominator=1)
        : m_numerator{numerator}, m_denominator{denominator}
    {
    }

    // Explicitly request default copy constructor
    Fraction(const Fraction& fraction) = default;

    void print()
    {
        std::cout << "Fraction(" << m_numerator << ", " << m_denominator << ")\n";
    }
};

int main()
{
    Fraction f { 5, 3 };
    Fraction fCopy { f };

    f.print();
    fCopy.print();

    return 0;
}
```

## Using `= delete` to prevent copies

```cpp
#include <iostream>

class Fraction
{
private:
    int m_numerator{ 0 };
    int m_denominator{ 1 };

public:
    // Default constructor
    Fraction(int numerator=0, int denominator=1)
        : m_numerator{numerator}, m_denominator{denominator}
    {
    }

    // Delete the copy constructor so no copies can be made
    Fraction(const Fraction& fraction) = delete;

    void print()
    {
        std::cout << "Fraction(" << m_numerator << ", " << m_denominator << ")\n";
    }
};

int main()
{
    Fraction f { 5, 3 };
    Fraction fCopy { f }; // compile error: copy constructor has been deleted

    return 0;
}
```

> [!IMPORTANT]
> You can also prevent the public from making copies of class object by making the copy constructor private.

# 14.13 Class initialization and copy elision
- We have 6 types of initialization for object with fundatmental data types

```cpp
int a;         // no initializer (default initialization)
int b = 5;     // initializer after equals sign (copy initialization)
int c( 6 );    // initializer in parenthesis (direct initialization)

// List initialization methods (C++11)
int d { 7 };   // initializer in braces (direct list initialization)
int e = { 8 }; // initializer in braces after equals sign (copy list initialization)
int f {};      // initializer is empty braces (value initialization)
```

- All of these initialization types are valid for object with class types

```cpp
#include <iostream>

class Foo
{
public:

    // Default constructor
    Foo()
    {
        std::cout << "Foo()\n";
    }

    // Normal constructor
    Foo(int x)
    {
        std::cout << "Foo(int) " << x << '\n';
    }

    // Copy constructor
    Foo(const Foo&)
    {
        std::cout << "Foo(const Foo&)\n";
    }
};

int main()
{
    // Calls Foo() default constructor
    Foo f1;           // default initialization
    Foo f2{};         // value initialization (preferred)

    // Calls foo(int) normal constructor
    Foo f3 = 3;       // copy initialization (non-explicit constructors only)
    Foo f4(4);        // direct initialization
    Foo f5{ 5 };      // direct list initialization (preferred)
    Foo f6 = { 6 };   // copy list initialization (non-explicit constructors only)

    // Calls foo(const Foo&) copy constructor
    Foo f7 = f3;      // copy initialization
    Foo f8(f3);       // direct initialization
    Foo f9{ f3 };     // direct list initialization (preferred)
    Foo f10 = { f3 }; // copy list initialization

    return 0;
}
```

> [!NOTE]
> List initialization prevents narrowing conversions
> Copy initialization only works with non-explicit constructor
> List initialization prefers list constructors over other constructors.

## Copy elision
- Copy elision is a compiler optimization technique that allows the compiler to remove unncessary copying of object.
- Copy elision in pass by value and return by value

# 14.14 Converting constructors and the explicit keyword
## User-defined conversions
```cpp
#include <iostream>

class Foo
{
private:
    int m_x{};
public:
    Foo(int x)
        : m_x{ x }
    {
    }

    int getX() { return m_x; }
};

void printFoo(Foo f) // has a Foo parameter
{
    std::cout << f.getX();
}

int main()
{
    printFoo(5); // we're supplying an int argument

    return 0;
}
```

- In this version `printFoo` has a `foo` parameter but we're passing in an argument of type `int`. Because these types do not match, the compiler will try to implicity convert int value 5 to a Foo object so the function can be called.

**A constructor that can be used to perform an implicit conversion is called a converting constructor. By default, all constructors are converting constructors**
## The explicit keyword
- We can use the explicit keyword to tell the compiler that a constructor should not be used as a converting constructor.
- Making a constructor `explicit` has two notable consequances
    - An explicit constructor cannot be used to do copy initialization or copy list initialization
    - An explicit constructor cannot be used to do implicit conversions (since this uses copy initialization or copy list initialization)

```cpp
#include <iostream>

class Dollars
{
private:
    int m_dollars{};

public:
    explicit Dollars(int d) // now explicit
        : m_dollars{ d }
    {
    }

    int getDollars() { return m_dollars; }
};

void print(Dollars d)
{
    std::cout << "$" << d.getDollars();
}

int main()
{
    print(5); // compilation error because Dollars(int) is explicit

    return 0;
}
```

## Explicit constructors can be used for direct and list initialization

- An explicit constructor can still be used for direct and direct initialization
```cpp
// Assume Dollars(int) is explicit
int main()
{
    Dollars d1(5); // ok
    Dollars d2{5}; // ok
}
```

## Return by value and explicit constructors
- When we return a value from a functoin, if that value does not match the return type of the function, an implicit conversion will occur.
```cpp
#include <iostream>

class Foo
{
public:
    explicit Foo() // note: explicit (just for sake of example)
    {
    }

    explicit Foo(int x) // note: explicit
    {
    }
};

Foo getFoo()
{
    // explicit Foo() cases
    return Foo{ };   // ok
    return { };      // error: can't implicitly convert initializer list to Foo

    // explicit Foo(int) cases
    return 5;        // error: can't implicitly convert int to Foo
    return Foo{ 5 }; // ok
    return { 5 };    // error: can't implicitly convert initializer list to Foo
}

int main()
{
    return 0;
}
```

## Best practices for use of `explicit`
- Make any constructor that accepts a single argument `explicit` by default. If an implicit conversion between types is both semantically equivalent and performant, you can consider making the constructor non-explicit