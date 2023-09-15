#include <iostream>
#include <string>
#include <string_view>

class Employee
{
public:
    std::string m_name{};
    int m_id{ 0 };

public:
/*     Employee(std::string name)
        : Employee(name, 0) // delegate initialization to Employee(std::string_view, int) constructor
    {
        std::cout << "Hello Viet nam " << std::endl;
    }

    Employee(std::string name, int id)
        : m_name(name), m_id{ id } // actually initializes the members
    {
        std::cout << "Employee " << m_name << " created\n";
    } */

    Employee(std::string name)
        : m_name {name}
    {
        std::cout << "Hello Viet nam " << std::endl;
    }

    Employee(std::string name, int id)
        : Employee(name)
    {
        std::cout << "Employee " << m_name << " created\n";
        std::cout << "id: " << id << std::endl;
        m_id = id;
    }

};

int main()
{
    // Employee e1{ "James" };
    Employee e2{ "Dave", 42 };
    std::cout << "ID : " << e2.m_id << std::endl;
}