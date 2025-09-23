#include <stdio.h>

int main()
{
    // definição e entrada dos dados
    float consumo, valor;
    char tipo;

    printf("Digite o consumo em kWh: ");
    scanf("%f", &consumo);

    printf("Digite o tipo de consumidor (R, C ou I): ");
    scanf(" %c", &tipo);

    // Classificação e processamento
    switch (tipo)
    {
    case 'R':
    case 'r':
        valor = 15.00 + (consumo * 0.60);
        break;
    case 'C':
    case 'c':
        valor = 15.00 + (consumo * 0.48);
        break;
    case 'I':
    case 'i':
        valor = 15.00 + (consumo * 1.29);
        break;
    default:
        printf("Tipo de consumidor inválido!\n");
        return 1;
    }

    // saida
    printf("Valor total da conta: R$ %.2f\n", valor);

    return 0;
}