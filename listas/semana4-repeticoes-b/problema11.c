#include <stdio.h>
int main()
{
    char correspondente, primeira_linha;
    // seja um tabuleiro onde as colunas são letras de "a" a "d", enquanto as linhas são numeros de 1 a 4
    // os casos onde a rainha não se interceptam é quando são dispostas de forma que o façam um "L"
    for (int i = 1; i <= 4; i++)
    { // i será as letras
        for (int j = 1; j <= 4; j++)
        {
            if (i == 1 && (j != 1 || j != 4))
            { // rainha inicial
                switch (j)
                {
                case 1:
                    correspondente = 'a';
                    break;
                case 2:
                    correspondente = 'b';
                    break;
                case 3:
                    correspondente = 'c';
                    break;
                case 4:
                    correspondente = 'd';
                    break;
                default:
                    break;
                }
                if (j == 2)
                {
                    primeira_linha = 'p';
                    printf("primeiro caso:\n");
                    printf("%d%c\n", i, correspondente);
                }
                else
                {
                    primeira_linha = 'i';
                    printf("segundo caso:\n");
                    printf("%d%c\n", i, correspondente);
                }
            }
        }
    }
}