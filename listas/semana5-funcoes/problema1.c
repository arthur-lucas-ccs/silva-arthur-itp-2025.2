#include <stdio.h>

void ajustarHorario(int *hora, int *minuto)
{
    *hora += *minuto / 60;
    *minuto %= 60;
    *hora %= 24;
}

void imprimirHorario(int hora, int minuto, int formato)
{
    ajustarHorario(&hora, &minuto);

    if (formato == 0)
    { // 24h
        printf("%02d:%02d\n", hora, minuto);
    }
    else
    { // 12h
        int hora12 = hora % 12;
        if (hora12 == 0)
            hora12 = 12;
        printf("%02d:%02d %s\n", hora12, minuto, hora < 12 ? "AM" : "PM");
    }
}

int main()
{
    int hora, minuto, formato;
    scanf("%d %d %d", &hora, &minuto, &formato);

    // Intervalos de tempo
    int intervalosH[] = {0, 1, 2, 4, 12};
    int intervalosM[] = {0, 0, 10, 40, 5};

    for (int i = 0; i < 5; i++)
    {
        int novaHora = hora + intervalosH[i];
        int novoMinuto = minuto + intervalosM[i];
        imprimirHorario(novaHora, novoMinuto, formato);
    }

    return 0;
}
