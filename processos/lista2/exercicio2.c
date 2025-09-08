/*2 – Escreva um programa formado por 3 processos concorrentes, que executam um laço de repetição de N interações.
Neste laço, cada processo imprime sua identificação. A partir da execução do programa, identifique como acontece o
escalonamento dos processos.*/

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num;

    printf("Entre com o numero de interações do laço: ");
    scanf("%d", &num);

    // Primeiro fork
    pid_t p1 = fork();

    if (p1 < 0)
    {
        perror("Erro ao criar processo");
        exit(1);
    }

    // Segundo fork
    pid_t p2 = fork();

    if (p2 < 0)
    {
        printf("Erro ao criar processo");
        exit(1);
    }

    // Pai (original), Filho 1 e Filho 2
    for (int i = 0; i < num; i++)
    {
        if (p1 == 0 && p2 > 0)
        {
            printf("Processo Filho 1 - interação %d\n", i + 1);
        }
        else if (p1 > 0 && p2 == 0)
        {
            printf("Processo Filho 2 - interação %d\n", i + 1);
        }
        else if (p1 > 0 && p2 > 0)
        {
            printf("Processo Pai - interação %d\n", i + 1);
        }
    }

    return 0;
}
