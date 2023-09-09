#include <iostream>

namespace first {
    int x = 111;
}

namespace second {
    int x = 222;
}
// using namespace first;

int main(int argc, char const *argv[])
{
    // int x;
    // test git config unset
    std::cout << "Duck " <<first:: x << std::endl;
    std::cout << "Duck " << frist::x << std::endl;
    return 0;
}
