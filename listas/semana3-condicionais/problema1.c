#include <stdio.h>

int main()
{
    float peso, altura, imc;

    printf("Digite o peso em kg: ");
    scanf("%f", &peso);

    printf("Digite a altura em metros: ");
    scanf("%f", &altura);

    imc = peso / (altura * altura);

    printf("Seu IMC é: %.2f - ", imc);

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