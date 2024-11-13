#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid = fork();

    switch (pid) {
        case -1:
            perror("Process creation failed");
            return 1;

        case 0:
            printf("Child process:\n");
            printf("PID: %d\n", getpid());
            printf("PPID: %d\n", getppid());
            break;

        default:
            printf("Parent process:\n");
            printf("PID: %d\n", getpid());
            printf("PPID: %d\n", getppid());
            break;
    }

    return 0;
}