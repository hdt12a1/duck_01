#include <iostream>
#include <vector>

int main()
{
    // Create a vector with length 5
    std::vector<int> v{ 0, 1, 2, 3, 4 };
    v = { 0, 1, 2, 3, 4 }; // okay, array length = 5
    std::cout << "Capacity: " << v.capacity() << "  Length: " << v.size() << '\n';

    for (int i = 0; i < static_cast<int>(v.size()); ++i)
    {
        std::cout << "Adress " << &v[i] << "   " << v[i] << ' ' << std::endl;
        
    }
    std::cout << '\n';

    // Resize vector to 3 elements
    v.resize(3); // we could also assign a list of 3 elements here
    std::cout << "Capacity: " << v.capacity() << "  Length: " << v.size() << '\n';

    for (int i = 0; i < static_cast<int>(v.capacity()); ++i)
    {
        std::cout << "Adress " << &v[i] << "   " << v[i] << ' ' << std::endl;
        
    }
    std::cout << '\n';

    // Resize vector back to 5 elements
    v.resize(6);
    std::cout << "Capacity: " << v.capacity() << "  Length: " << v.size() << '\n';

    for (int i = 0; i < static_cast<int>(v.size()); ++i)
    {
        std::cout << "Adress " << &v[i] << "   " << v[i] << ' ' << std::endl;
        
    }
    std::cout << '\n';

    return 0;
}