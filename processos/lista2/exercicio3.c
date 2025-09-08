/*3 - Faça um programa em que dois processos concorrentes executam as ações a seguir.
Lembre-se de imprimir o PID de cada processo em cada impressão.
    • Processo Pai: Imprime os números de 1 a 50, com um intervalo de 2 segundos entre cada número. Ao terminar, imprime “Processo Pai finalizou”.
    • Processo Filho1: Imprime os números de 100 a 200, com um intervalo de 1 segundo entre cada um. Ao terminar, imprime “Filho1 finalizou”.
    • Processo Filho2: Imprime os números de 250 a 350, com um intervalo de 1 segundo entre cada um. Ao terminar, imprime “Filho2 finalizou”.
Verifique como acontece o escalonamento de processos na execução do exercício 3.*/

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    pid_t pid1, pid2;

    pid1 = fork(); // cria primeiro filho

    if (pid1 == 0)
    {
        // Código do Filho 1
        for (int i = 100; i <= 200; i++)
        {
            printf("Filho1 (PID=%d) -> %d\n", getpid(), i);
            sleep(1);
        }
        printf("Filho1 (PID=%d) finalizou\n", getpid());
        exit(0);
    }
    else
    {
        // Só o pai continua aqui
        pid2 = fork(); // cria segundo filho

        if (pid2 == 0)
        {
            // Código do Filho 2
            for (int i = 250; i <= 350; i++)
            {
                printf("Filho2 (PID=%d) -> %d\n", getpid(), i);
                sleep(1);
            }
            printf("Filho2 (PID=%d) finalizou\n", getpid());
            exit(0);
        }
        else
        {
            // Código do Pai
            for (int i = 1; i <= 50; i++)
            {
                printf("Pai (PID=%d) -> %d\n", getpid(), i);
                sleep(2);
            }
            printf("Pai (PID=%d) finalizou\n", getpid());
        }
    }

    return 0;
}
