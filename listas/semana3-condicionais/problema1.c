#include <stdio.h>

int main()
{
    // definição de variaveis e entrada
    float peso, altura, imc;

    printf("Digite o peso em kg: ");
    scanf("%f", &peso);

    printf("Digite a altura em metros: ");
    scanf("%f", &altura);

    // processamento
    imc = peso / (altura * altura);

    printf("Seu IMC é: %.2f - ", imc);

    // classificação e saida
    if (imc < 18.5)
    {
        printf("Abaixo do peso\n");
    }
    else if (imc >= 18.5 && imc <= 24.9)
    {
        printf("Peso normal\n");
    }
    else if (imc >= 25.0 && imc <= 29.9)
    {
        printf("Sobrepeso\n");
    }
    else
    {
        printf("Obesidade\n");
    }

    return 0;
}