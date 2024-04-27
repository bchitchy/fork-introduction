#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/mman.h>

#define LEN 80
#define BLOCK 20
#define CHILDS 4

int main()
{   int num = 4;
    int* myarray = mmap(NULL , 4096, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);;
    int* ptr = mmap(NULL , 4096, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);

    for (int i = 0; i < LEN; i++)
    {
        ptr[i] = num++;
    }
    

    for(int i = 0 ; i< CHILDS ; ++i)
    {
        
        
        
        pid_t id = fork();
        if(id > 0)
        {
            wait(NULL);
        }
        
        
        if (id == 0)
        {
            int sum = 0;
            for (int j = i * BLOCK; j < (i+1)*BLOCK; ++j)
            {
                sum+= ptr[j];
            }

            myarray[i] = sum;
            exit(EXIT_SUCCESS);
            
        }
        
    }

    int result = 0;
    for (int i = 0; i < CHILDS; i++)
    {
        result += myarray[i];
    }

    printf("%d", result);
    
    
    return 0;
}