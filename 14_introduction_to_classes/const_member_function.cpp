#include <iostream>

class Something
{
private:
    int m_value{};

public:
    int &getValue() const { return m_value; } // now a const member function
};

int main()
{
    const Something something{}; // something is const

    std::cout << something.getValue(); // ok to call const member function on const object

    return 0;
}