#include <stdio.h>
#include <stdlib.h>

// Função para calcular a soma dos divisores próprios
int soma_divisores_proprios(int num)
{
    int soma = 0;
    for (int i = 1; i <= num / 2; i++)
    {
        if (num % i == 0)
        {
            soma += i;
        }
    }
    return soma;
}

int main()
{
    int A, B, soma_A, soma_B;

    printf("Digite o primeiro numero: ");
    scanf("%d", &A);
    printf("Digite o segundo numero: ");
    scanf("%d", &B);

    soma_A = soma_divisores_proprios(A);
    soma_B = soma_divisores_proprios(B);

    // Verifica se são colegas
    if (abs(soma_A - B) <= 2 && abs(soma_B - A) <= 2)
    {
        printf("S\n");
    }
    else
    {
        printf("N\n");
    }

    return 0;
}