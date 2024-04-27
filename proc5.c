#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>


int main()
{
    pid_t pid;

    int x = 0;

    pid = vfork();

    if (pid == 0) {
        x = 1;
        exit(0);
    } else if (pid > 0) {
        wait(NULL);
    }

    printf("hello %d\n", x);


    return 0;
}