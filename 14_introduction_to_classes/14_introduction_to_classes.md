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