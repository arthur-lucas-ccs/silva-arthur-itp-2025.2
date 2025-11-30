
#include <stdio.h>

int main()
{
    int m, n;
    scanf("%d %d", &m, &n);
    int sorteados[m], aposta[n];
    for (int i = 0; i < m; i++)
        scanf("%d", &sorteados[i]);
    for (int i = 0; i < n; i++)
        scanf("%d", &aposta[i]);
    int acertos = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (sorteados[i] == aposta[j])
                acertos++;
        }
    }
    printf("%d\n", acertos);
    return 0;
}
