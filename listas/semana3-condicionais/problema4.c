#include <stdio.h>

int main()
{
    // definição e entrada
    char jogador1, jogador2;

    printf("Jogador 1 - Digite P (pedra), A (papel) ou T (tesoura): ");
    scanf(" %c", &jogador1);

    printf("Jogador 2 - Digite P (pedra), A (papel) ou T (tesoura): ");
    scanf(" %c", &jogador2);

    // processamento dos dados e saida
    if (jogador1 == jogador2)
    {
        printf("Empate!\n");
    }
    else if ((jogador1 == 'P' && jogador2 == 'T') ||
             (jogador1 == 'T' && jogador2 == 'A') ||
             (jogador1 == 'A' && jogador2 == 'P'))
    {
        printf("Jogador 1 venceu!\n");
    }
    else if ((jogador2 == 'P' && jogador1 == 'T') ||
             (jogador2 == 'T' && jogador1 == 'A') ||
             (jogador2 == 'A' && jogador1 == 'P'))
    {
        printf("Jogador 2 venceu!\n");
    }
    else
    {
        printf("Jogada inválida!\n");
    }

    return 0;
}