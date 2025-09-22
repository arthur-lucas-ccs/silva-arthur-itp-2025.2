#include <stdio.h>
#include <math.h>

int main()
{
    float a, b, c, temp;

    printf("Digite os três lados do triângulo: ");
    scanf("%f %f %f", &a, &b, &c);

    // Ordenar os lados (a será o maior)
    if (a < b)
    {
        temp = a;
        a = b;
        b = temp;
    }
    if (a < c)
    {
        temp = a;
        a = c;
        c = temp;
    }
    if (b < c)
    {
        temp = b;
        b = c;
        c = temp;
    }

    // Verificar se pode formar triângulo
    if (a >= b + c)
    {
        printf("Não pode formar um triângulo!\n");
        return 1;
    }

    printf("Pode formar um triângulo: ");

    // Classificação quanto aos lados
    if (a == b && b == c)
    {
        printf("Equilátero ");
    }
    else if (a == b || b == c || a == c)
    {
        printf("Isósceles ");
    }
    else
    {
        printf("Escaleno ");
    }

    // Classificação quanto aos ângulos
    float a2 = a * a;
    float b2c2 = b * b + c * c;

    if (fabs(a2 - b2c2) < 0.001)
    { // Usando tolerância para comparação de floats
        printf("Retângulo\n");
    }
    else if (a2 < b2c2)
    {
        printf("Acutângulo\n");
    }
    else
    {
        printf("Obtusângulo\n");
    }

    return 0;
}