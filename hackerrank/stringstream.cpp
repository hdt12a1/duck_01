#include <iostream>
#include <vector>
#include <sstream>

int main(int argc, char const *argv[])
{
    /* code */
    std::string str = "1,2,3,4,5,6";
    std::vector<std::string> v;
    std::string number;
    std::stringstream ss(str);
    while (getline(ss, number, ','))
    {
        std::cout << number << std::endl;
    }
    return 0;
}
