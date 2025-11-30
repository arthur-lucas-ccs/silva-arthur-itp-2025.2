#include <stdio.h>
#include <stdlib.h>

int* alocarVetor(int n) {
    return (int*)malloc(n * sizeof(int));
}

int* somaVetores(int *u, int *v, int n1, int n2) {
    if (n1 != n2) return NULL;
    int *soma = (int*)malloc(n1 * sizeof(int));
    for (int i = 0; i < n1; i++)
        soma[i] = u[i] + v[i];
    return soma;
}

int main() {
    int n1, n2;
    scanf("%d %d", &n1, &n2);
    int *u = alocarVetor(n1);
    int *v = alocarVetor(n2);
    for (int i = 0; i < n1; i++) scanf("%d", &u[i]);
    for (int i = 0; i < n2; i++) scanf("%d", &v[i]);
    int *soma = somaVetores(u, v, n1, n2);
    if (soma == NULL) printf("dimensoes incompativeis\n");
    else {
        for (int i = 0; i < n1; i++)
            printf("%d ", soma[i]);
        printf("\n");
        free(soma);
    }
    free(u);
    free(v);
    return 0;
}
