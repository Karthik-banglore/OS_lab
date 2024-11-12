#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) exit(1);
    if (pid > 0) exit(0);

    if (setsid() < 0) exit(1);
    umask(0);
    chdir("/");

    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);

    pid_t daemon_pid = getpid();
    printf("Daemon running with PID: %d\n", daemon_pid);  // Print PID to terminal

    while (1) {
        int fd = open("/tmp/daemon.log", O_WRONLY | O_CREAT | O_APPEND, 0600);
        if (fd != -1) {
            dprintf(fd, "Daemon running, PID: %d\n", daemon_pid);  // Write PID to log file
            close(fd);
        }
        sleep(10);
    }

    return 0;
}