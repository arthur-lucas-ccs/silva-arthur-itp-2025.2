#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

typedef enum
{
    VALOR_NULO = -1,
    JOGADOR_O = 0,
    JOGADOR_X = 1
} valores;

valores *criarVetorBase(size_t tamanho)
{
    valores *vetor = malloc(tamanho * sizeof(valores));
    for (size_t i = 0; i < tamanho; i++)
    {
        vetor[i] = -1;
    }
    return vetor;
}

void set_posicao(valores binario[], int posicao, valores jogador)
{
    binario[posicao] = jogador;
}

void get_tabuleiro(valores *binario)
{
    printf("\n");
    for (int i = 0; i < 9; i++)
    {
        if (i % 3 == 0 && i != 0)
        {
            printf("\n");
        }
        if (binario[i] == JOGADOR_O)
        {
            printf("O ");
        }
        else if (binario[i] == JOGADOR_X)
        {
            printf("X ");
        }
        else
        {
            printf("%d ", i + 1);
        }
    }
    printf("\n");
}

int binarioParaDecimal(valores binario[], valores jogada)
{
    int aux = 0;
    for (int i = 0; i < 9; i++)
    {
        if (binario[i] == jogada)
        {
            aux += pow(2, i);
        }
    }
    return aux;
}

bool verificaGanho(valores binario[], valores jogada)
{
    int decimal = binarioParaDecimal(binario, jogada);
    if ((decimal & 7) == 7 || (decimal & 56) == 56 || (decimal & 448) == 448 || (decimal & 73) == 73 || (decimal & 146) == 146 || (decimal & 296) == 296 || (decimal & 84) == 84 || (decimal & 273) == 273)
    {
        return 1;
    }
    else
        return 0;
}

bool verificaVazios(valores binario[])
{
    for (int i = 0; i < 9; i++)
    {
        if (binario[i] == -1)
        {
            return false; // encontrou um espaço
        }
    }
    return true;
}

valores *copiaVetor(valores *original, size_t tamanho)
{
    valores *copia = malloc(tamanho * sizeof(valores));
    for (size_t i = 0; i < tamanho; i++)
    {
        copia[i] = original[i];
    }
    return copia;
}
valores *jogada(valores *original, int posicao, valores jogador, size_t tamanho)
{
    valores *novoTabuleiro = copiaVetor(original, tamanho);
    set_posicao(novoTabuleiro, posicao, jogador);
    return novoTabuleiro;
}

bool *possiveisJogadas(valores *original, size_t tamanho)
{
    bool *jogadas = malloc(tamanho * sizeof(bool));
    for (size_t i = 0; i < tamanho; i++)
    {
        if (original[i] == -1)
        {
            jogadas[i] = 1; // não tem algo
        }
        else
            jogadas[i] = 0;
    }
    return jogadas;
}

int minimax(valores *tabuleiro, valores jogador, valores eu) // jogador é do momento

{

    if (verificaGanho(tabuleiro, eu) == 1)
    {
        return 1;
    }
    if (verificaGanho(tabuleiro, jogador) == 1)
    {
        return -1;
    }
    else if (verificaVazios(tabuleiro) == 1)
    {
        return 0;
    }

    size_t tamanho = 9;
    bool *jogadas = possiveisJogadas(tabuleiro, tamanho);

    if (jogador == eu)
    {
        int maior = -10000;
        for (size_t i = 0; i < tamanho; i++)
        {
            if (jogadas[i] == 1)
            {
                valores *resultado = jogada(tabuleiro, i, eu, tamanho);
                int valor = minimax(resultado, (eu == JOGADOR_X) ? eu == JOGADOR_O : eu == JOGADOR_X, eu);
                free(resultado);
                if (valor > maior)
                {
                    maior = valor;
                }
            }
        }
        free(jogadas);
        return maior;
    }
    else
    {
        int maior = 10000;
        for (size_t i = 0; i < tamanho; i++)
        {
            if (jogadas[i] == 1)
            {
                valores *resultado = jogada(tabuleiro, i, jogador, tamanho);
                int valor = minimax(resultado, (eu == JOGADOR_X) ? eu == JOGADOR_O : eu == JOGADOR_X, eu);
                free(resultado);
                if (valor < maior)
                {
                    maior = valor;
                }
            }
        }
        free(jogadas);
        return maior;
    }
}

int melhorJogada(valores *tabuleiro, valores eu)
{
    size_t tamanho = 9;
    bool *jogadas = possiveisJogadas(tabuleiro, tamanho);
    int maior = -1000000;
    int melhor = 0;
    for (size_t i = 0; i < tamanho; i++)
    {
        printf("possivel jogada: %d\n", jogadas[i]);
        if (jogadas[i] == 1)
        {
            valores *resultado = jogada(tabuleiro, i, eu, tamanho);
            int valor = minimax(resultado, (eu == JOGADOR_X) ? eu == JOGADOR_O : eu == JOGADOR_X, eu);
            printf("i = %d\n", i);
            printf("valor: %d\n", valor);
            printf("decimal: %d\n", binarioParaDecimal(resultado, eu));
            printf("verifica: %d\n", verificaGanho(resultado, eu));
            printf("eu: %d\n", eu);
            free(resultado);
            if (valor > maior)
            {
                melhor = i;
                maior = valor;
            }
        }
    }
    printf("ultimo i: %d", melhor);
    free(jogadas);
    return melhor;
}

/*
void copiaVetor(valores vetorC[], valores vetorV[])
{
    for (int i = 0; i < 9; i++)
    {
        vetorV[i] = vetorC[i];
    }
}*/

int main()
{
    size_t posicoes = 9;
    valores *tabuleiro = criarVetorBase(posicoes);
    set_posicao(tabuleiro, 0, JOGADOR_O);
    set_posicao(tabuleiro, 2, JOGADOR_X);
    set_posicao(tabuleiro, 8, JOGADOR_X);
    set_posicao(tabuleiro, 7, JOGADOR_O);

    bool *possiveis = possiveisJogadas(tabuleiro, posicoes);
    printf("minimax jogada X:%d\n", melhorJogada(tabuleiro, JOGADOR_X));
    get_tabuleiro(tabuleiro);
    return 0;
}