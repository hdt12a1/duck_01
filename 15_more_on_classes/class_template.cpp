#include <iostream>

template <typename T, typename U, typename X>

class Triad
{
private:
    T t_ins {};
    U u_ins {};
    X x_ins {};

public:
    // member initialize list
    Triad(T t_ins, U u_ins, X x_ins)
        : t_ins{t_ins}, u_ins{u_ins}, x_ins{x_ins}
    {
        std::cout << "Creating Contrutor!" << std::endl;
    }
    void print()
    {
        std::cout << "[" << t_ins << ", " << u_ins << ", " << x_ins << "]";
    }
};



int main()
{
    /* 
    Triad<int, int , int> t1{1, 2, 3};
    t1.print();

    Triad<int, double, std::string> t2{1, 2.3, "Hello"};
    t2.print(); */

    Triad t1{1, 2, 3};
    t1.print();

    Triad<int, double, std::string> t2{1, 2.3, "Hello"};
    t2.print();

    return 0;
}