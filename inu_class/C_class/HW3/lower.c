#include <stdio.h>
#include <string.h>

int main()
{
    char lower[100] = "HELLOworlD";
    for (int i = 0; i < strlen(lower); i++)
    {
        if (lower[i] >= 'A' && lower[i] <= 'Z')
            lower[i] += 32;
    }
    for (int i = 0; i < strlen(lower); i++)
        printf("%c", lower[i]);
}