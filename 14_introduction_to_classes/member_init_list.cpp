#include <iostream>

class Foo
{
private:
    int m_x {};
    int m_y {};

public:
    Foo(int x, int y)
        : m_y { x } , m_x {y} // here's our member initialization list
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