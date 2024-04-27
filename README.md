# fork-introduction
# Process Management in Linux

This repository contains C programs implementing various process management tasks in Linux. Each task focuses on different aspects of process creation, execution, and communication using fork(), exec(), wait(), and mmap().

## Task Descriptions

### Task 1: Basic Process Creation with fork()

- **Objective**: Understand the basics of process creation using fork().
- **Requirements**:
  - Implement a C program that utilizes fork() to create a new process.
  - In the parent process, print the message "Hello from Parent!" followed by the parent's PID.
  - In the child process, print the message "Hello from Child!" followed by the child's PID.
  - Ensure your program checks for and handles the error case where fork() fails.

### Task 2: Executing a New Program with exec()

- **Objective**: Learn to replace the current process image with a new process image using exec().
- **Requirements**:
  - Modify the Task 1 program. After the fork, make the child process execute /bin/ls to list the contents of the current directory.
  - Use execlp() for executing /bin/ls.
  - Ensure the parent process waits for the child process to complete its execution before exiting, using wait().
  - Handle potential errors for fork(), execlp(), and wait() calls.

### Task 3: Combining fork(), exec(), and wait()

- **Objective**: Master the combination of fork(), exec(), and wait() for process management.
- **Requirements**:
  - Implement a C program where the parent process creates multiple child processes through a loop.
  - Each child process should execute a different command using exec(). Suggested commands: ls, whoami, date.
  - The parent process must wait for all child processes to complete execution before it exits.
  - Include error checking for each system call (fork(), exec(), wait()) to ensure robustness.

### Task 4: Shared Memory with mmap()

- **Objective**: Explore memory mapping and IPC using mmap().
- **Requirements**:
  - Write a C program that creates a shared memory region accessible by two processes (a parent and a child created with fork()).
  - The parent writes a message (e.g., "Hello from Parent") to the shared memory.
  - The child reads this message and prints it.
  - Use mmap() for creating the shared memory. Implement necessary synchronization to prevent race conditions.

### Task 5: Complex Communication with mmap() and fork()

- **Objective**: Implement a more complex scenario involving shared memory and process control.
- **Requirements**:
  - Extend the Task 4 program to create a shared data structure (like an array of integers) in the shared memory region.
  - The parent process fills this shared data structure with data.
  - The child processes read from this data structure and perform a simple operation (e.g., summing the integers).

## Implementation Guidance

- **Error Handling**: Each task includes robust error handling for all system calls to ensure reliability.
- **Code Documentation**: Code is clearly commented to describe key decisions and mechanisms, aiding in understanding the implementation approach.
- **Testing**: Programs are tested in different scenarios and inputs to ensure they handle edge cases gracefully.

