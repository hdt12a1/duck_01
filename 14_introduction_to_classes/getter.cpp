#include <iostream>
#include <string>

class Employee
{
	 std::string m_name  = "Helloooo";

public:
	Employee(std::string_view name)
		: m_name{ name }
	{
	}

	const std::string& getName(){ 
        return m_name; }

    int& getNumber()
    {
        return 10;
    }
};

int main()
{
	Employee joe{ "Joe" };
    std::string test = joe.getName();
	std::cout << joe.getName();

	return 0;
}