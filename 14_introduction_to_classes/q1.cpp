#include <iostream>

// Provide the definition for IntPair and the print() member function here
struct IntPair
{
    int number1 {};
    int number2 {};
    IntPair(int num1, int num2)
    {
        this->number1 = num1;
        this->number2 = num2;
    }
    void print()
    {
        std::cout << "Pair(" << number1 << ","
            << number2 << ")" << std::endl;
    }
};
int main()
{
	IntPair p1 {1, 2};
	IntPair p2 {3, 4};

	std::cout << "p1: ";
	p1.print();

	std::cout << "p2: ";
	p2.print();

	return 0;
}