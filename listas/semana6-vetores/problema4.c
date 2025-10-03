#include <stdio.h>

int main()
{
    int v[10];
    int visitado[10] = {0}; // Marca se a ilha já foi visitada

    // Lê as sugestões dos nativos de cada ilha
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &v[i]);
    }

    int ilha = 0;

    while (1)
    {
        if (visitado[ilha])
        {
            printf("%d\n", ilha); // Ilha visitada pela segunda vez
            break;
        }
        visitado[ilha] = 1; // Marca como visitada
        ilha = v[ilha];     // Vai para a próxima ilha sugerida
    }

    return 0;
}
