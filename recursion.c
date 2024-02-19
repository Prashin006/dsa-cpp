#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int Print(int);
int main()
{
    int n;
    Print(1);
    return 420;
}

int Print(int n)
{
    if (n == 5)
    {
        printf("%d", 5);
        return 1;
    }
    printf("%d\n", n);
    Print(n + 1);

    return 0;
}