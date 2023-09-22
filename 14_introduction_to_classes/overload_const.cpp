#include <string>
#include <string_view>
#include <iostream>

class MyString
{
public:
    std::string m_str{"Vietnam"};

public:
    MyString(std::string_view str = "Hello ")
        : m_str{str}
    {
    }

    const std::string &str() const 
    {
        return m_str;
    } // str() for const objects (returns const reference)
    std::string &str()
    {
        return m_str;
    } // str() for non-const objects (returns non-const reference)
};

int main()
{
    MyString s1{};
    s1.str() = "Drake"; // calls non-const str();
    std::cout << s1.m_str << std::endl;
    const MyString s2{};
    s2.str(); // calls const str();

    return 0;
}