#include <iostream>


/* C++ program to demonstate problem with NULL */
/* void func(int N)
{
    std::cout << "func(int)" << '\n';
    return;
}

void func(char *s)
{
    std::cout << "func(char *)" << '\n';
    return;
} */

void foo(int)
{

}
void foo(char*)
{
    
}
int main(int argc, char const *argv[])
{
    /* Ideally, It should have called fun(char*) */
/*     func(nullptr); */
    int *pNum = NULL;
    foo(nullptr);
    return 0;
}
