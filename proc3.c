#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
 
        pid_t chpid;
      
        for (size_t i = 0; i < 3; i++)
        {
             chpid = fork();
             
             if (chpid == -1)
             {
                perror("fork");
                exit(EXIT_FAILURE);
             }

             if (chpid == 0)
             {
                if (i == 0)
                {   int ret;
                    ret = execlp("ls" , "ls", NULL);
                    if (ret == -1)
                    {
                        perror("exec");
                        exit(EXIT_FAILURE);
                    }

                    exit(EXIT_SUCCESS);
                    
                }
                if (i == 1)
                {   int ret;
                    ret = execlp("whoami" , "whoami", NULL);
                    if (ret == -1)
                    {
                        perror("exec");
                        exit(EXIT_FAILURE);
                    }

                    exit(EXIT_SUCCESS);
                    
                }

                if (i == 2)
                {   int ret;
                    ret = execlp("date" , "date", NULL);
                    if (ret == -1)
                    {
                        perror("exec");
                        exit(EXIT_FAILURE);
                    }

                    exit(EXIT_SUCCESS);
                    
                }
                
            }


            for (size_t i = 0; i < 3; i++)
            {
                wait(NULL);
            }
            
             
        }
 
    return 0;
}