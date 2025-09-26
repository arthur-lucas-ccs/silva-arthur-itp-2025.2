#include <stdio.h>

int main()
{
    float preco1, preco2, quantia;
    int i, j;

    // Leitura dos dados
    printf("Digite o preco do primeiro fornecedor: ");
    scanf("%f", &preco1);

    printf("Digite o preco do segundo fornecedor: ");
    scanf("%f", &preco2);

    printf("Digite a quantia disponivel: ");
    scanf("%f", &quantia);

    // Testar todas as combinações possíveis
    for (i = 0; i <= 10; i++)
    { // Quantidade do primeiro fornecedor (0 a 10)
        for (j = 0; j <= 10; j++)
        { // Quantidade do segundo fornecedor (0 a 10)
            float custo_total = (i * preco1) + (j * preco2);
            float resto = quantia - custo_total;

            // Verificar se a compra é possível (não pode ficar negativo)
            if (resto >= 0)
            {
                printf("Comprando %d do primeiro e %d do segundo resta: %.2f\n", i, j, resto);
            }
        }
    }

    return 0;
}