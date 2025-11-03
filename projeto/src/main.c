// inclusão das bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

// Estrutura de dados que corresponde a todos os valores possiveis dentro de um tabuleiro de jogo da velha.
typedef enum
{
    VALOR_NULO = -1,
    JOGADOR_O = 0,
    JOGADOR_X = 1
} valores;

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

// cria um novo tabuleiro, e faz uma jogada
valores *jogada(valores *original, int posicao, valores jogador, size_t tamanho)
{
    valores *novoTabuleiro = copiarVetor(original, tamanho);
    setPosicao(novoTabuleiro, posicao, jogador);
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
    if (verificaGanho(tabuleiro, jogador) == 1 && jogador == eu)
    {
        printf("\npossivel ganho\n");
        return 1;
    }
    else if (verificaGanho(tabuleiro, jogador) == 1 && jogador != eu)
    {
        printf("\npossivel perca\n");
        return -1;
    }
    else if (temVazios(tabuleiro) == false)
    {
        printf("\npossivel empate\n");
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
            if (jogadas[i] == 1)
            {
                // percorremos as possiveis jogadas, aplicando o minimax nos tabuleiros resultantes
                valores *resultado = jogada(tabuleiro, i, eu, tamanho);
                valor = minimax(resultado, (eu == JOGADOR_X) ? JOGADOR_O : JOGADOR_X, eu);
                free(resultado);
                if (valor > maior) // o valor do minimax é a melhor posição
                {
                    maior = valor;
                    printf("esse eh o maior da jogada i: %d\n e esse eh o valor: %d\n", i, valor);
                }
            }
        }
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
                valor = minimax(resultado, eu, (eu == JOGADOR_X) ? JOGADOR_O : JOGADOR_X);
                free(resultado);
                if (valor < menor)
                {
                    menor = valor;
                    printf("esse eh o menor valor da jogada i: %d\n e esse eh o valor: %d\n", i, valor);
                }
            }
        }
        return menor;
    }
}

// função que aplica minimax, buscando as melhores jogadas de acordo com o tabuleiro, retornando a jogada onde acha a melhor posição.
int melhorJogada(valores *tabuleiro, valores eu)
{
    size_t tamanho = 9;
    bool *jogadas = possiveisJogadas(tabuleiro, tamanho);
    int maiorJogada = 1000000;
    int melhor = 0;
    int melhorValor;
    for (size_t j = 0; j < tamanho; j++)
    {
        if (jogadas[j] == 1)
        {
            valores *resultado = jogada(tabuleiro, j, eu, tamanho);
            melhorValor = minimax(resultado, (eu == JOGADOR_X) ? JOGADOR_O : JOGADOR_X, (eu == JOGADOR_X) ? JOGADOR_O : JOGADOR_X);
            if (melhorValor < maiorJogada)
            {
                melhor = j;
                maiorJogada = melhorValor;
            }
        }
    }
    return melhor;
}

int main()
{
    // cria um novo tabuleiro de tamanho 9
    size_t posicoes = 9;
    valores *tabuleiro = criarVetorBase(posicoes);

    // o usuario escolhe quem quer ser e com base nisso definimos o valor da IA.
    int posicao;
    char resposta;
    printf("Se Voce quer ser X, digite: 'x', se quiser jogar com O, digite: 'o'.\n");
    scanf(" %c", &resposta);
    valores eu = (resposta == 'x') ? JOGADOR_X : JOGADOR_O;
    valores ia = (eu == JOGADOR_X) ? JOGADOR_O : JOGADOR_X;

    // Jogo, onde o usuario escolhe a posição onde quer jogar e a ia responde por meio da aplicação da melhor jogada
    while ((verificaGanho(tabuleiro, eu)) != 1 && (verificaGanho(tabuleiro, (eu == JOGADOR_X) ? JOGADOR_O : JOGADOR_X) != 1) && (temVazios(tabuleiro) == true))
    {
        printf("\n0 Para ver a posicao, e 1 para fazer uma jogada\n");
        scanf(" %c", &resposta);
        if (resposta == '0')
        {
            getTabuleiro(tabuleiro);
        }
        else if (resposta == '1')
        {
            bool validacao;
            do
            {
                printf("Digite a posicao de 1 a 9: \n");
                scanf("%d", &posicao);
                validacao = setPosicao(tabuleiro, posicao - 1, eu);
                if (validacao == false)
                {
                    printf("Espaco ocupado ou invalido.\n");
                }
                if (verificaGanho(tabuleiro, eu) != 1)
                {
                    validacao = setPosicao(tabuleiro, melhorJogada(tabuleiro, ia), ia);
                }
            } while (validacao != true);
        }
    }

    // mostra dos resultados.
    printf("Acabou e esse foi o tabuleiro");
    getTabuleiro(tabuleiro);
    if (verificaGanho(tabuleiro, eu))
    {
        printf(">>>>>>>>Voce ganhou!<<<<<<<<");
    }
    else if (verificaGanho(tabuleiro, ia))
    {
        printf(">>>>>>>>IA ganhou!<<<<<<<<");
    }
    else if (temVazios(tabuleiro) == false)
    {
        printf(">>>>>>>>deu velha!<<<<<<<<");
    }

    // encerra a função main.
    return 0;
}