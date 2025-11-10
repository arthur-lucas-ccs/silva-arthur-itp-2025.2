#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <windows.h>

void printr(char name[])
{
    for (int i = 0; i < strlen(name); i++)
    {
        printf("%c", name[i]);
        Sleep(70);
    }
}

int main()
{
    char nome[] = "arthur";
    printr(nome);
}
