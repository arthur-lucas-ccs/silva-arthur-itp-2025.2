
#include <stdio.h>
#include <string.h>

int main()
{
    char campo[21];
    int indice;
    scanf("%s", campo);
    scanf("%d", &indice);
    int len = strlen(campo);
    if (campo[indice] == 'x')
    {
        printf("bum!\n");
    }
    else
    {
        int bombas = 0;
        if (indice > 0 && campo[indice - 1] == 'x')
            bombas++;
        if (indice < len - 1 && campo[indice + 1] == 'x')
            bombas++;
        printf("%d\n", bombas);
    }
    return 0;
}
