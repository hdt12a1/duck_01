#include <iostream>

class Person
{
public:
    Person(const std::string &name)
        : m_name{name}
    {
        std::cout << "Constructor\n";
    }
    std::string getName() const
    {
        return m_name;
    }

private:
    std::string m_name;
};

int main(int argc, char const *argv[])
{
    Person p1("Alice");
    Person p2(p1); // shallow copy

    // p1 and p2 share the same underlying string object
    std::cout << p1.getName() << std::endl; // Alice
    std::cout << p2.getName() << std::endl; // Alice

    // change p1's name
    p1.getName() = "Bob";

    // p2's name is also changed
    std::cout << p2.getName() << std::endl; // Bob
    return 0;
}
