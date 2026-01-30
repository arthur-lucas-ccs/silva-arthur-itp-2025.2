#include "manipulacaoTabuleiro.h"
#include "minimax.h"

// cria um novo tabuleiro, e faz uma jogada
valores *jogada(valores *original, int posicao, valores jogador, size_t tamanho)
{
    valores *novoTabuleiro = copiarVetor(original, tamanho);
    setJogada(novoTabuleiro, posicao, jogador);
    return novoTabuleiro;
}

// retorna em um vetor de booleano as possiveis jogadas (os espaços vazios)
bool *possiveisJogadas(valores *original, size_t tamanho)
{
    bool *jogadas = malloc(tamanho * sizeof(bool));
    for (size_t i = 0; i < tamanho; i++)
    {
        if (original[i] == -1)
        {
            jogadas[i] = 1; // não tem algo, então é uma posição valida
        }
        else
            jogadas[i] = 0; // tem algo, não é posição valida
    }
    return jogadas;
}

int minimax(valores *tabuleiro, valores jogador, valores eu) // jogador é quem vai fazer a jogada, enquanto eu é o ponto de vista que buscamos
{
    // condições de parada do minimax
    if (verificaGanho(tabuleiro, eu))
    {
        return 1;
    }
    else if (verificaGanho(tabuleiro, (eu == JOGADOR_X) ? JOGADOR_O : JOGADOR_X))
    {
        return -1;
    }
    else if (!temVazios(tabuleiro))
    {
        return 0;
    }

    // criação das possiveis jogadas
    size_t tamanho = 9;
    bool *jogadas = possiveisJogadas(tabuleiro, tamanho);

    // é a posição onde buscamos maximizar os ganhos
    if (jogador == eu)
    {
        int valor;
        int maior = -10000;
        for (size_t i = 0; i < tamanho; i++)
        {
            if (i == 0)
            {
                //   printf("-----------------------------------------------------\n");
            }
            if (jogadas[i] == 1)
            {
                // percorremos as possiveis jogadas, aplicando o minimax nos tabuleiros resultantes
                valores *resultado = jogada(tabuleiro, i, eu, tamanho);
                valor = minimax(resultado, (eu == JOGADOR_X) ? JOGADOR_O : JOGADOR_X, eu);
                free(resultado);
                if (valor > maior) // o valor do minimax é a melhor posição
                {
                    maior = valor;
                    // printf("esse eh o maior da jogada i: %d\n e esse eh o valor: %d\n", i, valor);
                }
            }
            if (i == 0)
            {
                //   printf("-----------------------------------------------------\n");
            }
        }
        free(jogadas);
        return maior;
    }
    else // posição onde buscamos minimizar, nesse caso será praticamente a mesma coisa do maximizar, porém buscamos minimizar invertendo o maior para menor.
    {
        int valor;
        int menor = +10000;
        for (size_t i = 0; i < tamanho; i++)
        {
            if (jogadas[i] == 1)
            {
                valores *resultado = jogada(tabuleiro, i, jogador, tamanho);
                valor = minimax(resultado, eu, eu);
                free(resultado);
                if (valor < menor)
                {
                    menor = valor;
                    // printf("esse eh o menor valor da jogada i: %d\n e esse eh o valor: %d\n", i, valor);
                }
            }
        }
        free(jogadas);
        return menor;
    }
}

// função que aplica minimax, buscando as melhores jogadas de acordo com o tabuleiro, retornando a jogada onde acha a melhor posição.
int melhorJogada(valores *tabuleiro, valores eu)
{
    size_t tamanho = 9;
    bool *jogadas = possiveisJogadas(tabuleiro, tamanho);
    int maiorJogada = -1000000;
    int melhor;
    for (size_t j = 0; j < tamanho; j++)
    {
        if (jogadas[j] == 1)
        {
            valores *resultado = jogada(tabuleiro, j, eu, tamanho);
            int melhorValor = minimax(resultado, (eu == JOGADOR_X) ? JOGADOR_O : JOGADOR_X, eu);
            free(resultado);
            if (melhorValor > maiorJogada)
            {
                melhor = j;
                maiorJogada = melhorValor;
            }
        }
    }
    free(jogadas);
    return melhor;
}
