/* – Crie um programa com dois processos. As medidas de um terreno retangular devem ser lidas.
O processo Filho deve calcular a área do terreno e o processo Pai o perímetro. Todos os resultados
obtidos devem ser mostrados ao usuário.*/

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
    pid_t procID;
    float base, altura;

    printf("Informe a base do terreno: ");
    scanf("%f", &base);
    printf("Informe a altura do terreno: ");
    scanf("%f", &altura);

    procID = fork();

    if (procID == -1)
    {
        printf("Erro ao criar processo");
        return 1; // encerra com código de erro
    }
    else if (procID == 0)
    {
        // Filho
        printf("... Processo Filho ...\n");
        printf("A área do terreno é: %.2f m²\n", base * altura);
        printf("......................\n");
    }
    else
    {
        // Pai
        printf("... Processo Pai ...\n");
        printf("O perímetro do terreno é: %.2f m\n", 2 * (base + altura));
        printf("......................\n");
    }

    return 0;
}
