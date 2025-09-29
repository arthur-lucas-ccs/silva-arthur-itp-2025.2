#include <stdio.h>
#include <stdbool.h>
#include <math.h>

typedef enum
{
    VALOR_NULO = -1,
    JOGADOR_O = 0,
    JOGADOR_X = 1
} valores;

void set_posicao(valores binario[], int posicao, valores jogador)
{
    binario[posicao] = jogador;
}

void get_tabuleiro(valores binario[])
{
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
        if (binario[i] == VALOR_NULO)
        {
            return true;
        }
    }
    return false;
}

void copiaVetor(valores vetorC[], valores vetorV[])
{
    for (int i = 0; i < 9; i++)
    {
        vetorV[i] = vetorC[i];
    }
}

void possiveisJogadas(valores binario[], int posicoes[], int *count)
{
    *count = 0;
    for (int i = 0; i < 9; i++)
    {
        if (binario[i] == VALOR_NULO)
        {
            posicoes[*count] = i;
            (*count)++;
        }
    }
}

int minimax(valores binario[], valores jogador, valores eu)
{
    bool winEu = verificaGanho(binario, eu);
    bool winJogador = verificaGanho(binario, jogador);
    if (winEu)
    {
        return 1;
    }
    else if (winJogador)
    {
        return -1;
    }
    else if (!verificaVazios(binario))
    {
        return 0;
    }

    int posicoes[9];
    int count;
    possiveisJogadas(binario, posicoes, &count);

    if (jogador == eu)
    { // max
        int melhor = -1000000;
        for (int i = 0; i < count; i++)
        {
            valores novoVetor[9];
            copiaVetor(binario, novoVetor);
            set_posicao(novoVetor, posicoes[i], eu);
            valores oponente = (eu == JOGADOR_X) ? JOGADOR_O : JOGADOR_X;
            int valor = minimax(novoVetor, oponente, eu);
            if (valor > melhor)
            {
                melhor = valor;
            }
        }
        return melhor;
    }
    else
    { // min
        int melhor = +1000000;
        for (int i = 0; i < count; i++)
        {
            valores novoVetor[9];
            copiaVetor(binario, novoVetor);
            set_posicao(novoVetor, posicoes[i], jogador);
            valores oponente = (jogador == JOGADOR_X) ? JOGADOR_O : JOGADOR_X;
            int valor = minimax(novoVetor, oponente, eu);
            if (valor < melhor)
            {
                melhor = valor;
            }
        }
        return melhor;
    }
}

int melhorPosicao(valores binario[], valores eu)
{
    int posicoes[9];
    int count;
    possiveisJogadas(binario, posicoes, &count);

    if (count == 0)
        return -1;

    int melhorAcao = posicoes[0];
    int melhor = -1000000;

    for (int i = 0; i < count; i++)
    {
        valores novoVetor[9];
        copiaVetor(binario, novoVetor);
        set_posicao(novoVetor, posicoes[i], eu);
        valores oponente = (eu == JOGADOR_X) ? JOGADOR_O : JOGADOR_X;
        int valor = minimax(novoVetor, oponente, eu);
        if (valor > melhor)
        {
            melhor = valor;
            melhorAcao = posicoes[i];
        }
    }
    return melhorAcao;
}

int main()
{
    valores tabuleiro[9] = {-1, -1, -1, -1, -1, -1, -1, -1, -1};

    // Configuração do tabuleiro
    set_posicao(tabuleiro, 2, JOGADOR_O);
    set_posicao(tabuleiro, 3, JOGADOR_X);
    set_posicao(tabuleiro, 8, JOGADOR_O);
    set_posicao(tabuleiro, 7, JOGADOR_X);
    set_posicao(tabuleiro, 0, JOGADOR_X);

    printf("Tabuleiro atual:\n");
    get_tabuleiro(tabuleiro);
    printf("\n\n");

    // Testa melhores jogadas
    printf("Melhor jogada para X: %d\n", melhorPosicao(tabuleiro, JOGADOR_X));
    printf("Melhor jogada para O: %d\n", melhorPosicao(tabuleiro, JOGADOR_O));

    return 0;
}