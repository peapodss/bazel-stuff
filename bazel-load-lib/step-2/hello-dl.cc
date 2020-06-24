#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
int main()
{
    void *handle = dlopen("hello-greet", RTLD_LAZY);
    if (!handle)
    {
        fprintf(stderr, "%s\n", dlerror());
        exit(EXIT_FAILURE);
    }
    void (*f)() = (void (*)())dlsym(handle, "f");
    char *error = dlerror();
    if (error != NULL)
    {
        fprintf(stderr, "%s\n", error);
        exit(EXIT_FAILURE);
    }
    f();
    dlclose(handle);
    exit(EXIT_SUCCESS);
    return 0;
}