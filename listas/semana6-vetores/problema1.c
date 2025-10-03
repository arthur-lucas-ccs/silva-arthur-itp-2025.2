#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int gabarito[20], aluno[20];
    int i, acertos = 0;

    // Lê o gabarito
    for (i = 0; i < n; i++)
    {
        scanf("%d", &gabarito[i]);
    }

    // Lê as respostas do aluno
    for (i = 0; i < n; i++)
    {
        scanf("%d", &aluno[i]);
    }

    // Conta acertos
    for (i = 0; i < n; i++)
    {
        if (gabarito[i] == aluno[i])
        {
            acertos++;
        }
    }

    // Imprime resultado
    if (acertos == 1)
    {
        printf("1 acerto\n");
    }
    else
    {
        printf("%d acertos\n", acertos);
    }

    return 0;
}
