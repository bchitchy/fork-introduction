#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    pid_t pid;
    pid = fork();
    if (pid < 0)
    {
        perror("No forking");
        exit(-1);        
    }

    else if (pid == 0)
    {
        printf("Hello from child, its my id -> %d", getpid());        
    }

    else
    {
        printf("Hello from parent, its my id -> %d", getpid());
    }
    
    
    

    return 0;
}
