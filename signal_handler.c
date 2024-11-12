#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void handle_sigint(int sig) {
    printf("Caught signal %d (SIGINT). Exiting gracefully...\n", sig);
    exit(0);
}

int main() {
    // Register signal handler
    signal(SIGINT, handle_sigint);

    printf("Running... Press Ctrl+C to trigger SIGINT.\n");

    // Infinite loop to keep the program running
    while (1) {
        pause(); // Wait for signals
    }

    return 0;
}