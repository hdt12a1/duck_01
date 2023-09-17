#include <iostream>
#include <memory>

int main(int argc, char const *argv[])
{
    std::unique_ptr<int> unPtr1 = std::make_unique<int>(25);
    std::unique_ptr<int> unPtr2 = std::move(unPtr1);

    if (unPtr1 == nullptr)
    {
        std::cout << "unPtr1 is a nullptr" << std::endl;
    }

    std::cout << *unPtr2 << std::endl;
    // std::cout << *unPtr1 << std::endl;
    return 0;
}
