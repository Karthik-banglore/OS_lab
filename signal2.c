#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

// Handler for SIGINT (Ctrl+C)
void handle_sigint(int sig) {
    printf("Caught SIGINT (Ctrl+C). Exiting gracefully...\n");
    exit(0);
}

// Handler for SIGUSR1
void handle_sigusr1(int sig) {
    printf("Caught SIGUSR1. Custom action performed!\n");
}

// Handler for SIGUSR2
void handle_sigusr2(int sig) {
    printf("Caught SIGUSR2. Another custom action performed!\n");
}

int main() {
    // Register signal handlers
    signal(SIGINT, handle_sigint);
    signal(SIGUSR1, handle_sigusr1);
    signal(SIGUSR2, handle_sigusr2);

    printf("Running... Use Ctrl+C to trigger SIGINT.\n");
    printf("Send SIGUSR1 (kill -USR1 %d) to trigger SIGUSR1.\n", getpid());
    printf("Send SIGUSR2 (kill -USR2 %d) to trigger SIGUSR2.\n", getpid());

    // Infinite loop to keep the program running
    while (1) {
        pause(); // Wait for signals
    }

    return 0;
}