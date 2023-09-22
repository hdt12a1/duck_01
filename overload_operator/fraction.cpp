#include <iostream>

class Fraction
{
private:
    int numerator{};
    int denominator{1};

public:
    Fraction()
    {
        std::cout << "Default Constructor\n";
    }
    Fraction(int num1, int num2 = 1)
        : numerator{num1}, denominator{num2}
    {
        std::cout << "Constructor\n";
    }
    Fraction(const Fraction &f)
        : numerator{f.numerator}, denominator{f.denominator}
    {
        std::cout << "Copy Constructor\n";
    }
    void print()
    {
        std::cout << numerator << "/" << denominator << std::endl;
    }
    friend Fraction operator*(const Fraction &f1, const Fraction &f2);
    friend Fraction operator*(Fraction f1, int num);
    friend Fraction operator*(int num, Fraction f2);
    friend std::ostream &operator<<(std::ostream &out, const Fraction &f);
    friend std::istream &operator>>(std::istream &in, Fraction &f);
};

Fraction operator*(const Fraction &f1, const Fraction &f2)
{
    int numerator = f1.numerator * f2.numerator;
    int denominator = f2.denominator * f1.denominator;
    Fraction ins{numerator, denominator};
    return ins;
}
Fraction operator*(Fraction f1, int num)
{
    int numerator = f1.numerator * num;
    int denominator = f1.denominator;
    Fraction ins{numerator, denominator};
    return ins;
}
Fraction operator*(int num, Fraction f1)
{
    int numerator = f1.numerator * num;
    int denominator = f1.denominator;
    Fraction ins{numerator, denominator};
    return ins;
}
std::ostream &operator<<(std::ostream &out, const Fraction &f)
{
    out << f.numerator << "/" << f.denominator;
    return out;
}
std::istream &operator>>(std::istream &in, Fraction &f)
{
    char c{};
    in >> f.numerator >> c >> f.denominator;
    return in;
}
int main(int argc, char const *argv[])
{

    /*     Fraction f1{2, 5};
        f1.print();

        Fraction f2{3, 8};
        f2.print();

        Fraction f3{f1 * f2};
        f3.print();

        Fraction f4{f1 * 2};
        f4.print();

        Fraction f5{2 * f2};
        f5.print();
        Fraction f6{ Fraction{1, 2} * Fraction{2, 3} * Fraction{3, 4} };
        f6.print(); */

    Fraction f1;
    std::cout << "Enter fraction 1: ";
    std::cin >> f1;

    Fraction f2;
    std::cout << "Enter fraction 2: ";
    std::cin >> f2;

    std::cout << f1 << " * " << f2 << " is " << f1 * f2 << '\n';
    // note: The result of f1 * f2 is an r-value
    return 0;
}
