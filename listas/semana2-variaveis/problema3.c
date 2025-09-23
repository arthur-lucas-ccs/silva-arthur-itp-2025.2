#include <stdio.h>
#include <math.h>

int main()
{
    // definição de variaveis
    float capital, taxa, tempo, montante;

    // entrada
    printf("Digite o capital inicial: ");
    scanf("%f", &capital);

    printf("Digite a taxa de juros (%%): ");
    scanf("%f", &taxa);

    printf("Digite o tempo em anos: ");
    scanf("%f", &tempo);

    // processamento
    montante = capital * pow(1 + taxa / 100, tempo);

    // saida
    printf("Montante final: R$ %.2f\n", montante);

    return 0;
}