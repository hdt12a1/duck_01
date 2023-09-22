#include <iostream>
class Fraction
{
public:
    Fraction(int numerator, int denominator) : m_numerator(numerator), m_denominator(denominator)
    {
        std::cout << "Default Constructor\n";
    }

    Fraction (const Fraction &f)
    {
        std::cout << "Copy Constructor\n";
        this->m_denominator = f.m_numerator;
        this->m_denominator = f.m_denominator;
    }
    Fraction ()
    {
        std::cout << "Default no argument Constructor\n";
    }
    int getNumerator() const { return m_numerator; }
    int getDenominator() const { return m_denominator; }

    ~Fraction()
    {
        std::cout << "Destructor\n";
    }

    
    Fraction& operator= (const Fraction &f)
    {
        std::cout << "Overload operator\n";
        this->m_numerator = f.m_numerator;
        this->m_denominator = f.m_denominator;
        return *this;
    }

private:
    int m_numerator;
    int m_denominator;
};

Fraction add(const Fraction &a, const Fraction &b)
{
    return Fraction(a.getNumerator() + b.getNumerator(), a.getDenominator() + b.getDenominator());
}

int main()
{
    Fraction a(1, 2);
    Fraction b(3, 4);

    // Fraction result = add(a, b);
    Fraction test;
    test = a;

    return 0;
}
