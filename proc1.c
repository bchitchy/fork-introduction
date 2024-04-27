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
        exit(EXIT_FAILURE);        
    }

    else if (pid == 0)
    {
        execl("/bin/ls", "ls", "-l" , NULL);
        exit(0);        
    }
    
    return 0;
}