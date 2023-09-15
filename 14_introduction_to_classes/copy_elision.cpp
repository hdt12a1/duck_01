#include <iostream>
class Something
{
public:
	Something() 
    {
        std::cout << "Default constructor\n";
    }
	Something(const Something&)
	{
		std::cout << "Copy constructor called\n";
	}
};

Something rvo()
{
	return Something{}; // calls Something() and copy constructor
}

Something nrvo()
{
	Something s{}; // calls Something()
	return s;      // calls copy constructor
}

int main()
{

    int num (10);
    int num1 {11};
    int num2 (12.3);
    int num3 {12.3}; // error error: type 'double' cannot be narrowed to 'int' in initializer list
	std::cout << "Initializing s1\n";
	Something s1 { rvo() }; // calls copy constructor

	std::cout << "Initializing s2\n";
	Something s2 { s1 }; // calls copy constructor

    return 0;
}