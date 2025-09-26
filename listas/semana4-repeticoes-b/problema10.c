#include <stdio.h>

int main()
{
    float p, q;
    int x, y;
    int melhor_x = 0, melhor_y = 0;
    float melhor_razao = 0;

    // Leitura dos dados
    printf("Digite o preco de venda p: ");
    scanf("%f", &p);

    printf("Digite o preco de producao q: ");
    scanf("%f", &q);

    // Testar todas as combinações possíveis de x e y
    for (x = 1; x <= 10; x++)
    { // Leve x unidades
        for (y = 1; y < x; y++)
        { // Pague y unidades (y < x)
            // Verificar se não há prejuízo: custo total <= receita total
            float custo_total = x * q;   // Custo para produzir x unidades
            float receita_total = y * p; // Receita por vender y unidades

            if (receita_total >= custo_total)
            {
                float razao = (float)x / y;

                // Se encontrou uma razão maior
                if (razao > melhor_razao)
                {
                    melhor_razao = razao;
                    melhor_x = x;
                    melhor_y = y;
                }
            }
        }
    }

    // Mostrar o resultado
    if (melhor_razao > 0)
    {
        printf("A melhor promocao eh: leve %d pague %d\n", melhor_x, melhor_y);
    }
    else
    {
        printf("Nenhuma promocao sem prejuizo foi encontrada.\n");
    }

    return 0;
}