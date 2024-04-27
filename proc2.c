#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
    pid_t pid;
    pid = fork();
    int status;

    if (pid < 0)
    {
        perror("No forking");
        exit(EXIT_FAILURE);        
    }

    else if (pid == 0)
    {
      int ret = execlp("ls", "ls", "-l" , NULL);
        if (ret == -1)
        {
            perror("execlp");
            exit(EXIT_FAILURE);
        }
        
        exit(EXIT_SUCCESS);        
    }

    else if (pid > 0)
    {
        printf("I parent");
        if(wait(&status) == -1)
        {
            perror("wait");
            exit(EXIT_FAILURE);
        }
    }
    
    
    return 0;
}