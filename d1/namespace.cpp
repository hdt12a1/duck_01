#include <iostream>

namespace first {
    int x = 111;
}

namespace second {
    int x = 222;
}
using namespace first;

int main(int argc, char const *argv[])
{
    // int x;

    std::cout << "Duck " << x << std::endl;
    std::cout << "Duck " << x << std::endl;
    return 0;
}
