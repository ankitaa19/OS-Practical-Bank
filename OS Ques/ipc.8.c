#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/sem.h>

#define SHARED_VALUE 0 // Initial value for the shared variable

int main() {
    key_t key = ftok(".", 'a'); // Generate a unique key
    int semid = semget(key, 1, IPC_CREAT | 0666); // Create a semaphore set with 1 semaphore

    if (semid == -1) {
        perror("semget");
        exit(1);
    }

    // Initialize the semaphore with value 1 (unlocked)
    semctl(semid, 0, SETVAL, 1);

    pid_t pid = fork();

    if (pid < 0) {
        perror("fork");
        exit(1);
    } else if (pid == 0) {
        // Child process (writer)
        int shared_var = SHARED_VALUE;

        struct sembuf operations[1];  // Array for semaphore operations
        operations[0].sem_num = 0;      // Operate on the first semaphore
        operations[0].sem_op = -1;     // Decrement (lock) the semaphore
        operations[0].sem_flg = 0;      // No flags

        while (1) {
            // Acquire semaphore (wait for it to be non-zero)
            if (semop(semid, operations, 1) == -1) {
                perror("semop (child)");
                exit(1);
            }

            shared_var++;
            printf("Child process incremented shared value to: %d\n", shared_var);

            // Release semaphore (increment to signal)
            operations[0].sem_op = 1;
            if (semop(semid, operations, 1) == -1) {
                perror("semop (child)");
                exit(1);
            }

            sleep(1); // Simulate some work
        }
    } else {
        // Parent process (reader)
        int shared_var = SHARED_VALUE;

        struct sembuf operations[1];
        operations[0].sem_num = 0;
        operations[0].sem_op = -1;
        operations[0].sem_flg = 0;

        while (1) {
            // Acquire semaphore (wait for it to be non-zero)
            if (semop(semid, operations, 1) == -1) {
                perror("semop (parent)");
                exit(1);
            }

            printf("Parent process read shared value: %d\n", shared_var);

            // Release semaphore (increment to signal)
            operations[0].sem_op = 1;
            if (semop(semid, operations, 1) == -1) {
                perror("semop (parent)");
                exit(1);
            }

            sleep(2); // Simulate some work
        }
    }

    // Not reached due to the infinite loops, but included for completeness
    if (semctl(semid, 0, IPC_RMID) == -1) {
        perror("semctl (IPC_RMID)");
        exit(1);
    }

    return 0;
}
