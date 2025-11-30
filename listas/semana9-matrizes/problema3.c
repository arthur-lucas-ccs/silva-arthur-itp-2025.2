
#include <stdio.h>

int main()
{
    int M;
    scanf("%d", &M);
    int gols[20][20];
    for (int i = 0; i < M; i++)
        for (int j = 0; j < M; j++)
            scanf("%d", &gols[i][j]);

    int empates = 0;
    for (int i = 0; i < M; i++)
    {
        for (int j = i + 1; j < M; j++)
        {
            if (gols[i][j] == gols[j][i])
                empates++;
        }
    }
    printf("%d\n", empates);
    return 0;
}
