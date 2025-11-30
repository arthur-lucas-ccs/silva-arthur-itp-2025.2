
#include <stdio.h>

int main()
{
    int M, N;
    scanf("%d %d", &M, &N);
    int campo[10][10], coberto[10][10] = {0};
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            scanf("%1d", &campo[i][j]);

    for (int i = 1; i < M - 1; i++)
    {
        for (int j = 1; j < N - 1; j++)
        {
            if (campo[i][j] == 2)
            {
                if (campo[i - 1][j] == 1)
                    coberto[i - 1][j] = 1;
                if (campo[i + 1][j] == 1)
                    coberto[i + 1][j] = 1;
                if (campo[i][j - 1] == 1)
                    coberto[i][j - 1] = 1;
                if (campo[i][j + 1] == 1)
                    coberto[i][j + 1] = 1;
            }
        }
    }

    int cobertos = 0, nao_cobertos = 0;
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            if (campo[i][j] == 1)
                if (coberto[i][j])
                    cobertos++;
                else
                    nao_cobertos++;

    printf("%d %d\n", cobertos, nao_cobertos);
    return 0;
}
