
#include <stdio.h>

int main()
{
    int M;
    scanf("%d", &M);
    int preco[10][10];
    for (int i = 0; i < M; i++)
        for (int j = 0; j < M; j++)
            scanf("%d", &preco[i][j]);

    int X, Z;
    scanf("%d %d", &X, &Z);

    int menor = preco[X][Z], inter = -1;
    for (int k = 0; k < M; k++)
    {
        if (k == X || k == Z)
            continue;
        int soma = preco[X][k] + preco[k][Z];
        if (soma < menor)
        {
            menor = soma;
            inter = k;
        }
    }

    if (inter == -1)
        printf("%d-%d %d\n", X, Z, menor);
    else
        printf("%d-%d-%d %d\n", X, inter, Z, menor);

    return 0;
}
