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