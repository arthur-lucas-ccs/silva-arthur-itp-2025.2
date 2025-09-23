#include <stdio.h>

int main()
{
    // definição e entrada
    float valorCompra, desconto, valorFinal;
    int porcentagem;

    printf("Digite o valor da compra: R$ ");
    scanf("%f", &valorCompra);

    // classificação de acordo com o valor da venda
    if (valorCompra <= 100.00)
    {
        porcentagem = 0;
    }
    else if (valorCompra <= 500.00)
    {
        porcentagem = 10;
    }
    else if (valorCompra <= 1000.00)
    {
        porcentagem = 15;
    }
    else
    {
        porcentagem = 20;
    }

    // processamento das dados
    desconto = valorCompra * porcentagem / 100;
    valorFinal = valorCompra - desconto;

    // saida
    printf("Valor da compra: R$ %.2f\n", valorCompra);
    printf("Desconto aplicado: %d%%\n", porcentagem);
    printf("Valor do desconto: R$ %.2f\n", desconto);
    printf("Valor final: R$ %.2f\n", valorFinal);

    return 0;
}