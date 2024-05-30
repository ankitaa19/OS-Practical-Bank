#include <stdio.h>
#include <signal.h>

void signal_handler(int signo) {
  if (signo == SIGINT) {
    printf("\nCaught SIGINT signal! (Interrupt)\n");
  }
}

int main() {
  // Register signal handler for SIGINT
  if (signal(SIGINT, signal_handler) == SIG_ERR) {
    perror("signal");
    return 1;
  }

  printf("Press Ctrl+C to send SIGINT signal.\n");

  // Simulate some work (program keeps running until interrupted)
  while (1) {
    // Add any code you want to execute here
  }

  return 0;
}
