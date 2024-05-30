#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    int pipe_fd[2]; // Array to store pipe file descriptors (read & write ends)

    if (pipe(pipe_fd) == -1) {
        perror("pipe");
        exit(1);  // Exit with failure code on error
    }

    pid_t pid = fork();

    if (pid < 0) {
        perror("fork");
        exit(1);
    } else if (pid == 0) {
        // Child process (writer)
        close(pipe_fd[0]); // Close read end in child (not used)
        char message[] = "Hello from the child process!\n";
        ssize_t bytes_written = write(pipe_fd[1], message, sizeof(message));
        if (bytes_written == -1) {
            perror("write");
            exit(1);
        }
        close(pipe_fd[1]); // Close write end after writing
        exit(0);
    } else {
        // Parent process (reader)
        close(pipe_fd[1]); // Close write end in parent (not used)
        char buffer[100];
        ssize_t bytes_read = read(pipe_fd[0], buffer, sizeof(buffer));
        if (bytes_read == -1) {
            perror("read");
            exit(1);
        }
        close(pipe_fd[0]); // Close read end after reading
        printf("Received message from child: %s\n", buffer);
    }

    return 0;
}
