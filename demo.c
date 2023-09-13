#include <stdio.h>

typedef void (*FUNCPTR)();

void print(double  a)
{
        printf("%d\n", a);
}

typedef union
{
        int *ptr;
        unsigned int data;
} num_t;

num_t symbol;

int main(int argc, char const *argv[])
{
        double number = 57.16;
        // printf("%f\n", number);
        symbol.data = (unsigned int ) number;
        // printf("Data = %f\n", (double)symbol.data);
        printf("ptr = %p\n", symbol.ptr);
        FUNCPTR cmd = print;
        printf("Sizeof double = %ld sizeof pointer = %ld\n", sizeof(double), sizeof(int*));
        int x = 99;
        int *pointer = &x;
        double test = pointer  ; 
        double castt = (double)symbol.ptr;
        // cmd((double)symbol.ptr);
        // printf("%f\n", symbol.data);
        return 0;
}

