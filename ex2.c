#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int pid = fork();

    if (pid < 0)
    {
        printf("Fork failed\n");
        return 1;
    }
    else if (pid == 0)
    {
        printf("I am child, my PID is %d\n", getpid());
        printf("My parent PID is %d\n", getppid());
    }
    else
    {
        printf("I am parent, my PID is %d\n", getpid());
        wait(NULL);
        printf("Child process completed.\n");
    }

    return 0;
}
