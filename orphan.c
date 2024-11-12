#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();
    
    if (pid > 0) {
        printf("Parent Process: My PID is %d, Child PID is %d\n", getpid(), pid);
        exit(0);
    } 
    else if (pid == 0) {
        printf("Child Process: My PID is %d\n", getpid());
        sleep(30);
    } 
    else {
        printf("Fork failed\n");
        return 1;
    }
    
    return 0;
}