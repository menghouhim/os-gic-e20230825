#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid;
    printf("Parent process (PID: %d) — creating child...\n", getpid());
    pid = fork();
    if (pid < 0) { perror("fork"); exit(EXIT_FAILURE); }
    else if (pid == 0) {
        printf("Child process (PID: %d, Parent PID: %d)\n", getpid(), getppid());
        sleep(30);
        execlp("ls", "ls", "-la", NULL);
        perror("execlp");
        exit(EXIT_FAILURE);
    } else {
        int status;
        waitpid(pid, &status, 0);
        printf("Parent: child exited with status %d\n", WEXITSTATUS(status));
    }
    return 0;
}
