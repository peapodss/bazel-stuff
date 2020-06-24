#include <stdio.h>
#include <add.h>
#include <result.h>

int main(int argc, char *argv[])
{
    setConstant(5);
    printf("5 + 10 = %d\n", add(10));
    printf("result: %d\n", result());
    return 0;
}