#include <stdio.h>

int main()
{
    // definição de variaveis
    float celsius, fahrenheit, kelvin;

    // entrada
    printf("Digite a temperatura em Celsius: ");
    scanf("%f", &celsius);

    // processamento
    fahrenheit = (celsius * 9 / 5) + 32;
    kelvin = celsius + 273.15;

    // saida
    printf("Temperatura em Fahrenheit: %.1f\n", fahrenheit);
    printf("Temperatura em Kelvin: %.1f\n", kelvin);

    return 0;
}