#include <stdio.h>
#include <math.h>

float altura(float x, float y)
{
    return sin(cos(y) + x) + cos(y + sin(x));
}

int pontoSeguro(float x, float y)
{
    float dx[] = {0, 0.2, -0.2, 0.2, -0.2};
    float dy[] = {0, 0.2, -0.2, -0.2, 0.2};

    for (int i = 0; i < 5; i++)
    {
        float h = altura(x + dx[i], y + dy[i]);
        if (h < 0 || h > 2)
            return 0;
    }
    return 1;
}

int main()
{
    float x, y;
    scanf("%f %f", &x, &y);

    if (!pontoSeguro(x, y))
    {
        printf("troque de coordenada\n");
        return 0;
    }

    int seguros = 0;
    float vizinhos[4][2] = {
        {x + 2, y},
        {x - 2, y},
        {x, y + 2},
        {x, y - 2}};

    for (int i = 0; i < 4; i++)
    {
        if (pontoSeguro(vizinhos[i][0], vizinhos[i][1]))
            seguros++;
    }

    if (seguros <= 1)
        printf("inseguro\n");
    else if (seguros <= 3)
        printf("relativamente seguro\n");
    else
        printf("seguro\n");

    return 0;
}
