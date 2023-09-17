#include <iostream>

class Something
{
public:
    int m_value{}; // public just for sake of example

    void setValue(int value) { m_value = value; }
    int getValue() 
    { 
        std::cout << "Hello \n";
    }
};

int main()
{
    const Something something{}; // something is const

    // something.m_value = 5; // compile error: violates const
    something.setValue(5); // compile error: violates const

    return 0;
}