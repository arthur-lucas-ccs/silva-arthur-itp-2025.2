#include <stdio.h>
#include <math.h>

int main()
{
    float x, y, teia_max, ax, ay, distancia;
    int n, i;
    int consegue = 1; // 1 para sim, 0 para não

    printf("Digite a coordenada inicial do homem aranha (x y): ");
    scanf("%f %f", &x, &y);
    printf("Digite o comprimento maximo da teia: ");
    scanf("%f", &teia_max);
    printf("Digite o numero de alvos: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Digite a coordenada do alvo %d (x y): ", i + 1);
        scanf("%f %f", &ax, &ay);

        // Calcula distância euclidiana
        distancia = sqrt(pow(x - ax, 2) + pow(y - ay, 2));

        if (distancia <= teia_max)
        {
            // Atualiza posição do homem aranha
            x = 2 * ax - x;
            y = ay; // Pela descrição, apenas x muda, y permanece o mesmo?
        }
        else
        {
            consegue = 0;
            break;
        }
    }

    if (consegue)
    {
        printf("S\n");
    }
    else
    {
        printf("N\n");
    }

    return 0;
}