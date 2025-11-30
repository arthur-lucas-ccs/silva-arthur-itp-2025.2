#include <stdio.h>
#include <string.h>

int main()
{
    int chuvas[12], i, j, temp;
    char meses[12][20] = {"Janeiro", "Fevereiro", "Marco", "Abril", "Maio", "Junho", "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"};
    char temp_mes[20];

    for (i = 0; i < 12; i++)
        scanf("%d", &chuvas[i]);

    for (i = 0; i < 12; i++)
    {
        for (j = i + 1; j < 12; j++)
        {
            if (chuvas[i] < chuvas[j])
            {
                temp = chuvas[i];
                chuvas[i] = chuvas[j];
                chuvas[j] = temp;
                strcpy(temp_mes, meses[i]);
                strcpy(meses[i], meses[j]);
                strcpy(meses[j], temp_mes);
            }
        }
    }

    for (i = 0; i < 12; i++)
    {
        printf("%s %d\n", meses[i], chuvas[i]);
    }
    return 0;
}
