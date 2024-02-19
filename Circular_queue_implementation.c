#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10
int A[MAX];
int front = -1, rear = -1;
void Enqueue(int);
int Dequeue();

int main()
{
    int val, option;
    do
    {
        printf("\n\n*****MAIN MENU*****\n\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        switch (option)
        {
        case 1:
            printf("Enter the number\n");
            scanf("%d", &val);
            Enqueue(val);
            break;
        case 2:
            Dequeue();
            break;
        }
    } while (option != 3);

    return 0;
}
void Enqueue(int x)
{
}