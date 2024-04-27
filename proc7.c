#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/mman.h>

int main() 
{
    pid_t pid;
    char* mmapptr; // Declare mmapptr variable
    
    // Map shared memory
    mmapptr = mmap(NULL, 4096, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    if (mmapptr == MAP_FAILED) {
        perror("mmap");
        exit(EXIT_FAILURE);
    }

    pid = fork();
    if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid > 0) { // Parent process
        printf("Enter a message: ");
        scanf("%s", mmapptr);

        wait(NULL); // Wait for the child process to finish
        
        // Unmap shared memory in the parent process
        // if (munmap(mmapptr, 4096) == -1) {
        //     perror("munmap");
        //     exit(EXIT_FAILURE);
        // }

        exit(EXIT_SUCCESS);
    }if (munmap(mmapptr, 4096) == -1) {
        //     perror("munmap");
        //     exit(EXIT_FAILURE);
        // }

    if (pid == 0) { // Child process
        sleep(10); // Sleep for 10 seconds

        printf("Received message: %s\n", mmapptr); // Print the message directly

        // Unmap shared memory in the child process
        // if (munmap(mmapptr, 4096) == -1) {
        //     perror("munmap");
        //     exit(EXIT_FAILURE);
        // }

        exit(EXIT_SUCCESS);
    }

    return 0;
}