#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *misturar(char *str1, char *str2)
{
    int len1 = strlen(str1), len2 = strlen(str2);
    char *nova = (char *)malloc(len1 + len2 + 1);
    int i, j = 0;
    for (i = 0; i < len1 && i < len2; i++)
    {
        nova[j++] = str1[i];
        nova[j++] = str2[i];
    }
    while (i < len1)
        nova[j++] = str1[i++];
    while (i < len2)
        nova[j++] = str2[i++];
    nova[j] = '\0';
    return nova;
}

int main()
{
    char str1[101], str2[101];
    fgets(str1, 101, stdin);
    fgets(str2, 101, stdin);
    str1[strcspn(str1, "\n")] = 0;
    str2[strcspn(str2, "\n")] = 0;
    char *res = misturar(str1, str2);
    printf("%s\n", res);
    free(res);
    return 0;
}
