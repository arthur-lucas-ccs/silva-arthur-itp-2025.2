#include <stdio.h>
#include <math.h>

int main()
{
    float a, b, c, delta, x1, x2;

    printf("Digite o coeficiente a: ");
    scanf("%f", &a);

    printf("Digite o coeficiente b: ");
    scanf("%f", &b);

    printf("Digite o coeficiente c: ");
    scanf("%f", &c);

    if (a == 0)
    {
        printf("Não é uma equação do segundo grau!\n");
        return 1;
    }

    delta = b * b - 4 * a * c;

    printf("Delta = %.2f\n", delta);

    if (delta > 0)
    {
        x1 = (-b + sqrt(delta)) / (2 * a);
        x2 = (-b - sqrt(delta)) / (2 * a);
        printf("Duas raízes reais distintas:\n");
        printf("x1 = %.2f\n", x1);
        printf("x2 = %.2f\n", x2);
    }
    else if (delta == 0)
    {
        x1 = -b / (2 * a);
        printf("Uma raiz real:\n");
        printf("x = %.2f\n", x1);
    }
    else
    {
        printf("Não possui raízes reais\n");
    }

    return 0;
}