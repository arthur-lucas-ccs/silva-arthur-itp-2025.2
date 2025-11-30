#include <stdio.h>
#include <stdlib.h>

int *buscaNoVetor(int *v, int n, int valor, int *maior, int *qtd)
{
    int count = 0;
    for (int i = 0; i < n; i++)
        if (v[i] == valor)
            count++;
    *qtd = count;
    if (count == 0)
        return NULL;
    int *indices = (int *)malloc(count * sizeof(int));
    int j = 0;
    for (int i = 0; i < n; i++)
        if (v[i] == valor)
            indices[j++] = i;
    *maior = indices[count - 1];
    return indices;
}

int main()
{
    int n;
    scanf("%d", &n);
    int *v = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        scanf("%d", &v[i]);
    int valor;
    scanf("%d", &valor);
    int maior, qtd;
    int *indices = buscaNoVetor(v, n, valor, &maior, &qtd);
    if (indices == NULL)
        printf("Nenhuma ocorrencia\n");
    else
    {
        printf("%d\n", qtd);
        for (int i = 0; i < qtd; i++)
            printf("%d", indices[i]);
        printf("\n");
        free(indices);
    }
    free(v);
    return 0;
}
