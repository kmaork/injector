#define _GNU_SOURCE
#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>
#include <sched.h>
#include <sys/wait.h>
#include <unistd.h>

#define STACK_SIZE (1024 * 4)

int threadFunction(void *arg) {
    void* handle = dlopen("./loaded.so", RTLD_LAZY);
    printf("handle: %p\n", handle);
    return 0;
}

int main() {
    if (clone(threadFunction, malloc(STACK_SIZE) + STACK_SIZE, CLONE_VM, 0) == -1) {
        perror("clone");
        exit(1);
    }
    usleep(10000);
    return 0;
}
