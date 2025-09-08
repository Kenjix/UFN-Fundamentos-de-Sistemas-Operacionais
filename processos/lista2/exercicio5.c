#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    pid_t pid1, pid2, pid3, pid4, pid5;

    pid1 = fork(); // cria Filho 1
    if (pid1 == 0) {
        // Código do Filho 1
        pid2 = fork(); // cria Filho 2
        if (pid2 == 0) {
            // Código do Filho 2
            pid3 = fork(); // cria Filho 3
            if (pid3 == 0) {
                // Código do Filho 3
                printf("Sou o Filho 3, PID = %d\n", getpid());
                exit(0);
            }
            printf("Sou o Filho 2, PID = %d\n", getpid());
            exit(0);
        }
        printf("Sou o Filho 1, PID = %d\n", getpid());
        exit(0);
    } else {
        // Código do Pai
        pid4 = fork(); // cria Filho 4
        if (pid4 == 0) {
            // Código do Filho 4
            pid5 = fork(); // cria Filho 5
            if (pid5 == 0) {
                // Código do Filho 5
                printf("Sou o Filho 5, PID = %d\n", getpid());
                exit(0);
            }
            printf("Sou o Filho 4, PID = %d\n", getpid());
            exit(0);
        }
        printf("Sou o Pai, PID = %d\n", getpid());
    }

    return 0;
}
