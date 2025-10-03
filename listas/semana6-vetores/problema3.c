#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int altura[30];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &altura[i]);
    }

    // 1. Encontrar o maior valor
    int maior = altura[0];
    for (int i = 1; i < n; i++)
    {
        if (altura[i] > maior)
        {
            maior = altura[i];
        }
    }

    // 2. Encontrar as duas posições do maior valor
    int primeira = -1, segunda = -1;
    for (int i = 0; i < n; i++)
    {
        if (altura[i] == maior)
        {
            if (primeira == -1)
                primeira = i;
            else
            {
                segunda = i;
                break; // já encontramos as duas
            }
        }
    }

    // 3. Calcular e imprimir a distância
    int comprimento = segunda - primeira;
    printf("%d\n", comprimento);

    return 0;
}
