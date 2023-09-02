#include <iostream>


/* C++ program to demonstate problem with NULL */
void func(int N)
{
    std::cout << "func(int)" << '\n';
    return;
}

void func(std::string *str)
{
    std::cout << "func(char *)" << '\n';
    std::cout << str << '\n';
    return;
}

/* void foo(int)
{

}
void foo(char*)
{
    
} */
int main(int argc, char const *argv[])
{
    /* Ideally, It should have called fun(char*) */
    //func(NULL);
/*     int *pNum = NULL;
    foo(nullptr); */
    // int x = nullptr;

    func(nullptr);
    return 0;
}
