#include <stdio.h>

int main()
{
    char febre, dorCabeca, dorCorpo, tosse;

    printf("Tem febre? (S/N): ");
    scanf(" %c", &febre);

    printf("Tem dor de cabeça? (S/N): ");
    scanf(" %c", &dorCabeca);

    printf("Tem dor no corpo? (S/N): ");
    scanf(" %c", &dorCorpo);

    printf("Tem tosse? (S/N): ");
    scanf(" %c", &tosse);

    // Convertendo para maiúsculas para facilitar a comparação
    if (febre >= 'a')
        febre -= 32;
    if (dorCabeca >= 'a')
        dorCabeca -= 32;
    if (dorCorpo >= 'a')
        dorCorpo -= 32;
    if (tosse >= 'a')
        tosse -= 32;

    if (febre == 'S' && dorCabeca == 'S' && dorCorpo == 'S')
    {
        printf("Possível gripe\n");
    }
    else if (tosse == 'S' && febre == 'S')
    {
        printf("Possível resfriado\n");
    }
    else if (dorCabeca == 'S' && febre == 'N' && dorCorpo == 'N' && tosse == 'N')
    {
        printf("Possível enxaqueca\n");
    }
    else if (febre == 'S' && dorCabeca == 'N' && dorCorpo == 'N' && tosse == 'N')
    {
        printf("Consulte um médico\n");
    }
    else if (febre == 'N' && dorCabeca == 'N' && dorCorpo == 'N' && tosse == 'N')
    {
        printf("Você parece estar bem\n");
    }
    else
    {
        printf("Consulte um médico para avaliação\n");
    }

    return 0;
}