#include <dlfcn.h>
#include <stdio.h>

int main() {
    void* handle = dlopen("./loaded.so", RTLD_LAZY);
    printf("handle: %p\n", handle);
    return 0;
}
