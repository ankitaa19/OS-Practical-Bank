#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork");
        exit(1);
    } else if (pid == 0) {
        // Child process
        char *argv[] = {"program_to_run", "argument1", "argument2", NULL}; // Replace with actual program and arguments
        
        // Replace this line with the actual program path
        if (execv("/path/to/program_to_run", argv) == -1) {
            perror("execv");
            exit(1);
        }
    } else {
        // Parent process
        printf("Parent process (PID: %d) created child process (PID: %d)\n", getpid(), pid);
        wait(NULL); // Wait for child process to finish
        printf("Child process finished\n");
    }

    return 0;
}
