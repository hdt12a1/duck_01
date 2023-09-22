#include <cassert>
#include <iostream>

class Fraction
{
private:
	int m_numerator { 0 };
	int m_denominator { 1 };

public:
	// Default constructor
	Fraction(int numerator = 0, int denominator = 1 )
		: m_numerator { numerator }, m_denominator { denominator }
	{
        std::cout << "Default Constructor\n";
		assert(denominator != 0);
	}

	// Copy constructor
	Fraction(const Fraction& copy)
		: m_numerator { copy.m_numerator }, m_denominator { copy.m_denominator }
	{
		// no need to check for a denominator of 0 here since copy must already be a valid Fraction
		std::cout << "Copy constructor called\n"; // just to prove it works
	}

	// Overloaded assignment
	Fraction& operator= (const Fraction& fraction);

	friend std::ostream& operator<<(std::ostream& out, const Fraction& f1);

};

std::ostream& operator<<(std::ostream& out, const Fraction& f1)
{
	out << f1.m_numerator << '/' << f1.m_denominator << std::endl;
	return out;
}

// A simplistic implementation of operator= (see better implementation below)
Fraction& Fraction::operator= (const Fraction& fraction)
{
    // do the copy
    std::cout << "Do the copy\n";
    std::cout << fraction;
    m_numerator = fraction.m_numerator;
    m_denominator = fraction.m_denominator;

    // return the existing object so we can chain this operator
    return *this;
}

/* chain multiple assignment together */
int main()
{
    Fraction f1 { 5, 3 };
    // Fraction f2 { 7, 2 };
    // Fraction f3 { 9, 5 };

    // f1 = f2 = f3; // chained assignment
    // std::cout << f1; // 7/2
    // std::cout << f2; // 9/5
    // std::cout << f3; // 9/5
    std::cout << f1;
    // Fraction f2 = f1;
    // std::cout << f2;
    Fraction f3 {f1};
    // Fraction f4;
    // f4 = f1;
    return 0;
}