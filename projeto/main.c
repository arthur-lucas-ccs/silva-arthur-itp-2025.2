#include <stdio.h>
#include <stdbool.h>
#include <math.h>

void set_posicao(bool binario[], int posicao)
{
    binario[posicao] = 1;
}

void get_tabuleiro(bool binario[])
{
    for (int i = 0; i < 9; i++)
    {
        if (i % 3 == 0 && i != 0)
        {
            printf("\n");
        }
        if (binario[i])
        {
            printf("X ");
        }
        else
        {
            printf("%d ", i + 1);
        }
    }
}

int binarioParaDecimal(bool binario[])
{
    int aux = 0;
    for (int i = 0; i < 9; i++)
    {
        aux += binario[i] * pow(2, i);
    }
    return aux;
}

bool verificaGanho(bool binario[])
{
    int decimal = binarioParaDecimal(binario);
    if (decimal & 7 == 7 || decimal & 56 == 56 || decimal & 448 == 448 || decimal & 73 == 73 || decimal & 146 == 146 || decimal & 296 == 296 || decimal & 84 == 84 || decimal & 273 == 273)
    {
        return 1;
    }
    else
        return 0;
}
int main()
{
    bool tabuleiro[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    set_posicao(tabuleiro, 0);
    set_posicao(tabuleiro, 4);
    set_posicao(tabuleiro, 8);
    set_posicao(tabuleiro, 6);
    get_tabuleiro(tabuleiro);
    printf("\n%d\n", binarioParaDecimal(tabuleiro));
    printf("%d", verificaGanho(tabuleiro));
}