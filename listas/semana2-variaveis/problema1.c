#include <stdio.h>

int main()
{
    // definição de variaveis
    float peso, altura, imc;

    // entrada
    printf("Digite o peso em kg: ");
    scanf("%f", &peso);

    printf("Digite a altura em metros: ");
    scanf("%f", &altura);

    // processamento
    imc = peso / (altura * altura);

    // saida
    printf("Seu IMC é: %.2f\n", imc);

    return 0;
}