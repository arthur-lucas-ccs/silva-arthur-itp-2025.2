#include <stdio.h>
#include <math.h>

int main()
{
    int a, b, c;

    for (a = 0; a < 1000; a++)
    {
        for (b = 0; b <= a; b++)
        {
            c = sqrt((a * a) + (b * b));

            if ((a * a + b * b == c * c) && c < 1000 && a != 0 && b != 0)
            {
                printf("a: %d\n", a);
                printf("b: %d\n", b);
                printf("c: %d\n", c);
                printf("----\n");
            }
        }
    }
    printf("\n");
}
