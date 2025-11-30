#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char placa[11];
    scanf("%s", placa);
    int len = strlen(placa);
    int brasileiro = 0, mercosul = 0;

    if (len == 8 &&
        isupper(placa[0]) && isupper(placa[1]) && isupper(placa[2]) &&
        placa[3] == '-' &&
        isdigit(placa[4]) && isdigit(placa[5]) && isdigit(placa[6]) && isdigit(placa[7]))
    {
        brasileiro = 1;
    }

    if (len == 7 &&
        isupper(placa[0]) && isupper(placa[1]) && isupper(placa[2]) &&
        isdigit(placa[3]) &&
        isupper(placa[4]) &&
        isdigit(placa[5]) && isdigit(placa[6]))
    {
        mercosul = 1;
    }

    if (brasileiro)
        printf("brasileiro\n");
    else if (mercosul)
        printf("mercosul\n");
    else
        printf("inválido\n");

    return 0;
}
