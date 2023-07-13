#define _GNU_SOURCE
#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>
#include <sched.h>
#include <sys/wait.h>
#include <unistd.h>

#define STACK_SIZE (1024 * 1024)    /* Stack size for cloned child */


int threadFunction(void *arg) {
    void* handle = dlopen("./loaded.so", RTLD_LAZY);
    printf("handle: %p\n", handle);
    return 0;
}

int main() {
    char *stack;
    char *stackTop;
    int status;

    /* Allocate stack for child */
    stack = malloc(STACK_SIZE);
    if (stack == NULL) {
        perror("malloc");
        exit(1);
    }

    /* Assume stack grows downward */
    stackTop = stack + STACK_SIZE;

    if (clone(threadFunction, stackTop, CLONE_VM, 0) == -1) {
        perror("clone");
        exit(1);
    }

    usleep(10000);
    return 0;
}
