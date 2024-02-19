#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char temp;
    char c[51];
    char *i = c;
    char *j = &c[strlen(c) - 1];
    printf("Enter a string\n");
    gets(c);
    printf("%d\n", strlen(c));
    printf("%c", *j);
    printf("%c", *i);
    while (i <= j)
    {
        temp = *j;
        *j = *i;
        *i = temp;
        i++;
        j--;
    }
    // printf("The reversed string is\n");
    // printf("%s", c);
    return 0;
}