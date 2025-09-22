#include <stdio.h>

int main()
{
    float comprimento, largura, bolso;
    int dobras = 0;

    printf("Digite o comprimento da folha: ");
    scanf("%f", &comprimento);
    printf("Digite a largura da folha: ");
    scanf("%f", &largura);
    printf("Digite o comprimento do bolso: ");
    scanf("%f", &bolso);

    // Enquanto ambos os lados forem maiores ou iguais ao bolso, continue dobrando
    while (comprimento >= bolso && largura >= bolso)
    {
        if (comprimento > largura)
        {
            comprimento /= 2;
        }
        else
        {
            largura /= 2;
        }
        dobras++;
    }

    printf("Dobras necessarias: %d\n", dobras);

    return 0;
}