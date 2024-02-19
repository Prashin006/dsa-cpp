// Program to insert and print elements at the begining of the linked list
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *head;
void Insert(int x);
void Print();
int main()
{
    head = NULL;
    int n, i, x;
    printf("How many numbers you want to add?\n");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter the number ");
        scanf("%d", &x);
        Insert(x);
        Print();
    }

    return 0;
}
void Insert(int x)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->next = head;
    head = temp;
    temp->data = x;
}
void Print()
{
    struct Node *temp = head;
    printf("The list is :");
    while (temp != NULL)
    {
        printf(" %d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}