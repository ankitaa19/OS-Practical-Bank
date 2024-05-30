#include <stdio.h>
#include <signal.h>

void signal_handler(int sig) {
  printf("Caught signal: %d\n", sig);
}

int main() {
  // Install signal handler for SIGINT (Ctrl+C)
  if (signal(SIGINT, signal_handler) == SIG_ERR) {
    perror("signal");
    return 1;
  }

  printf("Press Ctrl+C to send SIGINT signal.\n");

  // Infinite loop to demonstrate signal handling
  while (1) {
    // Do some work here (simulated with sleep)
    sleep(1);
  }

  return 0; // This line will never be reached due to the infinite loop
}
