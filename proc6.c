#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <errno.h>

int main()
{
    int ret;
    ret = execl("/bin/ls", "ls" , NULL);
    if (ret == -1)
    {
        perror("execl");
        return 1;
    }
    
    printf("execl failed\n");

    return 0;

}


