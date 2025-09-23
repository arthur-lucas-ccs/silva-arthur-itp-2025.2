#include <stdio.h>

int main()
{
    // definição
    int num1, num2;

    // entrada
    printf("Digite o primeiro número inteiro: ");
    scanf("%d", &num1);

    printf("Digite o segundo número inteiro: ");
    scanf("%d", &num2);

    // processamento e saida
    printf("Soma: %d\n", num1 + num2);
    printf("Diferença: %d\n", num1 - num2);
    printf("Produto: %d\n", num1 * num2);

    // processamento da divisão necessario para otimizar a saída
    if (num2 != 0)
    {
        printf("Divisão real: %.2f\n", (float)num1 / num2);
        printf("Resto da divisão: %d\n", num1 % num2);
    }
    else
    {
        printf("Divisão por zero não é permitida!\n");
    }

    printf("Média: %.2f\n", (num1 + num2) / 2.0);

    return 0;
}