#include <stdio.h>
#include <math.h>

int main()
{
    float capital, taxa, tempo, montante;

    printf("Digite o capital inicial: ");
    scanf("%f", &capital);

    printf("Digite a taxa de juros (%%): ");
    scanf("%f", &taxa);

    printf("Digite o tempo em anos: ");
    scanf("%f", &tempo);

    montante = capital * pow(1 + taxa / 100, tempo);

    printf("Montante final: R$ %.2f\n", montante);

    return 0;
}