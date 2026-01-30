// inclusão das bibliotecas
#include "manipulacaoTabuleiro.h"
#include "minimax.h"

int main()
{
    // cria um novo tabuleiro de tamanho 9
    size_t posicoes = 9;
    valores *tabuleiro = criarVetorBase(posicoes);

    // o usuario escolhe quem quer ser e com base nisso definimos o valor da IA.
    int posicao;
    char resposta;
    int historico[3][9];
    int turno = 1;
    print("Se Voce quer ser X, digite: 'x', se quiser jogar com O, digite: 'o'.");
    scanf(" %c", &resposta);
    valores eu = (resposta == 'x') ? JOGADOR_X : JOGADOR_O;
    valores ia = (eu == JOGADOR_X) ? JOGADOR_O : JOGADOR_X;

    // Jogo, onde o usuario escolhe a posição onde quer jogar e a ia responde por meio da aplicação da melhor jogada
    while ((verificaGanho(tabuleiro, eu)) != 1 && (verificaGanho(tabuleiro, (eu == JOGADOR_X) ? JOGADOR_O : JOGADOR_X) != 1) && (temVazios(tabuleiro) == true))
    {
        print("0 Para ver a posicao, e 1 para fazer uma jogada");
        scanf(" %c", &resposta);
        if (resposta == '0')
        {
            getTabuleiro(tabuleiro);
        }
        else if (resposta == '1')
        {
            bool validacao;
            print("Digite a posicao de 1 a 9: ");
            scanf("%d", &posicao);
            validacao = setPosicao(historico, tabuleiro, posicao - 1, eu, turno);
            turno++;
            while (validacao == false && temVazios(tabuleiro) == true)
            {
                print("Espaco ocupado ou invalido.");
                print("Digite a posicao de 1 a 9: ");
                scanf("%d", &posicao);
                validacao = setPosicao(historico, tabuleiro, posicao - 1, eu, turno);
                turno++;
            }
            if (temVazios(tabuleiro) == true)
            {
                setPosicao(historico, tabuleiro, melhorJogada(tabuleiro, ia), ia, turno);
                turno++;
            }
        }
    }

    // mostra dos resultados.
    if (verificaGanho(tabuleiro, eu))
    {
        print(">>>>>>>>Voce ganhou!<<<<<<<<");
    }
    else if (verificaGanho(tabuleiro, ia))
    {
        print(">>>>>>>>IA ganhou!<<<<<<<<");
    }
    else if (temVazios(tabuleiro) == false)
    {
        print(">>>>>>>>deu velha!<<<<<<<<");
    }

    print("Acabou e esse foi o tabuleiro");
    getHistorico(historico);
    getTabuleiro(tabuleiro);

    free(tabuleiro);

    // encerra a função main.
    return 0;
}