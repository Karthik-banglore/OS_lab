#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();
    
    if (pid > 0) {
        sleep(10);
    } 
    else if (pid == 0) {
        exit(0);
    } 
    else {
        printf("Fork failed\n");
        return 1;
    }
    
    return 0;
}