#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
    int status;

    // Using execl() with full path
    printf("Running ps using execl()\n");

    if (fork() == 0)
    {
        execl("/bin/ps", "ps", "-f", NULL);
        perror("execl failed");
        exit(1);
    }

    wait(&status);

    if (WIFEXITED(status))
    {
        printf("Child exited with status: %d\n\n", WEXITSTATUS(status));
    }
    else
    {
        printf("Child did not exit successfully\n\n");
    }

    // Using execlp() without full path
    printf("Running ps using execlp()\n");

    if (fork() == 0)
    {
        execlp("ps", "ps", "-f", NULL);
        perror("execlp failed");
        exit(1);
    }

    wait(&status);

    if (WIFEXITED(status))
    {
        printf("Child exited with status: %d\n", WEXITSTATUS(status));
    }
    else
    {
        printf("Child did not exit successfully\n");
    }

    printf("\nProgram completed successfully.\n");

    return 0;
}
