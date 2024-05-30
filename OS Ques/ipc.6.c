#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define MESSAGE_SIZE 128

struct message_struct {
    long mtype;
    char message[MESSAGE_SIZE];
};

int main() {
    // Generate a unique key for message queue
    key_t key = ftok(".", 'a');

    // Create or retrieve the message queue with IPC_CREAT and access permissions
    int msgqid = msgget(key, IPC_CREAT | 0666);
    if (msgqid == -1) {
        perror("msgget");
        exit(1);
    }

    pid_t pid = fork();
    if (pid < 0) {
        perror("fork");
        exit(1);
    }

    if (pid == 0) {
        // Child process (sender)
        struct message_struct msg;
        msg.mtype = 1;  // Specify message type
        strcpy(msg.message, "Hello from the child process!");

        // Send message to the queue using msgsnd
        if (msgsnd(msgqid, &msg, sizeof(msg.message), 0) == -1) {
            perror("msgsnd");
            exit(1);
        }

        exit(0);
    } else {
        // Parent process (receiver)
        struct message_struct msg;

        // Receive message from the queue with specified type (1)
        if (msgrcv(msgqid, &msg, sizeof(msg.message), 1, 0) == -1) {
            perror("msgrcv");
            exit(1);
        }

        printf("Received message from child: %s\n", msg.message);
    }

    // Remove the message queue (optional) - uncomment if needed
    // if (msgctl(msgqid, IPC_RMID, NULL) == -1) {
    //     perror("msgctl");
    //     exit(1);
    // }

    return 0;
}
