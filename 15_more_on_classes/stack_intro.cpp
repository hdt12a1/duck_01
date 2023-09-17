#include <iostream>
#include <vector>

void printStack(const std::vector<int> &stack)
{
    if (stack.size() == 0)
    {
        std::cout << "Stack is empty" << std::endl;
    }
    for (auto element : stack)
    {
        std::cout << element << " ";
    }

    std::cout << "Capacity: " << stack.capacity() << " Length " << stack.size() << std::endl;
}

int main(int argc, char const *argv[])
{
    /* code */

	std::vector<int> stack{}; // empty stack

	printStack(stack);

	stack.push_back(1); // push_back() pushes an element on the stack
	printStack(stack);

	stack.push_back(2);
	printStack(stack);

	stack.push_back(3);
	printStack(stack);

	std::cout << "Top: " << stack.back() << '\n'; // back() returns the last element

	stack.push_back(1); // push_back() pushes an element on the stack
	printStack(stack);

	stack.push_back(2);
	printStack(stack);

	// stack.push_back(3);
	// printStack(stack);


    
    return 0;
}
