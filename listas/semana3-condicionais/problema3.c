#include <stdio.h>

int main()
{
    float nota1, nota2, nota3, media, notaFinal;

    printf("Digite a primeira nota: ");
    scanf("%f", &nota1);

    printf("Digite a segunda nota: ");
    scanf("%f", &nota2);

    printf("Digite a terceira nota: ");
    scanf("%f", &nota3);

    media = (nota1 + nota2 + nota3) / 3;

    printf("Média: %.2f - ", media);

    if (media >= 7.0)
    {
        printf("Aprovado!\n");
    }
    else if (media < 4.0)
    {
        printf("Reprovado!\n");
    }
    else
    {
        printf("Recuperação!\n");
        notaFinal = 10 - media; // Para média final = (media + notaFinal)/2 >= 5
        printf("Você precisa de %.2f na prova final para ser aprovado\n", notaFinal);
    }

    return 0;
}