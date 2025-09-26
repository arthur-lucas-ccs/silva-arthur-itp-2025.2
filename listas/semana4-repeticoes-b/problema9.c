#include <stdio.h>

int main()
{
    float preco1, preco2, quantia;
    int i, j;
    int melhor_i = 0, melhor_j = 0;
    float menor_resto = -1;

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
                // Se é a primeira combinação válida ou se encontrou um resto menor
                if (menor_resto == -1 || resto < menor_resto)
                {
                    menor_resto = resto;
                    melhor_i = i;
                    melhor_j = j;
                }
            }
        }
    }

    // Mostrar o resultado
    if (menor_resto == -1)
    {
        printf("Nao eh possivel comprar nenhuma combinacao com a quantia disponivel.\n");
    }
    else
    {
        printf("Resta menos comprando %d do primeiro e %d do segundo\n", melhor_i, melhor_j);
    }

    return 0;
}