#include <iostream>

class Test
{

public: 
    /* Default constructor*/
    Test()
    {
        std::cout << "Default Constructor\n";
    }

    ~Test()
    {
        std::cout << "Default Destructor\n";
    }
private:

};

int main(int argc, char const *argv[])
{
    /* code */
    Test *ptr = new Test();
    delete ptr;
    return 0;
}

