
#include <stdio.h>

int main()
{
    int M;
    scanf("%d", &M);
    int matriz[100][100];
    for (int i = 0; i < M; i++)
        for (int j = 0; j < M; j++)
            scanf("%d", &matriz[i][j]);

    int x;
    scanf("%d", &x);

    for (int i = 0; i < M; i++)
    {
        if (i == x || matriz[x][i] == 1)
            continue;
        for (int j = 0; j < M; j++)
        {
            if (matriz[x][j] == 1 && matriz[i][j] == 1)
            {
                printf("%d\n", i);
                break;
            }
        }
    }
    return 0;
}
