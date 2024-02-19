#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct Node
{
    char data;
    struct Node *link;
};
struct Node *top = NULL;
void Push(char x)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = x;
    temp->link = top;
    top = temp;
}
void Pop()
{
    struct Node *temp;
    if (top == NULL)
    {
        return;
    }
    temp = top;
    top = top->link;
    free(temp);
}
void Print()
{
    struct Node *temp = top;
    while (temp != NULL)
    {
        printf("%c", temp->data);
        temp = temp->link;
    }
}
int main()
{
    int n;
    char x;
    printf("Enter the length of the string\n");
    scanf("%d", &n);
    printf("Enter a string\n");
    for (int i = 0; i < n + 1; i++)
    {
        scanf("%c", &x);
        Push(x);
    }
    Print();
    return 0;
}