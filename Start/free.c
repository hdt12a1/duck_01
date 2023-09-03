#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    char *ptr = NULL;
    ptr = (char *)malloc(sizeof(char));

    printf ("Address = %p\n", ptr);
    ptr = (char *)malloc(sizeof(char));

    printf ("Address = %p\n", ptr);

    printf("Sizeof CHAR = %lu\n", sizeof(char));
    return 0;
}
