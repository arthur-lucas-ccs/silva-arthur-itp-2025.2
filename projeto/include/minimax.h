#ifndef MINIMAX_H
#define MINIMAX_H

#include "manipulacaoTabuleiro.h"

valores *jogada(valores *original, int posicao, valores jogador, size_t tamanho);
bool *possiveisJogadas(valores *original, size_t tamanho);
int minimax(valores *tabuleiro, valores jogador, valores eu);
int melhorJogada(valores *tabuleiro, valores eu);

#endif