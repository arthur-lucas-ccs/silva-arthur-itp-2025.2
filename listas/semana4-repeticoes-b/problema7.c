#include <stdio.h>
int main()
{
    int a, b;
    do
    {
        printf("Digite A: \n");
        scanf("%d", &a);

        printf("Digite B: \n");
        scanf("%d", &b);
    } while (a < b);

    for (int i = a; i > b; i--)
    {
        int div_count = 0;
        for (int j = 1; j <= i; j++)
        {
            if (i % j == 0)
            {
                div_count++;
            } // dois divisores sairem do for
            if (div_count > 2)
            {
                j = i + 1; // encerra o for pois não é um primo.
            }
        }
        if (div_count == 2)
        {
            printf("esse numero eh primo: %d\n", i);
        }
    }
}