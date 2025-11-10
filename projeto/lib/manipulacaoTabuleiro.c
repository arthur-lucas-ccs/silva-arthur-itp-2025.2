#include "manipulacaoTabuleiro.h"
#include "minimax.h"

void print(char name[])
{
    for (int i = 0; i < strlen(name); i++)
    {
        printf("%c", name[i]);
        Sleep(30);
    }
    printf("\n");
}

// função responsavel por criar um tabuleiro base para nosso jogo da velha.
valores *criarVetorBase(size_t tamanho)
{
    valores *vetor = malloc(tamanho * sizeof(valores));
    for (size_t i = 0; i < tamanho; i++)
    {
        vetor[i] = -1;
    }
    return vetor;
}

// se houver um espaço livre, retorna 1 e preenche com o jogador.
bool setPosicao(valores tabuleiro[], int posicao, valores jogador)
{
    if (tabuleiro[posicao] == -1)
    {
        tabuleiro[posicao] = jogador;
        return true;
    }
    else if (tabuleiro[posicao] != -1)
    {
        return false;
    }
}

// imprime no terminal o tabuleiro
void getTabuleiro(valores *tabuleiro)
{
    printf("\n");
    for (int i = 0; i < 9; i++)
    {
        if (i % 3 == 0 && i != 0)
        {
            printf("\n");
        }
        if (tabuleiro[i] == JOGADOR_O)
        {
            printf("O ");
        }
        else if (tabuleiro[i] == JOGADOR_X)
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

/*retorna um numero inteiro, de acordo com o tabuleiro de "binarios" de acordo com um certo ponto de vista,
falo sobre binarios, pois se tivermos um ponto de vista, podemos dizer se uma posição está preenchida com o valor
que estamos analisando ou se não está, ai nesse caso fazemos nesse tabuleiro a transformação de binario para decimal*/
int valoresParaDecimal(valores *tabuleiro, valores jogada)
{
    int aux = 0;
    for (int i = 0; i < 9; i++)
    {
        if (tabuleiro[i] == jogada)
        {
            aux += pow(2, i);
        }
    }
    return aux;
}

// verifica as possiveis vitorias, de acordo com o decimal.
bool verificaGanho(valores *tabuleiro, valores jogada)
{
    int decimal = valoresParaDecimal(tabuleiro, jogada);
    if ((decimal & 7) == 7 || (decimal & 56) == 56 || (decimal & 448) == 448 || (decimal & 73) == 73 || (decimal & 146) == 146 || (decimal & 296) == 296 || (decimal & 84) == 84 || (decimal & 273) == 273)
    {
        return 1; // o valor de jogada ganhou
    }
    else
        return 0; // o valor de jogada perdeu
}

// verifica se tem vazios
bool temVazios(valores tabuleiro[])
{
    for (int i = 0; i < 9; i++)
    {
        if (tabuleiro[i] == -1)
        {
            return true; // encontrou um espaço
        }
    }
    return false; // não encontrou espaço
}

// Deep Copy
valores *copiarVetor(valores *original, size_t tamanho)
{
    valores *copia = malloc(tamanho * sizeof(valores));
    for (size_t i = 0; i < tamanho; i++)
    {
        copia[i] = original[i];
    }
    return copia;
}
