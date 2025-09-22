#include <stdio.h>
#include <math.h>

// Função para calcular pontuação baseada na distância
int calcular_pontuacao(float distancia)
{
    if (distancia <= 1.0)
        return 10;
    else if (distancia <= 2.0)
        return 6;
    else if (distancia <= 3.0)
        return 4;
    else
        return 0;
}

// Função para calcular pontuação bônus
int calcular_bonus(float distancia)
{
    if (distancia <= 1.0)
        return 5;
    else if (distancia <= 2.0)
        return 3;
    else if (distancia <= 3.0)
        return 2;
    else
        return 0;
}

int main()
{
    float x, y, x_anterior, y_anterior;
    float dist_centro, dist_anterior;
    int pontuacao_total = 0;

    printf("Digite as coordenadas dos 10 lancamentos:\n");

    // Primeiro lançamento (sem bônus)
    printf("Lancamento 1 (x y): ");
    scanf("%f %f", &x, &y);
    dist_centro = sqrt(x * x + y * y);
    pontuacao_total += calcular_pontuacao(dist_centro);
    x_anterior = x;
    y_anterior = y;

    // Próximos 9 lançamentos (com bônus)
    for (int i = 2; i <= 10; i++)
    {
        printf("Lancamento %d (x y): ", i);
        scanf("%f %f", &x, &y);

        // Distância ao centro (pontuação principal)
        dist_centro = sqrt(x * x + y * y);
        pontuacao_total += calcular_pontuacao(dist_centro);

        // Distância ao lançamento anterior (pontuação bônus)
        dist_anterior = sqrt(pow(x - x_anterior, 2) + pow(y - y_anterior, 2));
        pontuacao_total += calcular_bonus(dist_anterior);

        x_anterior = x;
        y_anterior = y;
    }

    printf("Pontuacao total: %d\n", pontuacao_total);

    return 0;
}