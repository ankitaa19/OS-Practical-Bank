#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork");
        return 1;
    } else if (pid == 0) {
        // Child process
        printf("Child process (PID: %d) sleeping for 5 seconds...\n", getpid());
        sleep(5);
        printf("Child process (PID: %d) exiting...\n", getpid());
    } else {
        // Parent process
        int status;
        pid_t wait_pid = wait(&status); // Wait for child process to finish
        if (wait_pid == -1) {
            perror("wait");
            return 1;
        }

        printf("Parent process (PID: %d) waiting complete, child exited with status %d\n", getpid(), status);
    }

    return 0;
}
