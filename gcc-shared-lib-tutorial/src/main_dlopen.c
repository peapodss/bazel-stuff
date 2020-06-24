#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
// Note, add.h and answer.h need not be #include'd

// void* GetRuntimeDsoHandle() {
//   return GetDsoHandle("libmyfunctions.so", GetVersion());
// }

void *GetSymbolFromLibrary(void *handle, const char *symbol_name,
                           void **symbol)
{
    // Check that the handle is not NULL to avoid dlsym's RTLD_DEFAULT behavior.
    if (!handle)
    {
        *symbol = NULL;
    }
    else
    {
        *symbol = dlsym(handle, symbol_name);
    }
    if (!*symbol)
    {
        fprintf(stderr, "Could not get function pointer for %s\n  error is: %s\n\n", symbol_name, dlerror());
        return NULL;
    }
    return symbol;
}

void *getFunctionPointer(void *lib, const char *funcName)
{
    // Get the function pointer to the function
    void *fptr = dlsym(lib, funcName);
    if (!fptr)
    {
        fprintf(stderr, "Could not get function pointer for %s\n  error is: %s\n\n", funcName, dlerror());
        return NULL;
    }
    return fptr;
}

int main(int argc, char *argv[])
{
    // Declare the function pointers:
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
    void (*fptr_null)(int);
#pragma GCC diagnostic pop
    void (*fptr_setConstant)(int);
    int (*fptr_add)(int);

    // Open the dynamic library
    void *myfunctionslib = dlopen("libmyfunctions.so", RTLD_LAZY | RTLD_GLOBAL);

    if (!myfunctionslib)
    {
        // Apparently, the library could not be opened
        fprintf(stderr, "Could not open libmyfunctions.so\n");
        exit(1);
    }

    //static auto func_ptr = LoadSymbol<FuncPtr>("__cudaPopCallConfiguration");
    // Get the pointers to the functions within the library:
    //Function doesNotExist does not exist, calls dlerror()
    fptr_null = getFunctionPointer(myfunctionslib, "doesNotExist");
    fptr_setConstant = getFunctionPointer(myfunctionslib, "setConstant");
    fptr_add = getFunctionPointer(myfunctionslib, "add");

    // Call the function via the function pointer
    fptr_setConstant(43);
    int result = fptr_add(7);
    printf("Result: %d\n", result);
}