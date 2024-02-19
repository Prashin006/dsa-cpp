#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_SIZE 101
int A[MAX_SIZE];
int top = -1;
void Push(int x)
{
    if (top == MAX_SIZE - 1)
    {
        printf("Error: stack overflow\n");
        return;
    }
    A[++top] = x;
}
void Pop()
{
    if (top == -1)
    {
        printf("Error: No element to pop\n");
        return;
    }
    top--;
}
bool IsEmpty()
{
    if (top == -1)
    {
        return true;
    }
    else
        return false;
}
int Top()
{
    return A[top];
}
void Print() // Print function is not a typical operation available with stack this is only used to verify my stack operations
{
    if (top == -1)
    {
        return;
    }
    for (int i = 0; i <= top; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}
int main()
{
    int n, x, p;
    Push(2);
    Push(4);
    Pop();
    Push(7);
    printf("%d\n", Top());
    Push(34);
    Push(43);
    Pop();
    Push(71);
    // printf("How many elements you want in the stack?\n");
    // scanf("%d", &n);
    // for (int i = 0; i < n; i++)
    // {
    //     printf("Enter the number: ");
    //     scanf("%d", &x);
    //     Push(x);
    // }

    Print();
    return 0;
}