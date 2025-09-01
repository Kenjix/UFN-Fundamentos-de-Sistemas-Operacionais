/* – Crie um programa com dois processos. As medidas de um terreno retangular devem ser
lidas. O processo Filho deve calcular a área do terreno e o processo Pai o perímetro. Todos
os resultados obtidos devem ser mostrados ao usuário.*/

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
    pid_t procID;
    float base, altura = 0;
    float area_retangulo = 0;

    procID = fork();
    prinf("Informe a base do triangulo");
    scanf("%f", &base);

    printf("Informe a altura do triangulo: ");
    scanf("%f", &altura);

    area_retangulo = base * altura;

    return 0;
}