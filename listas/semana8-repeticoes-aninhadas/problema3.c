#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int largada[n], chegada[n], ganhos[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &largada[i]);
    for (int i = 0; i < n; i++)
        scanf("%d", &chegada[i]);
    for (int i = 0; i < n; i++)
    {
        int piloto = chegada[i];
        int pos_largada;
        for (pos_largada = 0; pos_largada < n; pos_largada++)
        {
            if (largada[pos_largada] == piloto)
                break;
        }
        ganhos[piloto - 1] = pos_largada - i;
    }
    int max_ganho = ganhos[0], count = 0, piloto_max = 0;
    for (int i = 0; i < n; i++)
    {
        if (ganhos[i] > max_ganho)
        {
            max_ganho = ganhos[i];
            piloto_max = i + 1;
            count = 1;
        }
        else if (ganhos[i] == max_ganho)
        {
            count++;
        }
    }
    if (max_ganho <= 0 || count > 1)
        printf("empate\n");
    else
        printf("%d\n", piloto_max);
    return 0;
}
