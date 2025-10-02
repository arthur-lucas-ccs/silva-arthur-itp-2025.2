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
    if (binario[posicao] == -1)
    {
        binario[posicao] = jogador;
    }
    else
    {
        printf("Espaco ocupado ou invalido.\n");
    }
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
            return false; // encontrou um espaço (trocar)
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

int minimax(valores *tabuleiro, valores jogador, valores eu) // jogador é do momento, eu é  posição do max

{

    if (verificaGanho(tabuleiro, eu) == 1)
    {
        return 1;
    }
    else if (verificaGanho(tabuleiro, jogador) == 1)
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
        int valor;
        int maior = -10000;
        for (size_t i = 0; i < tamanho; i++)
        {
            if (jogadas[i] == 1)
            {
                valores *resultado = jogada(tabuleiro, i, eu, tamanho);
                valor = minimax(resultado, (eu == JOGADOR_X) ? JOGADOR_O : JOGADOR_X, eu);
                free(resultado);
                if (valor > maior)
                {
                    maior = valor;
                    printf("valor que foi atualizado: %d\n", valor);
                }
            }
        }
        return maior;
    }
    else
    {
        int valor;
        int maior = +10000;
        for (size_t i = 0; i < tamanho; i++)
        {
            if (jogadas[i] == 1)
            {
                valores *resultado = jogada(tabuleiro, i, jogador, tamanho);
                valor = minimax(resultado, (eu == JOGADOR_X) ? JOGADOR_O : JOGADOR_X, eu);
                free(resultado);
                if (valor < maior)
                {
                    maior = valor;
                    printf("valor que foi atualizado: %d\n", valor);
                }
            }
        }
        return maior;
    }
}

int melhorJogada(valores *tabuleiro, valores eu)
{
    size_t tamanho = 9;
    bool *jogadas = possiveisJogadas(tabuleiro, tamanho);
    int maior = -1000000;
    int melhor = 0;
    int valormelhor;
    for (size_t j = 0; j < tamanho; j++)
    {
        if (jogadas[j] == 1)
        {
            valores *resultado = jogada(tabuleiro, j, eu, tamanho);
            valormelhor = minimax(resultado, (eu == JOGADOR_X) ? JOGADOR_O : JOGADOR_X, eu);
            if (valormelhor > maior)
            {
                melhor = j;
                maior = valormelhor;
            }
        }
    }
    printf("ultimo j: %d\n", melhor);
    return melhor;
}

int main()
{
    size_t posicoes = 9;
    valores *tabuleiro = criarVetorBase(posicoes);
    int posicao;
    char resposta;
    printf("Se Voce quer ser X, digite: 'x', se quiser jogar com O, digite: 'o'.\n");
    scanf(" %c", &resposta);
    valores eu = (resposta == 'x') ? JOGADOR_X : JOGADOR_O;
    valores ia = (eu == JOGADOR_X) ? JOGADOR_O : JOGADOR_X;

    while ((verificaGanho(tabuleiro, eu)) != 1 && (verificaGanho(tabuleiro, (eu == JOGADOR_X) ? JOGADOR_O : JOGADOR_X) != 1) && (verificaVazios(tabuleiro) == false))
    {
        printf("0 Para ver a posicao, e 1 para fazer uma jogada\n");
        scanf(" %c", &resposta);
        if (resposta == '0')
        {
            get_tabuleiro(tabuleiro);
        }
        else if (resposta == '1')
        {
            printf("Digite a posicao de 1 a 9: \n");
            scanf("%d", &posicao);
            set_posicao(tabuleiro, posicao, eu);
            set_posicao(tabuleiro, melhorJogada(tabuleiro, ia), ia);
        }
    }
    printf("Acabou e esse foi o tabuleiro");
    get_tabuleiro(tabuleiro);

    return 0;
}