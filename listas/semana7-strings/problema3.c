#include <stdio.h>
#include <string.h>

int main()
{
    char aluno[11], registro[1001];
    scanf("%s", aluno);
    getchar();
    fgets(registro, 1001, stdin);

    int ausente = 0;
    char *token = strtok(registro, " \n");
    while (token != NULL)
    {
        if (token[2] == '/')
        {
            int presente = 0;
            token = strtok(NULL, " \n");
            while (token != NULL && token[2] != '/')
            {
                if (strcmp(token, aluno) == 0)
                    presente = 1;
                token = strtok(NULL, " \n");
            }
            if (!presente)
                ausente++;
        }
        else
        {
            token = strtok(NULL, " \n");
        }
    }

    printf("%d\n", ausente);
    return 0;
}
