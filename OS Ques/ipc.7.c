#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

#define SEGMENT_SIZE 1024  // Size of the shared memory segment

int main() {
    key_t key = ftok("shared_memory_file", 'a'); // Generate a unique key
    int shmid = shmget(key, SEGMENT_SIZE, IPC_CREAT | 0666);  // Create shared memory segment

    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }

    // Attach the shared memory segment to the address space of this process
    char *shared_memory = (char*)shmat(shmid, NULL, 0);
    if (shared_memory == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    pid_t pid = fork();

    if (pid < 0) {
        perror("fork");
        exit(1);
    } else if (pid == 0) {
        // Child process (writer)
        strcpy(shared_memory, "Hello from the child process!\n");
        printf("Child process wrote to shared memory: %s\n", shared_memory);
        sleep(2); // Simulate some work
    } else {
        // Parent process (reader)
        sleep(1); // Simulate some work to ensure child writes first
        printf("Parent process read from shared memory: %s\n", shared_memory);
    }

    // Detach the shared memory segment
    if (shmdt(shared_memory) == -1) {
        perror("shmdt");
        exit(1);
    }

    // Remove the shared memory segment (optional, parent can do this)
    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        perror("shmctl");
        exit(1);
    }

    return 0;
}
