#include <iostream>


class Cents
{
    private:
        int m_cents {};
    public:
        Cents(int cents) : m_cents( cents ) {};
        int getCents() const 
        {
            return m_cents;
        }
    friend Cents operator+(const Cents& c1, Cents const &c2);
};

Cents operator+(const Cents& c1, Cents const &c2)
{
    return c1.m_cents + c2.m_cents;
}
int main(int argc, char const *argv[])
{
	Cents cents1{ 6 };
	Cents cents2{ 8 };
	Cents centsSum{ cents1 + cents2 };
	std::cout << "I have " << centsSum.getCents() << " cents.\n";

	return 0;
}
