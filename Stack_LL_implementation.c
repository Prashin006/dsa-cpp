#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct Node
{
    int data;
    struct Node *link;
};
struct Node *top = NULL;
void Push(int x)
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
        printf("%d ", temp->data);
        temp = temp->link;
    }
}
int main()
{
    Push(2);
    Push(67);
    Push(5);
    Pop();
    Push(4);
    Print();
    return 0;
}