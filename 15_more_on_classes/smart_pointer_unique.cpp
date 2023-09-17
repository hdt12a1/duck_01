#include <iostream>
#include <memory>

class int
{
public:
    MyClass(int x)
    {
        std::cout << "Constructor " << x << std::endl;
    }

    ~MyClass()
    {
        std::cout << "Destructor " << std::endl;
    }
};

int main(int argc, char const *argv[])
{
    std::weak_ptr<int> wePtr1;

    {
        std::shared_ptr<int> shPtr1 = std::make_shared<int>(23);
        wePtr1 = shPtr1;
        if (wePtr1.expired())
        {
            std::cout << "Expired" << std::endl;
        }
        else
        {
            std::cout << "No Expired" << std::endl;
        }

        std::cout << *wePtr1 << "  " << *shPtr1 << std::endl;
    }
    if (wePtr1.expired())
    {
        std::cout << "Expired" << std::endl;
    }

    return 0;
}
