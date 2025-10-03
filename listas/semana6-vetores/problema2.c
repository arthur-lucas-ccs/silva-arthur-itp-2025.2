#include <stdio.h>

int main()
{
    int m, n;
    scanf("%d %d", &m, &n);

    int possui[1001] = {0}; // índice 1 a m

    // Ler figurinhas que possui
    for (int i = 0; i < n; i++)
    {
        int fig;
        scanf("%d", &fig);
        possui[fig] = 1; // marca que tem essa figurinha
    }

    // Imprimir faltantes
    for (int i = 1; i <= m; i++)
    {
        if (!possui[i])
        {
            printf("%d ", i);
        }
    }
    printf("\n");

    return 0;
}
