#ifndef MANIPULACAO_TABULEIRO_H
#define MANIPULACAO_TABULEIRO_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <windows.h>
#include <unistd.h>

typedef enum
{
    VALOR_NULO = -1,
    JOGADOR_O = 0,
    JOGADOR_X = 1
} valores;

void print(char nome[]);
valores *criarVetorBase(size_t tamanho);
void setHistorico(int historico[3][9], int posicao, int jogador, int turno);
void getHistorico(int historico[3][9]);
bool setPosicao(int historico[3][9], valores tabuleiro[], int posicao, valores jogador, int turno);
bool setJogada(valores tabuleiro[], int posicao, valores jogador);
void getTabuleiro(valores *tabuleiro);
int valoresParaDecimal(valores *tabuleiro, valores jogada);
bool verificaGanho(valores *tabuleiro, valores jogada);
bool temVazios(valores tabuleiro[]);
valores *copiarVetor(valores *original, size_t tamanho);

#endif
