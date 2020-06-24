#include <stdio.h>

int constant;

void setConstant(int c)
{
    constant = c;
}

int add(int c)
{
    return constant + c;
}

void __attribute__((constructor)) initLibrary(void)
{
    // Function that is called when the library is loaded.
    printf("initLibrary\n");
    constant = 0;
}

void __attribute__((destructor)) closeLibrary(void)
{
    // Function that is called when the library is closed.
    printf("closeLibrary\n");
}