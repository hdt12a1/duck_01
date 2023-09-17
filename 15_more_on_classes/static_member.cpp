#include <iostream>

class Something
{
public:
    // static const int s_value{1};
    static int s_value;
};
int Something::s_value{ 1 }; // defines the static member variable
int main()
{
    std::cout << Something::s_value; // s_value is public, we can access it directly
}